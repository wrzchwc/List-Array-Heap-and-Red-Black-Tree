//
// Created by kubaw on 19.04.2021.
//

#include "Node.h"

Node::Node(int data, char color) : color(color) {
    parent = nullptr;
    left_child = nullptr;
    right_child = nullptr;
    this->color = color;
    this->data = data;
}

Node::~Node() {
    parent = nullptr;
    left_child = nullptr;
    right_child = nullptr;
}

void Node::invertColor() {
    if (color == 'R')
        setColor('B');
    else
        setColor('R');
}

void Node::setColor(char color) {
    this->color = color;
}

Node *Node::getParent() const {
    return parent;
}

void Node::setParent(Node *parent) {
    Node::parent = parent;
}

Node *Node::getLeftChild() const {
    if (left_child != nullptr)
        return left_child;
    else
        return nullptr;
}

void Node::setLeftChild(Node *leftChild) {
    left_child = leftChild;
}

Node *Node::getRightChild() const {
    if (right_child != nullptr)
        return right_child;
    else
        return nullptr;
}

void Node::setRightChild(Node *rightChild) {
    right_child = rightChild;
}

char Node::getColor() const {
    return color;
}

int Node::getData() const {
    return data;
}

Node *Node::getSibling(Node *parent, Node *child) {
    if (parent != nullptr) {
        if (child->getData() < parent->getData())
            return parent->getRightChild();
        else
            return parent->getLeftChild();
    } else
        return nullptr;
}

void Node::setData(int data) {
    Node::data = data;
}

Node::Node(Node *node) {
    data = node->getData();
    color = node->getColor();
    left_child = node->getLeftChild();
    right_child = node->getRightChild();
    parent = node->getParent();
}
