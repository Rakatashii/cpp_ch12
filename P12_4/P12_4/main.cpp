/*
 Exercise P12.4.
 Write a function merge that merges two lists into one, alternating ele- ments from each list until the end of one of the lists has been reached, then append- ing the remaining elements of the other list. For example, merging the lists containing A B C and D E F G H should yield the list A D B E C F G H.
*/

#include <iostream>
#include <list>
#include <string>

using namespace std;

void merge(list<int>& a, list<int>& b);
void print_list(list<int>& l);

int main(int argc, const char * argv[]) {
    list<int> a;
    for (int i = 0; i < 13; i++){
        a.push_back(i+1);
    }

    list<int> b;
    for (int i = 13; i < 20; i++){
        b.push_back(i+1);
    }
    
    cout << "A" << endl;
    print_list(a);
    cout << endl;
    cout << "B" << endl;
    print_list(b);
    cout << endl;
    
    list<int> a_cpy = a;
    cout << "merge(A, B)" << endl;
    merge(a, b);
    print_list(a);
    cout << endl;
    cout << "merge(B, A)" << endl;
    merge(b, a_cpy);
    print_list(b);
    cout << endl;
    
    return 0;
}

void merge(list<int>& a, list<int>& b){
    list<int>::iterator b_start = b.begin();
    int b_size = b.size();
    for (int i = 0; i < b_size; i++){
        a.push_back(*b_start);
        b_start++;
    }
}
void print_list(list<int>& l){
    int i = 0;
    for (list<int>::iterator pos = l.begin(); pos != l.end(); pos++){
        printf("list%*i: %i\n", 2, i, *pos);
        i++;
    }
}








