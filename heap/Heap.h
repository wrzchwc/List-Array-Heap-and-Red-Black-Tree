//
// Created by kubaw on 20.03.2021.
//

#ifndef UNTITLED1_HEAP_H
#define UNTITLED1_HEAP_H

#include <algorithm>

/*
 * todo int *add()
 * todo int *remove()
 * todo bool contains()
 * todo void show()
 * todo int *heap()
 */
//adds element to heap
int *add(const int heap[], int *size, int data) {
    int *tmp;

    //adding to empty heap
    if (heap == nullptr || *size == 0) {
        *size = *size + 1;
        tmp = new int[*size];
        tmp[0] = data;
    }
        //adding to not empty array
    else {
        tmp = new int[*size + 1];
        for (int i = 0; i < *size; i++)
            tmp[i] = heap[i];
        tmp[*size] = data;
        *size = *size + 1;
    }
    //todo HEAP REBUILDING
    return tmp;
}

//removes the root of the heap
int *remove(const int heap[], int *size) {
    //removing from empty heap
    if (heap == nullptr || *size == 0) {
        cout << "Kopiec jest pusty!" << endl;
        return heap;
    }
        //remoivng from not empty heap
    else {
        swap(heap[0], heap[*size - 1]);
        *size = *size - 1;
        int *tmp = new int[*size];
        for (int i = 0; i < *size; i++)
            tmp[i] = heap[i];
        return tmp;
    }
    //todo HEAP REBUILDING
}

//returns true if heap contains specified value
bool contains(int heap[], const int *size, int data) {
    int *tmp = heap;
    for (int i = 1; i <= *size; i++)
        if (tmp[i] == data)
            return true;
    return false;
}

//sets heap elements to match heap condition
void heap(int heap[], const int *size) {
    int last_parent = *size / 2 - 1;
    for (int i = last_parent; i >= 0; i--) {
        //last parent has two children
        if (2 * i + 2 <= *size - 1) {
            int *left_child = heap[2 * i + 1], *right_child = heap[2 * i + 2];

            if (*left_child > heap[i]){
                swap(heap[i],*left_child);

            }
            else if(*right_child>heap[i]){
                swap(heap[i],*right_child);
            }

        }
    }
}

#endif //UNTITLED1_HEAP_H
