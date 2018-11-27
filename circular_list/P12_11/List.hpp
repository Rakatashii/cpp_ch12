#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <iostream>
#include "Node.hpp"
#include "Iterator.hpp"

class List{
public:
    List();
    void push_back(int data);
    void push_front(int data);
    void insert(Iterator iter, int data);
    Iterator erase(Iterator iter);
    Iterator begin();
    Iterator end();
    bool is_empty() const;
    void display(std::string list_name = "List");
    void display(Iterator pos, std::string list_name = "List");
    void reverse();
    void swap(List& b);
    int get_size();
    int size();
private:
    Node* first;
    Node* last;
    friend class Iterator;
    int list_size;
};

#endif /* List_hpp */
