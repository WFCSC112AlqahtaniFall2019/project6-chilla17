#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H
#include <iostream>
#include "Node.h"
using namespace std;


class LinkedList {

public:
    Node* head;
    Node* current;
    Node* next;

    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList &list);
    LinkedList& operator=(const LinkedList &copyLinkedList);
    void append(int item);
    // void remove(int item); - do not need this anymore
    void print();
    void insertionSort();

    friend class Node;

};


#endif //BINARYINSERTIONSORT_LINKEDLIST_H
