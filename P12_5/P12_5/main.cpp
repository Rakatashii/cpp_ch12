#include <iostream>
#include "List.hpp"
#include "Iterator.hpp"

using namespace std;

// DOES STRING_LLIST SEE THIS??? // Nope

int main(int argc, const char * argv[]) {
    List people;
    Iterator iter = people.begin();
    people.insert(iter, 4);
    people.insert(iter, 7);
    
    people.display(iter);
    iter.previous();
    people.display(iter);
    iter = people.begin();
    people.display(iter);
    
    *iter = 18;
    ++iter;
    *iter = 45;
    people.display(iter);

    return 0;
}
