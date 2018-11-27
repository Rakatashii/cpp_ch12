/*
 Exercise P12.6.
 Write a member function List::reverse() that reverses the nodes in a list.
 // done
 
 Exercise P12.7.
 Write a member function List::push_front() that adds a value to the
 beginning of a list.
 // done
 
 Exercise P12.8.
 Write a member function List::swap(List& other) that swaps the
 elements of this list and other. Your method should work in O(1) time.
 // done
 
 Exercise P12.9.
 Write a member function List::get_size() that computes the num- ber of elements in the list, by counting the elements until the end of the list is reached.
 // done
 
 Exercise P12.10.
 Add a size field to the List class. Modify the insert and erase functions to update the size field so that it always contains the correct size. Change the get_size() function of Exercise P12.9 to take advantage of this data field.
*/

#include <iostream>
#include "List.hpp"
#include "Iterator.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    List people;
    Iterator iter = people.begin();
    people.insert(iter, 4);
    people.insert(iter, 7);
    
    // Testing pre/pos increment/decrement operators: pre/post both serve same purpose as of now
    /*
    iter--;
    people.display(iter);
     --iter;
    *iter = 18;
    people.display(iter, "after dec");
    iter++;
    *iter = 45;
    people.display(iter, "after incr");
    iter--;
    ++iter;
    people.display(iter);
    --iter;
    people.display(iter);
    */
    
    people.reverse();
    people.display(iter, "reverse");
    people.push_front(13);
    people.push_front(78);
    people.display(iter, "push_front");
    
    List other;
    other.push_back(16);
    other.push_back(99);
    other.push_back(48);
    
    other.display(other.begin(), "other");
    
    cout << endl;
    
    // These are working as expected.
    // So just by swapping the first and last node pointers for each list, we also get all of the #next and #previous nodes that those nodes point to.
    // Might be able to implement a #reverse just be swapping first for last, but that would still require changing #next and previous for all those nodes in between
    people.swap(other);
    people.display(people.begin(), "people (swap)");
    other.display(other.begin(), "other (swap)");

    int ppl_sz = people.size();
    cout << "ppl_size = " << ppl_sz << endl;
    int oth_sz = other.size();
    cout << "oth_sz = " << oth_sz << endl;
    
    

    return 0;
}
