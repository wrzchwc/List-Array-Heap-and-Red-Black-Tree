//
// Created by kubaw on 19.04.2021.
//
#include "Node.h"

#ifndef UNTITLED1_REDBLACKTREE_H
#define UNTITLED1_REDBLACKTREE_H

//todo: What should be done here ?
//todo: public void add(int data);
//todo: private void checkConflict(Node*parent, Node*child)
//todo: private void verifyAfterAddition(Node *parent, Node *child)
//todo: private void verifyAfterDeletion(Node *parent, Node *child)
//todo: private void rotate(Node*A, Node*B, bool left)
//todo: public void show(Node *node)     //using post order ofc
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

public:
    //constructor
    RedBlackTree();

    //destructor
    virtual ~RedBlackTree();

    //adds node to the tree
    void add(int data, Node *sub_root);

    //prints content of the tree (using pre-order way of tree traversing)
    void show(Node *node);

    //returns the root of the tree
    [[nodiscard]]  Node *getRoot();

    //returns true if tree contains specified data, otherwise returns false
    bool contains(int data, Node *node);

};


#endif //UNTITLED1_REDBLACKTREE_H
