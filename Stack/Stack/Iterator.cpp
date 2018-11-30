#include "Iterator.hpp"

Iterator::Iterator(){
    position = NULL;
    container = NULL;
}
std::string Iterator::get() const{
    assert(position != NULL);
    return position->data;
}
void Iterator::next(){
    assert(position->next != NULL);
    position = position->next;
}
void Iterator::previous(){
    assert(position->previous != NULL);
    position = position->previous;
}
bool Iterator::operator==(const Iterator& b) const{
    if (position == b.position && container == b.container) return true;
    else return false;
}
bool Iterator::operator!=(const Iterator& b) const{
    return !(*this == b);
}
std::string& Iterator::operator*(){
    return *&(position->data);
}
