#ifndef Iterator_hpp
#define Iterator_hpp

#include <stdio.h>
#include <cassert>
#include "List.hpp" 

class Iterator{
public:
    Iterator();
    int get() const;
    void next(int idx = 1);
    void previous(int idx = 1);
    bool equals(Iterator b) const;
    int& operator*();
    Iterator operator++();
    Iterator operator--();
    //friend std::ostream& operator<<(std::ostream& os, Iterator iter);
private:
    Node* position;
    List* container;
    friend class List;
};

/*
std::ostream& operator<<(std::ostream& os, Iterator iter){
    os << iter.get();
    return os;
};
 */

#endif /* Iterator_hpp */
