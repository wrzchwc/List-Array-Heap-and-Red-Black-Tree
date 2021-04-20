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
    if (size == 1 && sub_root == nullptr) {
        new_node = new Node(data, 'B');
        root = new_node;
    } else {
        new_node = new Node(data);
        Node *tmp = sub_root;
        if (new_node->getData() < tmp->getData()) {
            if (tmp->getLeftChild() == nullptr) {
                tmp->setLeftChild(new_node);
                new_node->setParent(tmp);
                return;
            } else
                add(data, tmp->getLeftChild());
        } else {
            if (tmp->getRightChild() == nullptr) {
                tmp->setRightChild(new_node);
                new_node->setParent(tmp);
                return;
            } else
                add(data, tmp->getRightChild());
        }
    }

}

void RedBlackTree::show(Node *node) {
    Node *tmp = node;
    Node *tmpParent = nullptr;
    if (tmp == nullptr)
        return;
    show(tmp->getLeftChild());
    cout<<"("<<tmp->getParent()<<" "<<tmp<<" "<<tmp->getData() << " " << tmp->getColor()<<")"<<endl;
    show(tmp->getRightChild());
}

Node *RedBlackTree::getRoot() const {
    return root;
}

bool RedBlackTree::contains(int data) {
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


