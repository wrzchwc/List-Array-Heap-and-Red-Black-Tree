//
// Created by kubaw on 18.04.2021.
//

#ifndef UNTITLED1_BINARYHEAP_H
#define UNTITLED1_BINARYHEAP_H

/*
 * todo int *add()
 * todo int *remove()
 * todo void show()
 * todo int *heap()
 */
class BinaryHeap {
private:
    //dynamic array storing data added to the binary heap
    int * heap;
    //size of the binary heap
    int size;
    //restores binary heap features to the structure
    void restore();
public:
    //constructor
    BinaryHeap();
    //adds specified data to heap
    void add(int data);
    //removes the root of the binary heap
    void remove();
    //returns true if heap contains specified data, otherwise returns false
    bool contains(int data);


};


#endif //UNTITLED1_BINARYHEAP_H
