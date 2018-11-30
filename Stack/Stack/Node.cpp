#include "Node.hpp"

Node::Node(){
    data = 0.0;
    previous = NULL;
    next = NULL;
}
Node::Node(std::string val){
    data = val;
    previous = NULL;
    next = NULL;
}
/* // default for now
~Node::Node(){
    previous = NULL;
    next = NULL;
    delete *this;
}
*/
