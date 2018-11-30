/*
 Exercise P12.15.
 Implement a Stack class, using a linked list of strings. Supply opera-
 tions size, push, pop, and top, just like in the standard stack template.
*/

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <iostream>
#include "Iterator.hpp"

class Stack{
public:
    Stack();
    void push(std::string data);
    void pop();
    std::string top();
    int size();
private:
    Node* last;
    Node* first;
    int sz;
};

#endif /* Stack_hpp */
