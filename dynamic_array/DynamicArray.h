//
// Created by kubaw on 19.04.2021.
//

#ifndef UNTITLED1_DYNAMICARRAY_H
#define UNTITLED1_DYNAMICARRAY_H


class DynamicArray {
private:
    //size of the array
    int size;
    //dynamic-sized array
    int * array;
public:
    //constructor
    DynamicArray();
    //destructor
    virtual ~DynamicArray();
    //adds the data at the beginning of the dynamic array
    void addFirst(int data);
    //adds the data at the end of the dynamic array
    void addLast(int data);
    //adds the data at specified index in the dynamic array
    void add(int index, int data);
    //returns true if dynamic array contains specified value
    bool contains(int data);
    //removes the first element of the dynamic array
    void removeFirst();
    //removes the last element of the dynamic array
    void removeLast();
    //removes element at the specified position
    void remove(int index);
    //removes all elements fro, the array
    void removeAll();
    //prints the content of the dynamic array
    void show();
    //sets internal array
    void setArray(int *tmp);
};


#endif //UNTITLED1_DYNAMICARRAY_H
