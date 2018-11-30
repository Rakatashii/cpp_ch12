/*
 Exercise P12.16.
 Implement a Queue class, using a linked list of strings. Supply operations:
 size, push, pop, front, and back, just like in the standard stack template.
 */

#include <iostream>
#include "Queue.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Queue line;
    
    cout << "initial size = " << line.size() << endl << endl;
    
    line.push("Steve"); // first in line
    line.push("Larry");
    line.push("Mike");
    line.push("Sara");
    line.push("Donald"); // last in line
    
    string front = line.front();
    string back = line.back();
    cout << "front: " << front << endl;
    cout << "back: " << back << endl;
    cout << "size = " << line.size() << endl << endl;
    
    line.pop();
    
    front = line.front();
    back = line.back();
    cout << "front: " << front << endl;
    cout << "back: " << back << endl;
    cout << "size = " << line.size() << endl << endl;
    
    line.pop();
    
    front = line.front();
    back = line.back();
    cout << "front: " << front << endl;
    cout << "back: " << back << endl;
    cout << "size = " << line.size() << endl << endl;
    
    line.pop();
    
    front = line.front();
    back = line.back();
    cout << "front: " << front << endl;
    cout << "back: " << back << endl;
    cout << "size = " << line.size() << endl << endl;
    
    line.pop();
    
    front = line.front();
    back = line.back();
    cout << "front: " << front << endl;
    cout << "back: " << back << endl;
    cout << "size = " << line.size() << endl << endl;
    
    line.pop();
    
    // Assertions failed, as they should
    //front = line.front();
    //back = line.back();
    //cout << "front: " << front << endl;
    //cout << "back: " << back << endl;
    cout << "size = " << line.size() << endl << endl;
    
    
    
    
    
    return 0;
}
