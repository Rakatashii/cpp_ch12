/*
 Exercise P12.16.
 Implement a Queue class, using a linked list of strings.Supply operations:
 size, push, pop, front, and back, just like in the standard stack template.
 */

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include "Node.hpp"
#include <cassert>

class Queue {
public:
    Queue();
    int size();
    void push(std::string data);
    void pop();
    std::string front();
    std::string back();
private:
    Node* first;
    Node* last;
    int sz;
};

#endif /* Queue_hpp */
