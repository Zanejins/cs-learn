//
// Created by zanejins on 2022/11/1.
//

#ifndef NEW_PROJECT_STACK_H
#define NEW_PROJECT_STACK_H

typedef unsigned long Item;

class Stack
{
private:
    enum{MAX = 10}; //constant specific to class
    Item items[MAX]; // hold stack items
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item); // add item to stack;
    bool pop(Item & item); //pop top into item
};

#endif //NEW_PROJECT_STACK_H
