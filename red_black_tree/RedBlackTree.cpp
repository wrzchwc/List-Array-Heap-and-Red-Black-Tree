//
// Created by kubaw on 19.04.2021.
//
#include <iostream>
#include "Node.h"
#include "RedBlackTree.h"

using namespace std;


RedBlackTree::RedBlackTree() {
    size = 0;
    root = nullptr;
}

RedBlackTree::~RedBlackTree() {
    //todo:invoke removeAll or something like this here idk
}

void RedBlackTree::add(int data, Node *sub_root) {
    size++;
    Node *new_node;
    //tree is empty, added node will be the root of the tree
    if (size == 1 && root == nullptr) {
        new_node = new Node(data, 'B');
        root = new_node;
    } else {
        new_node = new Node(data);
        Node *tmp = root;
        Node *tmpParent = tmp->getParent();

        while (tmp != nullptr) {
            tmpParent = tmp;
            if (data < tmp->getData())
                tmp = tmp->getLeftChild();
            else
                tmp = tmp->getRightChild();
        }
        new_node->setParent(tmpParent);
        if (data < tmpParent->getData())
            tmpParent->setLeftChild(new_node);
        else
            tmpParent->setRightChild(new_node);
        verifyAfterAddition(new_node, tmpParent);
    }
}


void RedBlackTree::show(Node *node) {
    Node *tmp = node;
    if (tmp == nullptr)
        return;
    cout << "(" << tmp->getParent() << " " << tmp << " " << tmp->getData() << " " << tmp->getColor() << ")" << endl;
    show(tmp->getLeftChild());
    show(tmp->getRightChild());
}

Node *RedBlackTree::getRoot() {
    return root;
}

bool RedBlackTree::contains(int data, Node *node) {
    Node *tmp = root;
    while (tmp != nullptr) {
        if (tmp->getData() == data)
            return true;
        else if (data < tmp->getData())
            tmp = tmp->getLeftChild();
        else
            tmp = tmp->getRightChild();
    }
    return false;
}

void RedBlackTree::rotate(Node *a, Node *b, bool left) {
    //rotation
    b->setParent(a->getParent());
    //if a is not a root it surely has a parent
    if (a != root && a == a->getParent()->getRightChild())
        a->getParent()->setRightChild(b);
    else if (a != root)
        a->getParent()->setLeftChild(b);
    else
        root = b;
    a->setParent(b);

    //left rotation
    if (left) {
        if(b->getLeftChild()!= nullptr)
            b->getLeftChild()->setParent(a);
        a->setRightChild(b->getLeftChild());
        b->setLeftChild(a);
    }
        //right rotation
    else {
        if(b->getRightChild()!= nullptr)
            b->getRightChild()->setParent(a);
        a->setLeftChild(b->getRightChild());
        b->setRightChild(a);
    }
}

void RedBlackTree::verifyAfterAddition(Node *child, Node *parent) {
    //conflict occurs only if parent and its child are red
    if(child->getColor()&&parent->getColor()=='R'){
        Node *grandparent = parent->getParent();
        Node *uncle = parent->getSibling(grandparent, parent);

        //check color of the uncle
        if (!uncle || uncle->getColor() == 'B') {
            grandparent->invertColor();
            if (child == parent->getRightChild() && parent == grandparent->getLeftChild()) {
                child->invertColor();
                rotate(parent, child);
                rotate(grandparent, child, false);
            } else if (child == parent->getLeftChild() && parent == grandparent->getRightChild()) {
                child->invertColor();
                rotate(parent, child, false);
                rotate(grandparent, child);
            } else if (child == parent->getRightChild() && grandparent->getRightChild()) {
                parent->invertColor();
                rotate(grandparent, parent);
            } else {
                parent->invertColor();
                rotate(grandparent, parent, false);
            }
        } else {
            parent->invertColor();
            uncle->invertColor();
            if (grandparent != root) {
                grandparent->invertColor();
                verifyAfterAddition(grandparent, grandparent->getParent());
            }
        }
    }
}


