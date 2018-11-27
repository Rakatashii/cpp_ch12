/*
 Exercise P12.1. Write a function
 void downsize(list<string>& names)
 that removes every second value from a linked list.
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

void downsize(list<string>& names);

int main(int argc, const char * argv[]) {
    list<string> names;
    names.push_back("John");
    names.push_back("Sara");
    names.push_back("Max");
    names.push_back("Henry");
    names.push_back("Jen");

    cout << "Before downsizing list: " << endl;
    list<string>::iterator iter;
    int i = 1;
    for (iter = names.begin(); iter != names.end(); iter++){
        cout << "Name" << i << " = " << *iter << endl;
        i++;
    }
    i = 1;
    downsize(names);
    cout << endl << "After downsizing list:" << endl;
    for (iter = names.begin(); iter != names.end(); iter++){
        cout << "Name" << i << " = " << *iter << endl;
        i++;
    }
    
    i = 1;
    downsize(names);
    cout << endl << "After downsizing list again:" << endl;
    for (iter = names.begin(); iter != names.end(); iter++){
        cout << "Name" << i << " = " << *iter << endl;
        i++;
    }
    
    i = 1;
    downsize(names);
    cout << endl << "After downsizing list again, and again:" << endl;
    for (iter = names.begin(); iter != names.end(); iter++){
        cout << "Name" << i << " = " << *iter << endl;
        i++;
    }
    
    cout << endl;
    return 0;
}
void downsize(list<string>& names){
    list<string>::iterator pos;
    int i = 0;
    for (pos = names.begin(); pos != names.end(); pos++){
        if (i % 2 != 0) names.erase(pos);
        i++;
    }
}
