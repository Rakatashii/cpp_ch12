#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

class List;
class Iterator;

// Aside from the constructor, there is no need to define anything for this class, since the private data members are handled through the two friend classes
class Node{
public:
    Node(int val) : data(val), next(NULL) {} // Note no need for semicolon when using this syntax
private:
    int data;
    Node* next;
    friend class List; // The List class can inspect and modify the data members of the Node class
    friend class Iterator; // So can Iterator
};

#endif /* Node_hpp */
