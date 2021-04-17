//
// Created by kubaw on 18.04.2021.
//

#include <iostream>
#include "BinaryHeap.h"

using namespace std;

BinaryHeap::BinaryHeap() {
    heap = nullptr;
    size = 0;
}

void BinaryHeap::add(int data) {
    //heap is empty
    if (heap == nullptr || size == 0) {
        size++;
        heap = new int[size];
        heap[0] = data;
    }
        //heap is not empty
    else {
        size++;
        int *tmp = new int[size];
        for (int i = 0; i < size; i++) {
            tmp[i] = heap[i];
        }
        tmp[size] = data;
        delete heap;
        heap = tmp;
    }
    //todo: heap rebuilding

}

void BinaryHeap::remove() {
    //heap is empty
    if (heap == nullptr || size == 0)
        cout << "Heap is empty!" << endl;
        //heap is not empty
    else {
        swap(heap[0], heap[size - 1]);
        size--;
        int *tmp = new int[size];
        for (int i = 0; i < size; i++)
            tmp[i] = heap[i];
        delete heap;
        heap = tmp;
    }
    //todo: heap rebuilding
}

bool BinaryHeap::contains(int data) {
    int *tmp = heap;
    for (int i = 0; i < size; i++)
        if (tmp[i] == data)
            return true;
    return false;
}

void BinaryHeap::restore() {
    int last_parent = size / 2 - 1;
    for (int i = last_parent; i >= 0; i--) {
        //parent has two children
        if(2*i+2<=size-1){
//            int *left_child = heap[2 * i + 1], *right_child = heap[2 * i + 2];
//
//            if (*left_child > heap[i]){
//                swap(heap[i],*left_child);
//
//            }
//            else if(*right_child>heap[i]){
//                swap(heap[i],*right_child);
//            }
        }
        //parent has one child
        else if(2*i+1<=size-1){
            int *child=heap[]
        }
    }
}
