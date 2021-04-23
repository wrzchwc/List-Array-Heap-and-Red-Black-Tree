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

void RedBlackTree::add(int data) {
    size++;
    Node *new_node;
    //tree is empty, added node will be the root of the tree
    if (size == 1 || root == nullptr) {
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
    int option;
    if (contains(data)) {
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
        //sibling of x
        Node *w;
        if (leftOrphan == nullptr && rightOrphan == nullptr) {
            if (deleted->getParent() != nullptr) {
                if (deleted->getData() < deleted->getParent()->getData())
                    deleted->getParent()->setLeftChild(nullptr);
                else
                    deleted->getParent()->setRightChild(nullptr);
            }
            if (deleted->getParent() != nullptr)
                w = deleted->getSibling(deleted->getParent(), deleted);
            delete deleted;
            deleted = nullptr;
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
            Node *replacement = successor(deleted);
            newColor = replacement->getColor();
            deleted->setColor(newColor);
            deleted->setData(replacement->getData());
            x = replacement->getRightChild();
            w = replacement->getSibling(replacement->getParent(), replacement);
            if (replacement == deleted->getRightChild()) {
                deleted->setRightChild(x);
                if (x)
                    x->setParent(deleted);
            } else {
                replacement->getParent()->setLeftChild(x);
                if (x)
                    x->setParent(replacement->getParent());
            }
            delete replacement;
        }

        if (oldColor == 'R' && (newColor == 'R' || newColor == 'N'))
            success = true;
        else if (oldColor == 'B' && newColor == 'R') {
            deleted->setColor('B');
            success = true;
        } else if (oldColor == 'R' && newColor == 'B') {
            deleted->setColor('R');
            option = whichCase(w, newColor);
        } else
            option = whichCase(w, newColor);

        while (!success) {
            //true if node is the left child of its parent, false otherwise
            bool leftSideNode = true;
            if (w->getParent())
                if (w == w->getParent()->getLeftChild())
                    leftSideNode = false;

            switch (option) {
                case 0: {
                    deleted->getRightChild()->setColor('B');
                    success = true;
                }
                    break;
                case 1: {
                    w->setColor('B');
                    w->getParent()->setColor('R');
                    rotate(w->getParent(), w, leftSideNode);
                    if (leftSideNode)
                        w = w->getLeftChild()->getRightChild();
                    else
                        w = w->getRightChild()->getLeftChild();
                    option = whichCase(w, newColor);
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
                        option = whichCase(w, 'B');
                    }
                }
                    break;
                case 3: {
                    w->setColor('R');
                    if (leftSideNode) {
                        w->getLeftChild()->setColor('B');
                        rotate(w, w->getLeftChild(), leftSideNode);
                    } else {
                        w->getRightChild()->setColor('B');
                        rotate(w, w->getRightChild(), !leftSideNode);
                    }
                    w = w->getParent();
                    option = 4;
                }
                    break;
                case 4: {
                    w->setColor(w->getParent()->getColor());
                    w->getParent()->setColor('B');
                    if (leftSideNode)
                        w->getRightChild()->setColor('B');
                    else
                        w->getLeftChild()->setColor('B');
                    rotate(w->getParent(), w, leftSideNode);
                    success = true;
                }
                    break;
                default:
                    cout << "Wystapil blad podczas usuwania!" << endl;
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

Node *RedBlackTree::successor(Node *node) {
    if (node->getRightChild() != nullptr)
        return minData(node->getRightChild());
    Node *tmp = node->getParent();
    while (tmp != nullptr && tmp->getLeftChild() != node) {
        node = tmp;
        tmp = tmp->getParent();
    }
    return tmp;
}

Node *RedBlackTree::minData(Node *node) {
    Node *tmp = node;
    while (tmp->getLeftChild() != nullptr)
        tmp = tmp->getLeftChild();
    return tmp;
}

int RedBlackTree::whichCase(Node *siblingNode, char color) {
    char siblingColor = siblingNode->getColor();
    char leftColor = 'B';   //the color of the sibling node's left child
    char rightColor = 'B';  //the color of the sibling node's right child

    if (siblingNode->getLeftChild())
        leftColor = siblingNode->getLeftChild()->getColor();
    if (siblingNode->getRightChild())
        rightColor = siblingNode->getRightChild()->getColor();

    //true if the node is the left child of its parent, false otherwise
    bool leftSideNode = true;
    if (siblingNode->getParent()->getRightChild() == nullptr)
        leftSideNode = false;

    if (color == 'R')
        return 0;
    else if (color == 'B' && siblingColor == 'R')
        return 1;
    else if (color == 'B' && siblingColor == 'B' && leftColor == 'B' && rightColor == 'B')
        return 2;
    else if (color == 'B' && siblingColor == 'B' &&
             ((leftSideNode && leftColor == 'R' && rightColor == 'B') ||
              (!leftSideNode && leftColor == 'B' && rightColor == 'R'))) {
        return 3;
    } else if (color == 'B' && siblingColor == 'B' &&
               (leftSideNode && rightColor == 'R') || (!leftSideNode && leftColor == 'R')) {
        return 4;
    }
    return 5; //error code
}


