#include "Stack.hpp"

Stack::Stack(){
    sz = 0;
    last = NULL;
    first = NULL;
}
void Stack::push(std::string data){
    Node* nn = new Node(data);
    if (first == NULL && last == NULL){
        first = nn;
        last = nn;
        first->next = NULL;
        
        sz++;
        return;
    }
    if (first == last){
        last = nn;
        first->previous = last;
        last->next = first;
    } else {
        last->previous = nn;
        nn->next = last;
        last = nn;
    }
    
    sz++;
}
void Stack::pop(){
    assert(last != NULL );
    if (sz > 1){
        last = last->next;
        delete last->previous;
    } else {
        last = NULL;
        first = last;
    }
    
    sz--;
}
std::string Stack::top(){
    if (last == NULL || sz == 0) {
        std::cout << "Error, stack is empty. Unable to return top node string.\n";
        return "-1";
    }
    
    return last->data;
}
int Stack::size(){
    return sz;
}

