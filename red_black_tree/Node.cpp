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

void Node::changeColor() {
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
    return left_child;
}

void Node::setLeftChild(Node *leftChild) {
    left_child = leftChild;
}

Node *Node::getRightChild() const {
    return right_child;
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
