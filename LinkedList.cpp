#include "LinkedList.h"
#include <iostream>
using namespace std;

// constructor
LinkedList::LinkedList() {
    cout << "Constructor called." << endl;
    head = nullptr; // initialize empty list
}

// big three

// destructor
LinkedList::~LinkedList() {
    cout << "Destructor called." << endl;

    current = head; // current points to first node
    while (current != nullptr) { // loop ends when current does not point to a node
        next = current->getNext(); // next node
        delete current; // delete current
        current = next; // next node becomes current
    }
}

// copy constructor
LinkedList::LinkedList(const LinkedList &list){
    cout << "Copy constructor called." << endl;

    if (current == nullptr){ // the case that the list is empty
        head = nullptr;
    }

    else { // the case that the list is not empty
        head = new Node(list.head->getValue()); // allocate new memory
        current = head; // current point to first node

        Node* currentCopy = current; // copy of current

        while(currentCopy != nullptr) { // copy entire list
            current = new Node(currentCopy->getValue()); // deep copy
            currentCopy = currentCopy->getNext(); // next node in copy
            current = current->getNext(); // next node in original
        }
    }
}

// copy assignment operator
LinkedList& LinkedList::operator = (const LinkedList &copyLinkedList) {
    cout << "Copy assignment operator called." << endl;

    LinkedList temp(copyLinkedList);
    swap(temp.head, head);
    return *this;
}

// add item to list
void LinkedList::append(int item){
    if (head == nullptr) { // the case that the list is empty
        head = new Node(item); // head points to first node containing item
    }
    else { // the case that the list is not empty
        current = head; // current point to first node

        while(current->getNext() != nullptr) { // find the last node
            current = current->getNext(); // current point to next node
        }
        current->setNext(new Node(item)); // item appended to the end of the list
    }
}

/*
// remove item from list - do not need this member function anymore
void LinkedList::remove(int item){
    Node* current = head; // current point to first node

    // the case that the list is empty
    if (head == nullptr) {
        return;
    }

    if (head->getValue() == item) { // the case that the item is in the first node
        head = head->getNext(); // head points to second node
        current = nullptr;
        delete current;
        return;
    }

    // the case that the item is in the list but not in the first node
    Node* previous = head; // previous points to the first node
    current = head->getNext(); // current points to the second node

    while (current != nullptr) {
        if(current->getValue() == item) {
            previous->setNext(current->getNext()); // previous points to next next node
            current->setNext(nullptr); // disconnect node
            delete current; // delete node
            return;
        }
        current = current->getNext();
        previous = previous->getNext();
    }

    // the case that item is not in the list
    return;
} */

void LinkedList::print() {
    current = head;
    while (current != nullptr) {
        cout << current->getValue() << " ";
        current = current -> getNext();
    }
    cout << endl;
}


void LinkedList::insertionSort(){
    Node* sorted = head;

    // outerloop keeps track of sorted portion of the list
    while(sorted != nullptr) {
        Node* outerNext = sorted->next;
        if (outerNext->value < sorted->value) {
            int item = outerNext->value;
            current = head;
            if (head->value == item) { // the case that the item is in the first node
                head = head->next; // head points to second node
                current = nullptr;
                delete current;
            }
            Node* previous = head; // previous points to the first node
            current = previous->next; // current points to the second node
            while (current != nullptr) {
                if(current->value == item) {
                    previous->next = current->next; // previous points to next next node
                    current->next = nullptr; // disconnect node
                    delete current; // delete node
                }
                current = current->next;
                previous = previous->next;
            }

            previous = head->next;
            Node* innerCurrent = previous->next;

            // inner loop inserts the removed node in the sorted portion of the list and increments the sorted pointer
            while(innerCurrent != sorted) {
                if(head->value > item) { // item is new head
                    Node* newHead = new Node(item, head);
                    head = newHead;
                }
                else if(innerCurrent->value >= item) {
                    Node* newNode = new Node(item, innerCurrent);
                    previous->next = nullptr;
                    previous->next = newNode;
                }
                innerCurrent = innerCurrent->next;
                previous = previous->next;
            }
        }
        sorted = sorted->next;
        outerNext = outerNext->next;
    }
}





