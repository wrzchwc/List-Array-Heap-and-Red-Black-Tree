//
// Created by kubaw on 19.04.2021.
//

#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H


class Node {
private:
    //parent of the node
    Node *parent;
    //left child of the node
    Node *left_child;
    //right child of the node
    Node *right_child;
    //color of the node
    char color;
    //data stored in the node
    int data;

    //sets the color of the node
    void setColor(char color);

public:
    //constructor
    explicit Node(int data, char color = 'R');

    //destructor
    virtual ~Node();

    //changes the color of the node
    void invertColor();

    //returns the parent of the node
    [[nodiscard]] Node *getParent() const;

    //sets the parent of the node
    void setParent(Node *parent);

    //returns the left child of the node
    [[nodiscard]] Node *getLeftChild() const;

    //sets the left child of the node
    void setLeftChild(Node *leftChild);

    //returns the right child of the node
    [[nodiscard]] Node *getRightChild() const;

    //sets the right child of the node
    void setRightChild(Node *rightChild);

    //returns the color of the node
    [[nodiscard]] char getColor() const;

    //returns data stored in the node
    [[nodiscard]] int getData() const;

    //returns parent node's sibling
    Node *getSibling(Node *parent, Node *child);

};


#endif //UNTITLED1_NODE_H
