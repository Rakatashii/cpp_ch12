/*
 Exercise P12.11.
 Turn the linked list implementation into a circular list:
 Have the previous pointer of the first node point to the last node, and the next pointer of the last node point to the first node.
 Then remove the last pointer in the List class since the value can now be obtained as
 first->previous.
 Reimplement the member functions so that they have the same effect as before.
*/

#include <iostream>
#include "List.hpp"
#include "Iterator.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    List people;
    Iterator iter = people.begin();
    people.push_back(14);
    people.push_back(17);
    people.display("one");
    Iterator first = people.begin();
    Iterator last = people.end();
    cout << "first: " << *first << endl;
    cout << "last: " << *last << endl;
    first--;
    last++;
    cout << "first--: " << *first << endl;
    cout << "last++: " << *last << endl;
    first = people.begin();
    last = people.end();
    people.display(first, "first");
    people.display(last, "last ");
    
    /*
    people.insert(iter, 4);
    people.insert(iter, 7);
    
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

    people.swap(other);
    people.display(people.begin(), "people (swap)");
    other.display(other.begin(), "other (swap)");

    int ppl_sz = people.size();
    cout << "ppl_size = " << ppl_sz << endl;
    int oth_sz = other.size();
    cout << "oth_sz = " << oth_sz << endl;
    */
    
    // So far List is looking ok, still need to work on iterator cpp, especially next and previous
    

    return 0;
}
