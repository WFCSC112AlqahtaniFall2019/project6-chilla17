#include <iostream>
#include <vector>
#include "BinaryInsertionSort.h"
#include "LinkedList.h"
#include "Node.h"
using namespace std;

int main() {

    cout << "Input seed and length (length should be greater than 1 to sort)" << endl;
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);
    LinkedList list; // create list

    // generate vector of random integers
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
        list.append(v[i]); // generate linked list with same values in the same order
    }

    // binary insertion sort
    insertionSort(v, v.size());

    // check if sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v[i-1] <= v[i]);
    }

    cout << "Print Binary Insertion Sort" << endl;
    // print out sorted list
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // FINISH ME
    cout << "Linked list before sort: " << endl;
    list.print();

    list.insertionSort();

    cout<< "Linked list after sort: " << endl;
    list.print();

}