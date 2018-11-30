#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>

class Stack;
class Iterator;

class Node{
public:
    Node();
    Node(std::string val);
    //~Node();
private:
    std::string data;
    Node* next;
    Node* previous;
    
    friend class Stack;
    friend class Iterator;
};

#endif /* Node_hpp */
