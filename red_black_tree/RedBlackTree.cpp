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
        if (b->getLeftChild() != nullptr)
            b->getLeftChild()->setParent(a);
        a->setRightChild(b->getLeftChild());
        b->setLeftChild(a);
    }
        //right rotation
    else {
        if (b->getRightChild() != nullptr)
            b->getRightChild()->setParent(a);
        a->setLeftChild(b->getRightChild());
        b->setRightChild(a);
    }
}

void RedBlackTree::verifyAfterAddition(Node *child, Node *parent) {
    //conflict occurs only if parent and its child are red
    if (child->getColor() && parent->getColor() == 'R') {
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

void RedBlackTree::remove(int data) {
    bool success = false;
    bool cases = false;
    int option;
    if (contains(data, root)) {
        size--;
        Node *deleted = find(data);
        char oldColor = deleted->getColor();
        int oldData = deleted->getData();
        char newColor;
        //children of the deleted node
        Node *leftOrphan = deleted->getLeftChild();
        Node *rightOrphan = deleted->getRightChild();
        //the replacement of x
        Node *x;
        if (leftOrphan == nullptr && rightOrphan == nullptr) {
            if (deleted->getParent() != nullptr) {
                if (deleted->getData() < deleted->getParent()->getData())
                    deleted->getParent()->setLeftChild(nullptr);
                else
                    deleted->getParent()->setRightChild(nullptr);
            }
            delete deleted;
            newColor = 'N';
        } else if (rightOrphan == nullptr) {
            newColor = leftOrphan->getColor();
            deleted->setColor(newColor);
            deleted->setData(leftOrphan->getData());
            deleted->setLeftChild(nullptr);
            delete leftOrphan;
        } else if (leftOrphan == nullptr) {
            newColor = rightOrphan->getColor();
            deleted->setColor(newColor);
            deleted->setData(rightOrphan->getData());
            deleted->setRightChild(nullptr);
            delete rightOrphan;
        } else {
            x = findSuccessor(deleted);
            newColor = x->getColor();
            deleted->setColor(newColor);
            deleted->setData(x->getData());
            if(x->getData()>=oldData){
                deleted->setRightChild(x->getRightChild());
                x->getRightChild()->setParent(deleted);
            }
            else{
                deleted->setLeftChild(x->getLeftChild());
                x->getLeftChild()->setParent(deleted);
            }
            delete x;
        }

        if (oldColor == 'R' && (newColor == 'R' || newColor == 'N'))
            success = true; // We are done.
        else if (oldColor == 'B' && newColor == 'R') {
            deleted->setColor('B');
            success = true; // We are done
        } else if (oldColor == 'R' && newColor == 'B') {
            deleted->setColor('R');
            cases = true; // We proceed to the appropriate case
        } else if (oldColor == 'B' && (newColor == 'B' || newColor == 'N'))
            cases = true; // We proceed to the appropriate case

        if (cases)
            whichCase(deleted, &option, oldColor);

        while (!success) {
            Node *w = deleted->getSibling(deleted->getParent(), deleted);
            switch (option) {
                case 0: {
                    deleted->getRightChild()->setColor('B');
                    success = true;
                }
                    break;
                case 1: {
                    w->setColor('B');
                    deleted->getParent()->setColor('R');
                    if (deleted == deleted->getParent()->getLeftChild())
                        rotate(deleted->getParent(), w);
                    else if (deleted == deleted->getParent()->getRightChild())
                        rotate(deleted->getParent(), w, false);
                    if (deleted == deleted->getLeftChild()) {
                        w->setParent(deleted->getParent());
                        deleted->getParent()->setLeftChild(w);
                    } else if (deleted == deleted->getRightChild()) {
                        w->setParent(deleted->getParent());
                        deleted->getParent()->setRightChild(w);
                    }
                    whichCase(deleted, &option, newColor);
                }
                    break;
                case 2: {
                    w->setColor('R');
                    deleted = deleted->getParent();
                    if (deleted->getColor() == 'R') {
                        deleted->setColor('B');
                        success = true;
                    } else {
                        newColor = deleted->getColor();
                        whichCase(deleted, &option, newColor);
                    }
                }
                    break;
                case 3: {
                    if (deleted == deleted->getParent()->getLeftChild())
                        w->getLeftChild()->setColor('B');
                    else
                        w->getRightChild()->setColor('B');
                    w->setColor('R');
                    if (deleted == deleted->getParent()->getLeftChild())
                        rotate(deleted->getParent(), deleted, false);
                    else
                        rotate(deleted->getParent(), deleted);
                    if (deleted = deleted->getParent()->getLeftChild())
                        w = deleted->getParent()->getRightChild();
                    else
                        w = deleted->getParent()->getLeftChild();
                    option = 4;
                }
                    break;
                case 4: {
                    w->setColor(deleted->getParent()->getColor());
                    deleted->getParent()->setColor('R');
                    if (deleted == deleted->getLeftChild())
                        w->getLeftChild()->setColor('B');
                    else
                        w->getRightChild()->setColor('R');
                    if (deleted == deleted->getLeftChild())
                        rotate(deleted->getParent(), deleted);
                    else
                        rotate(deleted->getParent(), deleted, false);
                    success = true;
                }
                    break;
            }
        }


    } else
        cout << "W drzewie nie ma wierzcholka zawierajacego wartosc " << data << endl;
}

Node *RedBlackTree::find(int data) {
    Node *tmp = root;
    while (tmp->getData() != data) {
        if (data < tmp->getData())
            tmp = tmp->getLeftChild();
        else
            tmp = tmp->getRightChild();
    }
    if (tmp->getRightChild() != nullptr) {
        if (tmp->getRightChild()->getData() == data)
            return tmp->getRightChild();
    }

    return tmp;
}

Node *RedBlackTree::findSuccessor(Node *node) {
    if (node->getRightChild() != nullptr)
        return findMinData(node->getRightChild());
    Node *tmp = node->getParent();
    while (tmp != nullptr && tmp->getLeftChild() != node) {
        node = tmp;
        tmp = tmp->getParent();
    }
    return tmp;
}

Node *RedBlackTree::findMinData(Node *node) {
    Node *tmp = node;
    while (tmp->getLeftChild() != nullptr)
        tmp = tmp->getLeftChild();
    return tmp;
}

void RedBlackTree::whichCase(Node *node, int *option, char newColor) {
    Node *w = node->getSibling(node->getParent(), node);
    if (newColor == 'R')
        *option = 0;
    else if (newColor == 'B' && w->getColor() == 'R')
        *option = 1;
    else if (node->getColor() && w->getColor() && w->getLeftChild()->getColor() &&
             w->getRightChild()->getColor() == 'B')
        *option = 2;
    else if (newColor && w->getColor() == 'B') {
        //If x is the left child, w's left child is red and w's right child is black
        if ((node->getData() < node->getParent()->getData() && w->getLeftChild()->getColor() == 'R' &&
             w->getRightChild()->getColor() == 'B') || (node->getData() >= node->getParent()->getData() &&
                                                        w->getLeftChild()->getColor() == 'B' &&
                                                        w->getRightChild()->getColor() == 'R'))
            *option = 3;
    } else if (node->getColor() && w->getColor() == 'B') {
        if ((node == node->getParent()->getLeftChild() && w->getRightChild()->getColor() == 'R') ||
            (node == node->getParent()->getRightChild() && w->getLeftChild()->getColor() == 'R'))
            *option = 4;
    }
}


