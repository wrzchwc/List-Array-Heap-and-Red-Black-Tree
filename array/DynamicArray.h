//
// Created by kubaw on 17.03.2021.
//

#ifndef UNTITLED1_DYNAMICARRAY_H
#define UNTITLED1_DYNAMICARRAY_H

#include <iostream>

using namespace std;


//adds at the beginning of the array
int *addFirst(int array[], int *size, int data) {
    int *tmp;
    *size = *size + 1;
    //adding to empty array
    if (array == nullptr || *size == 1) {
        tmp = new int[*size];
        tmp[0] = data;
    }
        //adding to not empty array
    else {
        tmp = new int[*size];
        tmp[0] = data;
        for (int i = 1; i < *size; i++)
            tmp[i] = array[i - 1];
    }
    delete[] array;
    return tmp;
}

//adds at the end of the array
int *addLast(int array[], int *size, int data) {
    int *tmp;
    //adding to empty array
    if (array == nullptr || *size == 0)
        return addFirst(array, size, data);
        //adding to not empty array
    else {
        tmp = new int[*size + 1];
        for (int i = 0; i < *size; i++){
            tmp[i] = array[i];
        }
        tmp[*size] = data;
    }
    *size = *size + 1;
    delete[] array;
    return tmp;
}

//adds at specified index int the array
int *add(int array[], int *size, int index, int data) {
    //incorrect index
    if (index < 0 || index > *size)
        cout << "Nieprawidlowy indeks elementu do dodania!" << endl;

        //incorrect size
    else if (*size < 0)
        cout << "Nieprawidlowy rozmiar tablicy!" << endl;

        //adding at the beginning
    else if (array == nullptr || index == 0)
        return addFirst(array, size, data);

        //adding at the end
    else if (index == *size)
        return addLast(array, size, data);

    else {
        *size = *size + 1;
        int *tmp = new int[*size];
        tmp[index] = data;
        //part before index
        for (int i = 0; i < index; i++)
            tmp[i] = array[i];
        //part after index
        for (int i = index + 1; i < *size; i++)
            tmp[i] = array[i - 1];
        delete[] array;
        return tmp;
    }

    //do nothing if something is wrong
    return array;

}

//returns true if array contains specified value
bool contains(int array[], const int *size, int data) {
    int *tmp = array;
    for (int i = 0; i < *size; i++)
        if (tmp[i] == data)
            return true;
    return false;
}

//removes the first element of the array
int *removeFirst(int array[], int *size) {
    //empty list
    if (*size == 0)
        cout << "Tablica jest pusta!" << endl;
        //list consisting of only one element
    else if (*size == 1) {
        *size = *size - 1;
        delete[] array;
        array = nullptr;
    }
        //list consisting of more than one element
    else {
        *size = *size - 1;
        int *tmp = new int[*size];
        for (int i = 1; i < *size + 1; i++)
            tmp[i - 1] = array[i];
        delete[] array;
        return tmp;
    }
    return array;
}

//remove the last element of the array
int *removeLast(int array[], int *size) {

    //empty list or list consisting of only one element
    if (*size < 2)
        return removeFirst(array, size);

        //list consisting of more than one element
    else {
        *size = *size - 1;
        int *tmp = new int[*size];
        for (int i = 0; i < *size; i++)
            tmp[i] = array[i];
        delete[] array;
        return tmp;
    }
}

//removes element at specified position
int *remove(int array[], int *size, int index) {
    //incorrect index
    if (index < 0 || index > *size)
        cout << "Nieprawidlowy indeks elementu do usuniecia!" << endl;

        //incorrect size
    else if (*size < 0)
        cout << "Nieprawidlowy rozmiar tablicy!" << endl;

        //remove the first element
    else if (array == nullptr || index == 0)
        return removeFirst(array, size);

        //remove the last element
    else if (index == *size)
        return removeLast(array, size);

    else {
        *size = *size - 1;
        int *tmp = new int[*size];

        //part before index
        for (int i = 0; i < index; i++)
            tmp[i] = array[i];

        //part after index
        for (int i = index + 1; i < *size + 1; i++)
            tmp[i - 1] = array[i];
        delete[] array;
        return tmp;
    }
    return array;
}

//prints content of the list
void show(int *array, const int *size) {
    for (int i = 0; i < *size; i++)
        cout << array[i] << " ";
    cout << endl;
}

#endif //UNTITLED1_DYNAMICARRAY_H
