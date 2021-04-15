//
// Created by kubaw on 10.03.2021.
//

#ifndef UNTITLED1_TWOWAYLIST_H
#define UNTITLED1_TWOWAYLIST_H


#include "ElementTwo.h"

class TwoWayList {
private:
    int size;
    ElementTwo *first;
    ElementTwo *last;

    [[nodiscard]] ElementTwo *getPosition(int position) const;

    void setFirst(ElementTwo *first);
    void setLast(ElementTwo *last);


public:
    TwoWayList();

    virtual ~TwoWayList();

    //returns true if ElementTwo with given data on the list, otherwise returns false
    bool contains(int data);

    //adds new element into given index
    void add(int data, int index);

    //adds new element at the beginning
    void addFirst(int data);

    //adds new element at the end
    void addLast(int data);

    //prints all the elements on the list, length of the list, data pointed by first an last
    void show() const;

    //removes all the elements on the list
    void removeAll();

    //removes element at given index
    void remove(int index);

    //removes the first element
    void removeFirst();

    //removes the last element
    void removeLast();


};


#endif //UNTITLED1_TWOWAYLIST_H
