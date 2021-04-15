//
// Created by kubaw on 10.03.2021.
//

#ifndef UNTITLED1_ELEMENTTWO_H
#define UNTITLED1_ELEMENTTWO_H


class ElementTwo {
private:
    int data;
    ElementTwo *next;
    ElementTwo *previous;
public:
    explicit ElementTwo(int data);

    [[nodiscard]] ElementTwo *getNext() const;

    void setNext(ElementTwo *next);

    [[nodiscard]] ElementTwo *getPrevious() const;

    void setPrevious(ElementTwo *previous);

    [[nodiscard]] int getData() const;
};


#endif //UNTITLED1_ELEMENT_H
