#include <iostream>
#include <fstream>
#include "UnsortedList.h"

using namespace std;

/********OPTIONAL************OPTIONAL*************OPTIONAL*************
Link to learn more about Deep vs Shallow copy constructors:
https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/#
*********OPTIONAL************OPTIONAL*************OPTIONAL************/

int main() {
    /*Below is the hypothetical use of the Deep copy constructor
    since most of the class is not defined, I have commented out
    methods that have not been defined.*/

    // Create an instance of an UnsortedList and add items
    UnsortedList originalList;

    // originalList.insertItem(5);
    // originalList.insertItem(10);
    // originalList.insertItem(15);

    cout << "Original list:" << endl;
    // Print the contents of the original list
    // originalList.printList();

    // Use the copy constructor to create a new list
    UnsortedList copiedList(originalList);

    cout << "Copy of the original list:" << endl;
    // Print the contents of the copied list
    // copiedList.printList();

    return 0;
}