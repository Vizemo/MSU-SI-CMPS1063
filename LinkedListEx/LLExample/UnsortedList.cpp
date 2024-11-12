/********OPTIONAL************OPTIONAL*************OPTIONAL*************
Link to learn more about Deep vs Shallow copy constructors:
https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/#
*********OPTIONAL************OPTIONAL*************OPTIONAL************/

#include "UnsortedList.h"
#include <iostream>
#include <fstream>

using namespace std;

/**********************************************************************
*                            Constructors                             *
**********************************************************************/

// Purpose:  Deep copy constructor to create a new list as a copy of an 
//           existing list
// Receives: UnsortedList& other
// Returns:  Nothing (constructor)
UnsortedList::UnsortedList(UnsortedList& other) {
    // Initialize an empty list
    head = nullptr;
    cursor = nullptr;
    length = 0;

    // Proceed only if the source list has nodes
    if (other.head != nullptr) {
        // Copy the first node to initialize the new list's head
        head = new ListNode(other.head->val);

        // Pointer to traverse and build the new list
        ListNode* current = head;

        // Pointer to traverse the source list
        ListNode* otherCurrent = other.head->next;

        // Copy the rest of the source list
        while (otherCurrent != nullptr) {
            // Create a new node with the value from the source list and
            // link it
            current->next = new ListNode(otherCurrent->val);

            // Move to the new node
            current = current->next;

            // Move to the next node in the source list
            otherCurrent = otherCurrent->next;
        }

        // Initialize the cursor to the start of the new list
        cursor = head;
        // Copy the length from the source list
        length = other.length;
    }
}