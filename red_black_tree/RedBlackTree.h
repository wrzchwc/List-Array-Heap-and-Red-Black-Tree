//
// Created by kubaw on 19.04.2021.
//
#include "Node.h"

#ifndef UNTITLED1_REDBLACKTREE_H
#define UNTITLED1_REDBLACKTREE_H

//todo: public void remove(int data)    // omg, kinda scary
//todo: public void removeAll()
class RedBlackTree {
private:
    //size of the red-black tree
    int size;
    //root of the red-black tree
    Node *root;

    //if parameter left is true performs left rotation, otherwise performs right rotation
    void rotate(Node *a, Node *b, bool left = true);

    //checks if all the properties of red-black tree are maintained after addition
    void verifyAfterAddition(Node *child, Node *parent);

    //locates node containing specified data
    Node *find(int data);

    //finds successor of the given node
    Node *successor(Node *node);

    //finds the node with the minimal data in given subtree
    Node *minData(Node *node);

    //co-method for remove method, decides which case occurs
    static int whichCase(Node *siblingNode, char color);

public:
    //constructor
    RedBlackTree();

    //destructor
    virtual ~RedBlackTree();

    //adds node to the tree
    void add(int data);

    //prints content of the tree (using pre-order way of tree traversing)
    void show(Node *node);

    //returns the root of the tree
    [[nodiscard]]  Node *getRoot();

    //returns true if tree contains specified data, otherwise returns false
    bool contains(int data);

    //removes specified data
    void remove(int data);

    //removes all nodes
    void removeAll(Node *node);

};


#endif //UNTITLED1_REDBLACKTREE_H
