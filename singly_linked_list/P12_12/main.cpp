/*
Exercise P12.12.
 Turn the linked list implementation into a singly-linked list:
 Drop the previous pointer of the nodes and the previous member function of the iterator.
 Reimplement the other member functions so that they have the same effect as before.
 Hint: In order to remove an element in constant time, iterators should store the predecessor of the current node.
*/

#include <iostream>
#include "List.hpp"
#include "Iterator.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    List people;
    Iterator iter = people.begin();
    
    people.insert(iter, 4);
    cout << "pb:  " << *iter << endl;
    people.push_back(7);
    iter++;
    cout << "pb:  " << *iter << endl;
    people.push_back(9);
    iter++;
    cout << "pb:  " << *iter << endl;
    people.insert(iter, 14);
    cout << "ins: " << *iter << endl;
    people.display(iter);
    people.erase(iter);
    people.display(iter);
    
    // Not going to finish implementations for reverse, get_size, etc. Was good enough to see how I could work with a 'before' data member in the Iterator class.
    
    return 0;
}
