#include "List.hpp"

List::List(){
    first = NULL;
    last = NULL;
    list_size = 0;
}
void List::push_back(int data){
    Node* new_node = new Node(data);
    if (last == NULL) { // list is empty
        first = new_node;
        last = new_node;
    } else{
        last->next = new_node;
        new_node->previous = last;
        last = new_node; // new node now recognized as last node
        last->next = first;
        first->previous = last;
    }
    list_size++;
}
void List::push_front(int data){
    insert(begin(), data);
}
void List::insert(Iterator iter, int data){
    if (iter.position == last){ // iter is pointing to last element
        push_back(data);
        return;
    }
    Node* after = iter.position;
    Node* before = after->previous;
    Node* new_node = new Node(data);
    new_node->previous = before;
    new_node->next = after;
    after->previous = new_node; // We know that after->next is not NULL, since we would have already called pushback if so.
    // Now want to call brefore->next = new_node, but it is still possible that before is NULL
    if (before == NULL){
        first = new_node;
        if (last != NULL) first->previous = last;
    } else{
        before->next = new_node;
    }
    list_size++;
}
Iterator List::erase(Iterator iter){
    // It is illegal to erase any element past the end, so also cannot erase the last element (== NULL)
    assert(iter.position != NULL);
    Node* remove = iter.position;
    Node* before = remove->previous;
    Node* after = remove->next;
    
    //We want:
    //before->next = after; // if before != NULL
    //after->previous = before // if after != NULL
    // However, it is still possible that before or after or both are NULL
    if (remove == first){
        first = after; // Seems this is ok even if after is NULL
        first->previous = last;
    } else {
        before->next = after; // there is at least one element before remove
    }
    if (remove == last){
        last = before;
        last->next = first;
    } else {
        after->previous = before;
    }
    delete remove; // remove still points to after and before, but now after->previous is before and before->next = after. We should delete this pointer since there is no need to have multiple pointers to and from the same Node.
    Iterator r;
    r.position = after; // We return the element that comes after the erased element
    // Intuitively, why is this a good thing? Well if we think in terms of vector, and wanted to remove some v[i], we are being returned the new value of in v at index i once that value is removed. If we returned before instead, then that would be like decrementing the Iterator within this function call, which would be kind of confusing.
    r.container = this;
    list_size--;
    return r;
}
Iterator List::begin(){
    Iterator iter;
    iter.position = first;
    iter.container = this;
    return iter;
}
Iterator List::end(){
    Iterator iter;
    iter.position = last;
    iter.container = this;
    return iter;
}
bool List::is_empty() const{
    // first == last is just a reminder
    if (first == last && first == NULL && last == NULL) return true;
    else return false;
}
void List::display(std::string list_name){
    Iterator iter;
    const int print_width = 10;
    
    std::cout << list_name << ": { ";
    /*
    for (iter = begin(); !(iter.equals(end())); iter.next()){
        int n = iter.get();
        printf("[ %*i ]", print_width, n);
        if (!(iter.equals(end()))) std::cout << ", ";
    }
     */
    iter = begin();
    for (int i = 0; i < list_size; i++){
        int n = iter.get();
        printf("[ %*i ]", print_width, n);
        if (i < list_size-1) std::cout << ", ";
        iter++;
    }
    if (iter.position == first || iter.position == NULL) printf(" ~%*s~ ", print_width, "FULL_CIRCLE");
    std::cout << "}\n";
}
void List::display(Iterator pos, std::string list_name){
    Iterator iter;
    const int print_width = 10;
    bool keep_counting = true;
    int char_count = print_width + list_name.length() + 4;
    
    std::cout << list_name << ": { ";
    iter = begin();
    for (int i = 0; i < list_size; i++){
        int n = iter.get();
        printf("[ %*i ]", print_width, n);
        if (i < list_size-1) std::cout << ", ";
        if (iter.equals(pos)) keep_counting = false;
        else if (keep_counting) char_count += 14;
        iter++;
    }
    /*
    for (iter = begin(); !(iter.equals(end())); iter.next()){
        int n = iter.get();
        printf("[ %*i ]", print_width, n);
        if (!(iter.equals(end()))) std::cout << ", ";
        if (iter.equals(pos)) keep_counting = false;
        else if (keep_counting) char_count += 16;
    }
     */
    if (iter.position == first || iter.position == NULL){
        printf(" ~%*s~ ", print_width, "FULL_CIRLCE");
        if (iter.equals(end())) keep_counting = false;
    }
    std::cout << "}\n";
print_pos: if (!keep_counting) printf("%*s\n", char_count, "(pos)");
}
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
int List::size(){
    return list_size;
}











