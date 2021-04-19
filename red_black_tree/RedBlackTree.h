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

};


#endif //UNTITLED1_REDBLACKTREE_H
