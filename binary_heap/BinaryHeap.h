//
// Created by kubaw on 18.04.2021.
//

#ifndef UNTITLED1_BINARYHEAP_H
#define UNTITLED1_BINARYHEAP_H


class BinaryHeap {
private:
    //dynamic dynamic array storing data added to the binary heap
    int *heap;
    //size of the binary heap
    int size;

public:
    //constructor
    BinaryHeap();

    BinaryHeap(int *h, int size);

    //destructor
    virtual ~BinaryHeap();

    //adds specified data to heap
    void add(int data);

    //removes the root of the binary heap
    void remove();

    //removes all data in the binary heap
    void removeAll();

    //returns true if heap contains specified data, otherwise returns false
    bool contains(int data);

    //prints content of the binary heap
    void show();

    //restores binary heap features to the structure
    void restore(int range, int offset = 0) const;
};


#endif //UNTITLED1_BINARYHEAP_H
