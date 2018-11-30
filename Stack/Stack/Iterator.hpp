#ifndef Iterator_hpp
#define Iterator_hpp

#include <stdio.h>
#include "Node.hpp"
#include <cassert>

class Stack;

class Iterator{
public:
    Iterator();
    std::string get() const;
    void next();
    void previous();
    bool operator==(const Iterator& b) const;
    bool operator!=(const Iterator& b) const;
    std::string& operator*();
private:
    Node* position;
    Stack* container;
    
    friend class Stack;
};

#endif /* Iterator_hpp */
