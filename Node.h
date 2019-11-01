#ifndef NODE_H
#define NODE_H

class Node {
public:
    // Node constructor
    Node(int v = 0, Node* n = nullptr);

    // Node value accessor
    int getValue() const;

    // Node next pointer accessor
    Node* getNext() const;

    void setValue(int v); // good practice to have the setters
    void setNext(Node* n);

    friend class LinkedList;

private:
    int value;
    Node* next;
};

#endif //NODE_H