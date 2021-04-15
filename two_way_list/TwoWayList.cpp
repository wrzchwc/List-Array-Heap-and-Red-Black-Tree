//
// Created by kubaw on 10.03.2021.
//
#include <iostream>
#include "TwoWayList.h"

using namespace std;

TwoWayList::TwoWayList() {
    size = 0;
    first = last = nullptr;
}

ElementTwo *TwoWayList::getPosition(int position) const {
    if (position < 0 || position > size)
        return nullptr;

        //position is searched from the tail
    else if (position >= size / 2) {
        ElementTwo *tmp = last;
        for (int i = size - 1; i > position; i--)
            tmp = tmp->getPrevious();

        return tmp;
    } else {
        ElementTwo *tmp = first;
        for (int i = 0; i < position; i++)
            tmp = tmp->getNext();

        return tmp;
    }


}


void TwoWayList::add(int data, int index) {
    //adding to empty list or adding at the beginning
    if (first == nullptr || index <= 0)
        addFirst(data);

        //adding at the end
    else if (index >= size)
        addLast(data);

        //adding in the middle
    else {
        auto *element = new ElementTwo(data);
        ElementTwo *tmp = getPosition(index);
        ElementTwo *before = getPosition(index - 1);
        before->setNext(element);
        element->setPrevious(before);
        tmp->setPrevious(element);
        element->setNext(tmp);

        size++;
    }
}

void TwoWayList::addFirst(int data) {
    auto *element = new ElementTwo(data);
    if (first == nullptr) {
        setFirst(element);
        setLast(element);
    } else {
        first->setPrevious(element);
        element->setNext(first);
        setFirst(element);
    }
    size++;
}

void TwoWayList::addLast(int data) {
    if (last != nullptr) {
        auto *element = new ElementTwo(data);
        last->setNext(element);
        element->setPrevious(this->last);
        setLast(element);
        size++;
    } else addFirst(data);

}

void TwoWayList::setFirst(ElementTwo *first) {
    TwoWayList::first = first;
    first->setPrevious(nullptr);
}

void TwoWayList::setLast(ElementTwo *last) {
    TwoWayList::last = last;
    last->setNext(nullptr);
}

void TwoWayList::show() const {
    auto *tmp = first;

    for (int i = 0; tmp != nullptr; i++) {
        cout << tmp->getData() << " ";
        tmp = tmp->getNext();
    }
    tmp = last;
    cout<<endl;
    for (int i = size - 1; tmp != nullptr; i--) {
        cout << tmp->getData() << " ";
        tmp = tmp->getPrevious();
    }
    cout << endl;
}


void TwoWayList::remove(int index) {
    //empty list
    if (first == nullptr && last == nullptr)
        cout << "Lista jest pusta" << endl;

        //incorrect index
    else if (index < 0 || index >= size)
        cout << "Nieprawidlowy indeks elementu do usuniecia." << endl;

        //removing the only one on the list,
    else if (size == 1 || index == 0)
        removeFirst();

        //removing last one
    else if (index == size - 1)
        removeLast();

        //removing one from the middle
    else {
        auto *tmp = getPosition(index);
        tmp->getPrevious()->setNext(tmp->getNext());
        tmp->getNext()->setPrevious(tmp->getPrevious());
        delete tmp;
        size--;
    }
}

void TwoWayList::removeAll() {
    while (size > 0)
        remove(size - 1);
}

void TwoWayList::removeFirst() {
    if (first == nullptr && last == nullptr) {
        cout << "Lista pusta!" << endl;
        return;
    } else if (first->getNext() == nullptr) {
        delete first;
        first = last = nullptr;
    } else {
        ElementTwo *tmp = first;
        setFirst(first->getNext());
        first->setPrevious(nullptr);
        delete tmp;
    }
    size--;
}

void TwoWayList::removeLast() {
    if (first == nullptr && last == nullptr) {
        cout << "Lista pusta!" << endl;
        return;
    } else if (last->getPrevious() == nullptr)
        removeFirst();
    else {
        ElementTwo *tmp = last;
        last->getPrevious()->setNext(nullptr);
        last = last->getPrevious();
        delete tmp;
    }
    size--;
}

bool TwoWayList::contains(int data) {
    ElementTwo *tmp = first;
    while (tmp != nullptr) {
        if (tmp->getData() == data)
            return true;
        tmp = tmp->getNext();
    }
    return false;
}

TwoWayList::~TwoWayList() {
    removeAll();
}












