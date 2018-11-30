#include "Iterator.hpp"

Iterator::Iterator(){
    position = NULL;
    container = NULL;
}
int Iterator::get() const{
    assert(position != NULL);
    return position->data;
}
void Iterator::next(int idx){
    assert(position != NULL);
    position = position->next;
    for (int i = 1; i < idx; i++){
        next(1);
    }
}
void Iterator::previous(int idx){
    //assert(position != container->first); // current position is not the first in the list
    assert(position != NULL);
    position = position->previous; // try this alone
    for (int i = 1; i < idx; i++){
        previous(1);
    }
}
bool Iterator::equals(Iterator b) const{
    return position == b.position;
}
// Guessing it would be a little different when not working w/ strings - will wait for templates to get into that
int& Iterator::operator*(){
    assert(this->position != NULL);
    /* std::string* node_data = &(position->data); return *node_data; */
    return *&(position->data);
}

Iterator& Iterator::operator++(){
    next();
    return *this;
}
Iterator& Iterator::operator--(){
    previous();
    return *this;
}
Iterator& Iterator::operator++ (int) {  // pre-increment
    next();
    return *this;
}
Iterator& Iterator::operator-- (int) {  // pre-increment
    previous();
    return *this;
}

