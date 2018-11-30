#include "List.hpp"

List::List(){
    first = NULL;
    last = NULL;
    list_size = 0;
}
void List::push_back(int data, Iterator* iter){ // For now, aside from overload, don't see an alternative to the optional Iterator parameter, aside from rewriting the function contents within insert.
    Node* new_node = new Node(data);
    if (last == NULL) {
        first = new_node;
        last = new_node;
        if (iter != NULL) iter->before = NULL;
        new_node->next = NULL;
        if (iter != NULL) iter->position = new_node;
    } else{
        if (iter != NULL) iter->before = last;
        last->next = new_node;
        last = new_node;
        if (iter != NULL) iter->position = last;
        new_node->next = NULL;
    }
    list_size++;
}
void List::push_front(int data){
    Iterator iter = begin();
    insert(iter, data);
}
void List::insert(Iterator& iter, int data){
    if (last == NULL){
        push_back(data, &iter);
        return;
    }
    Node* new_node = new Node(data);
    Node* prev;
    Node* after;
    
    if (iter.position == first){
        prev = NULL;
        after = first;
        last = first;
        first = new_node;
        new_node->next = last;
        iter.before = prev;
    } else {
        prev = iter.before;
        after = iter.position;
        prev->next = new_node;
        new_node->next = after;
        iter.before = prev;
    }
    
    if (prev == NULL){
        first = new_node;
        iter.before = NULL;
    } else{
        iter.before = prev;
        prev->next = new_node;
    }
    iter.position = new_node;
    list_size++;
}
void List::erase(Iterator& iter){
    assert(iter.position != NULL);
    Node* prev = iter.before;
    Node* remove = iter.position;
    Node* after = remove->next;
    
    if (remove == first){
        first = after; // Seems this is ok even if after is NULL
        iter.before = NULL;
        iter.position = first;
    } else {
        prev->next = after; // there is at least one element before remove
        iter.position = after;
        iter.before = prev;
    }
    
    if (remove == last){
        last = prev;
        prev->next = NULL;
        iter.position = prev;
    }
    
    remove->next = NULL;
    delete remove;
    remove = NULL;

    list_size--;
}
Iterator List::begin(){
    Iterator iter;
    iter.position = first;
    iter.container = this;
    iter.before= NULL;
    return iter;
}
Iterator List::end(){
    Iterator iter;
    iter.position = NULL; // Note that iter.position is not last, last is the last element in the list that is not NULL
    iter.container = this;
    iter.before = last;
    return iter;
}
bool List::is_empty() const{
    if (first == NULL && last == NULL) return true;
    else return false;
}
void List::display(std::string list_name){
    Iterator iter;
    const int print_width = 10;
    
    std::cout << list_name << ": { ";
    for (iter = begin(); !(iter.equals(end())); iter.next()){
        int n = iter.get();
        printf("[ %*i ]", print_width, n);
        if (!(iter.equals(end()))) std::cout << ", ";
    }
    if (iter.position == NULL) printf("[ %*s ]\n", print_width, "(END)  ");
}
void List::display(Iterator pos, std::string list_name){
    Iterator iter;
    const int print_width = 10;
    bool keep_counting = true;
    int char_count = print_width + list_name.length() + 4;
    
    std::cout << list_name << ": { ";
    for (iter = begin(); !(iter.equals(end())); iter.next()){
        int n = iter.get();
        printf("[ %*i ]", print_width, n);
        if (!(iter.equals(end()))) std::cout << ", ";
        if (iter.equals(pos)) keep_counting = false;
        else if (keep_counting) char_count += 16;
    }
    if (iter.position == NULL){
        printf("[ %*s ]", print_width, "(END)  ");
        if (iter.equals(end())) keep_counting = false;
    }
    std::cout << " }\n";
print_pos: if (!keep_counting) printf("%*s\n", char_count, "(pos)");
}
/*
void List::reverse(){
    List b;
    Iterator first = begin();
    Iterator last = end();
    if (first.equals(last)) return;
    do{
        last--;
        b.push_back(*last);
        erase(last);
    } while (!last.equals(first));
    
    for (first = b.begin(); !first.equals(b.end()); first++) push_back(*first);
}
 */
void List::swap(List& b){
    int b_size = b.list_size;
    b.list_size = list_size;
    list_size = b_size;
    
    Node* other_first = b.first;
    Node* other_last = b.last;
    b.first = first;
    b.last = last;
    first = other_first;
    last = other_last;
}
/* Inefficient function for getting list size
int List::get_size(){
    Iterator first = begin();
    Iterator last = end();
    int i = 0;
    if (first.equals(last)) return i;
    do {
        first++;
        i++;
    } while (!first.equals(last));
    return i;
} */
int List::size(){
    return list_size;
}











