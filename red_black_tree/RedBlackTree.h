//
// Created by kubaw on 19.04.2021.
//
#include "Node.h"

#ifndef UNTITLED1_REDBLACKTREE_H
#define UNTITLED1_REDBLACKTREE_H

//todo: What should be done here ?
//todo: public void add(int data);
//todo: private void checkConflict(Node*parent, Node*child)
//todo: private void rotate_left(Node*A, Node*B)
//todo: private void rotate_right(Node*A, Node*B)
//todo: public void show()              //using in order ofc
//todo: public void remove(int data)    // omg, kinda scary
//todo: public void removeAll()
//todo: public void show(Node *node)
class RedBlackTree {
private:
    //size of the red-black tree
    int size;
    //root of the red-black tree
    Node *root;
public:
    //constructor
    RedBlackTree();

    //destructor
    virtual ~RedBlackTree();

    //adds node to the tree
    void add(int data, Node *sub_root);

    //prints content of the tree (using in-order way of tree traversing)
    void show(Node *node);

    //returns the root of the tree
    [[nodiscard]] Node *getRoot() const;

    //returns true if tree contains specified data, otherwise returns fals
    bool contains(int data);

};


#endif //UNTITLED1_REDBLACKTREE_H
