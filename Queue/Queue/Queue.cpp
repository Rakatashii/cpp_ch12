/*
 Exercise P12.16.
 Implement a Queue class, using a linked list of strings.Supply operations:
 size, push, pop, front, and back, just like in the standard stack template.
*/

#include "Queue.hpp"

Queue::Queue(){
    first = NULL;
    last = NULL;
    sz = 0;
}
int Queue::size(){
    return sz;
}
void Queue::push(std::string data){
    Node* nn = new Node(data);
    if (first == NULL && last == NULL){
        first = nn;
        last = nn;
        first->previous = NULL;
        last->next = NULL;
        sz++;
        return;
    } else if (first == last){
        last = nn;
        last->next = first;
        first->previous = last;
        sz++;
        return;
    }
    last->previous = nn;
    nn->next = last;
    last = nn;
    sz++;
    return;
}
void Queue::pop(){
    assert(first != NULL);
    if (sz == 1){
        delete first;
        first = NULL;
        last = first;
        sz--;
        return;
    }
    first = first->previous;
    delete first->next;
    first->next = NULL;
    sz--;
}
std::string Queue::front(){
    assert(first != NULL);
    return first->data;
}
std::string Queue::back(){
    assert(last != NULL);
    return last->data;
}
