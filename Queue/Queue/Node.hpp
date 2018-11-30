#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>

class Queue;

class Node{
public:
    Node() : next(NULL), previous(NULL) {}
    Node(std::string value) : next(NULL), previous(NULL), data(value) {}
private:
    std::string data;
    Node* next;
    Node* previous;
    
    friend class Queue;
};

#endif /* Node_hpp */
