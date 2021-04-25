//
// Created by kubaw on 19.04.2021.
//
#include <iostream>
#include "DynamicArray.h"

using namespace std;

DynamicArray::DynamicArray() {
    size = 0;
    array = nullptr;
}

DynamicArray::~DynamicArray() {
    removeAll();
}

void DynamicArray::addFirst(int data) {
    size++;
    //adding to empty dynamic array
    if (array == nullptr || size == 1) {
        array = new int[size];
        array[0] = data;
    }
        //adding to not empty dynamic array
    else {
        int *tmp = new int[size];
        tmp[0] = data;
        for (int i = 1; i < size; i++)
            tmp[i] = array[i - 1];
        delete array;
        array = tmp;
    }
}

void DynamicArray::addLast(int data) {
    //adding to empty dynamic array
    if (array == nullptr || size == 0)
        addFirst(data);
        //adding to not empty array
    else {
        int *tmp = new int[size + 1];
        for (int i = 0; i < size; i++)
            tmp[i] = array[i];
        tmp[size] = data;
        size++;
        delete array;
        array = tmp;
    }
}

void DynamicArray::add(int index, int data) {
    //incorrect index
    if (index < 0 || index > size)
        cout << "Nieprawidlowy indeks elementu do dodania." << endl;
        //adding at the beginning
    else if (array == nullptr || index == 0)
        addFirst(data);
        //adding at the end
    else if (index == size)
        addLast(data);
    else {
        size++;
        int *tmp = new int[size];
        tmp[index] = data;
        //part before index
        for (int i = 0; i < index; i++)
            tmp[i] = array[i];
        //part after index
        for (int i = index + 1; i < size; i++)
            tmp[i] = array[i - 1];
        delete array;
        array = tmp;
    }
}

bool DynamicArray::contains(int data) {
    int *tmp = array;
    for (int i = 0; i < size; i++)
        if (tmp[i] == data)
            return true;
    return false;
}

void DynamicArray::removeFirst() {
    //empty array
    if (size == 0 || array == nullptr)
        cout << "Tablica jest pusta" << endl;
        //list contains only one element
    else if (size == 1) {
        size--;
        delete[] array;
        array = nullptr;
    }
        //list contains more than one element
    else {
        size--;
        int *tmp = new int[size];
        for (int i = 1; i < size + 1; i++)
            tmp[i - 1] = array[i];
        delete[]array;
        array = tmp;
    }
}

void DynamicArray::removeLast() {
    //array is empty or contains one element
    if (size < 2)
        removeFirst();
        //array contains more than one element
    else {
        size--;
        int *tmp = new int[size];
        for (int i = 0; i < size; i++)
            tmp[i] = array[i];
        delete array;
        array = tmp;
    }
}

void DynamicArray::remove(int index) {
    //incorrect index
    if (index < 0 || index >= size)
        cout << "Nieprawidlowy indeks elementu do usuniecia!" << endl;
        //remove the first element
    else if (array == nullptr || index == 0)
        removeFirst();
        //remove the last element
    else if (index == size - 1)
        removeLast();
    else {
        size--;
        int *tmp = new int[size];
        //part before index
        for (int i = 0; i < index; i++)
            tmp[i] = array[i];
        //part after index
        for (int i = index + 1; i < size + 1; i++)
            tmp[i - 1] = array[i];
        delete[] array;
        array = tmp;
    }
}

void DynamicArray::show() {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void DynamicArray::removeAll() {
    while (size > 0)
        removeFirst();
}

void DynamicArray::setArray(int *tmp) {
    DynamicArray::array = tmp;
}

DynamicArray::DynamicArray(int *tmp, int size) {
    this->array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = tmp[i];
    }
    this->size = size;
}
