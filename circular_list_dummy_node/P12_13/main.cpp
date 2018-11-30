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
    Iterator last = --(people.end());
    cout << "first: " << *first << endl;
    cout << "last: " << *last << endl << endl;
    first--;
    last++;
    people.display("two");
    cout << "first--: " << *first << endl;
    cout << "last++: " << *last << endl << endl;
    first--;
    last++;
    people.display("three");
    cout << "first--: " << *first << endl;
    cout << "last++: " << *last << endl << endl;
    first = people.begin();
    last = people.end();
    people.display(first, "first");
    people.display(--last, "last ");
    
   
    return 0;
}
