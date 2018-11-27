/*
 Exercise P12.3. Write a function sort that sorts the elements of a linked list (without
 copying them into a vector).
*/

#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;

void quicksort(list<int>& nums, list<int>::iterator from, list<int>::iterator to);
list<int>::iterator partition(list<int>& nums, list<int>::iterator from, list<int>::iterator to);
void swap(list<int>::iterator& a, list<int>::iterator& b);
void print_list(list<int> nums);

int main(int argc, const char * argv[]) {
    const string file = "/Users/christianmeyer/cpp/ch12/P12_3/data.txt";
    
    // Need to find way to make popen recognize ruby gems required in script if possible
    /*
    string command = "/Users/christianmeyer/cpp/ch12/P12_3/generate_data.rb";
    FILE* pipe = popen(command.c_str(), "w");
    if (!pipe) {
        std::cerr << "Couldn't start command." << std::endl;
        return 0;
    }
     */
    
    list<int> nums;
    list<int>::iterator pos = nums.begin();
    int initial_sz = 100;
    string line;
    int n;
    
    fstream fs(file.c_str(), ios::in | ios::out);
    for (int i = 0; i < initial_sz; i++){
        getline(fs, line);
        n = stoi(line);
        nums.insert(pos, n);
        pos++;
    }
    fs.close();
    
    list<int>::iterator first = nums.begin();
    list<int>::iterator last = nums.end();

    quicksort(nums, first, last);
    print_list(nums);
    
    return 0;
}

void quicksort(list<int>& nums, list<int>::iterator from, list<int>::iterator to){
    int i = distance(nums.begin(), from);
    int j = distance(nums.begin(), to);
    if (i >= j) return;
    list<int>::iterator piv = partition(nums, from, to);
    quicksort(nums, from, piv);
    quicksort(nums, ++piv, to);
}
list<int>::iterator partition(list<int>& nums, list<int>::iterator from, list<int>::iterator to){
    list<int>::iterator pivot = from;
    int i = distance(nums.begin(), from) - 1;
    int j = distance(nums.begin(), to) + 1;
    from--;
    to++;
    while (i < j){
        i++; from++;
        while (*from < *pivot)
            { i++; from++; }
        j--; to--;
        while (*to > *pivot)
            { j--; to--; }
        if (i < j) swap(from, to);
    } return to;
}
void swap(list<int>::iterator& a, list<int>::iterator& b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print_list(list<int> nums){
    list<int>::iterator pos;
    int i = 0;
    for (pos = nums.begin(); pos != nums.end(); pos++){
        printf("pos%*i = %i\n", 2, i, *pos);
        i++;
    }
}





