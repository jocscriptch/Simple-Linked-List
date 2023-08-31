#include "Node.h"

Node::Node(Person* per, Node* nxt) { 

    person = per;
    next = nxt;
}
void Node::setPerson(Person *per) {

    person = per;
}

Person* Node::getPerson() {
    return person;
}

void Node::setNext(Node *nxt) {
    next = nxt;
}

Node* Node::getNext() {
    return next;
}

Node::~Node() {

}