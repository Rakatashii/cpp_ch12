/*
 Exercise P12.15. Implement a Stack class, using a linked list of strings. Supply opera-
 tions size, push, pop, and top, just like in the standard stack template.
*/

#include <iostream>
#include "Stack.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Stack books;
    books.push("3 lil P");
    books.push("Huck Fin");
    books.push("Toy Stry");
    string top_book = books.top();
    cout << "top_book = " << top_book << endl;
    books.pop();
    top_book = books.top();
    cout << "top_book = " << top_book << endl;
    books.pop();
    top_book = books.top();
    cout << "top_book = " << top_book << endl;
    books.pop();
    top_book = books.top();
    cout << "top_book = " << top_book << endl;
    
    /* Important insight:
     Stacks and Queues have NO Iterators
     
     The APIs for them are purposefully limited (for efficiency)
     
     Never:
     - sort a stack or queue
     - add items in the middle
     - remove items in the middle
     - search a stack or queue
     - copy or delete a range of a stack or queue
     
     std::stack and std::queue provide access to values at the ends(queue) or the top(stack) only.
     They do not need iterators because there is nothing to iterate. No reason to traverse or search in the container, just the ends. Only the target value (the one the data structure is built around) is what is important.
     
     Also note: none of this applies to std::deque / or a Deque class, which HAS iterators.
    */
    
    return 0;
}
