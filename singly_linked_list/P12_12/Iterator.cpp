#include "Iterator.hpp"

Iterator::Iterator(){
    position = NULL;
    container = NULL;
    before = NULL;
}
int Iterator::get() const{
    assert(position != NULL);
    return position->data;
}
void Iterator::next(int idx){
    assert(position != NULL);
    before = position;
    position = position->next;
    for (int i = 1; i < idx; i++){
        next(1);
    }
}
void Iterator::previous(int idx){
    assert(position != container->first); // current position is not the first in the list
    if (position == NULL)
        position = container->last; // Remember that even though the last element in the list is really NULL, that version if last is really just a termination indicator. Last always points to a node with a real value so long as the list is not truly empty
    else
        position = before;
    for (int i = 1; i < idx; i++){
        if (before != NULL) position = before;
    }
}
bool Iterator::equals(Iterator b) const{
    return position == b.position;
}
// Guessing it would be a little different when not working w/ strings - will wait for templates to get into that
int& Iterator::operator*(){
    /* std::string* node_data = &(position->data); return *node_data; */
    return *&(position->data);
}

Iterator& Iterator::operator++(){
    assert(position != container->last);
    next();
    return *this;
}

Iterator& Iterator::operator--(){
    assert(position != container->first);
    position = before;
    return *this;
}

Iterator& Iterator::operator++ (int) {  // pre-increment
    assert(position != container->last);
    next();
    return *this;
}

Iterator& Iterator::operator-- (int) {  // pre-increment
    assert(position != container->first);
    position = before;
    return *this;
}

