#include "Node.h"
using namespace std;

// constructor
Node::Node(int v, Node* n) {
    value = v;
    next = n;
}

int Node::getValue() const {
    return value;
}

Node* Node::getNext() const {
    return next;
}

void Node::setValue(int v) {
    value = v;
}

void Node::setNext(Node* n) {
    next = n;
}