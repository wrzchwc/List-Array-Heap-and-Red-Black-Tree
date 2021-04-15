//
// Created by kubaw on 10.03.2021.
//

#include "ElementTwo.h"

ElementTwo::ElementTwo(int data) {
    this->data=data;
    previous= nullptr;
    next= nullptr;
}

ElementTwo *ElementTwo::getNext() const {
    return next;
}

void ElementTwo::setNext(ElementTwo *next) {
    ElementTwo::next = next;
}

ElementTwo *ElementTwo::getPrevious() const {
    return previous;
}

void ElementTwo::setPrevious(ElementTwo *previous) {
    ElementTwo::previous = previous;
}

int ElementTwo::getData() const {
    return data;
}
