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
// Default constructor
UnsortedList::UnsortedList(){
    head = nullptr;
    cursor = nullptr;
    length = 0;
}

// Parameterized constructor
UnsortedList::UnsortedList(int item, ListNode* itemNext = nullptr) {
    // Create the first node in the list with the specified value
    head = new ListNode(item);

    // Set the 'next' pointer of the new node to itemNext
    head->next = itemNext;

    // Set cursor to head since this is the only node for now
    cursor = head;

    // Set the length of the list to 1
    length = 1;
}

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

// Destructor
UnsortedList::~UnsortedList(){}

/**********************************************************************
*                              Methods                                *
**********************************************************************/

// Resets the the cursor
void UnsortedList::resetList(){
    cursor = head;
}

// Resets the list
void UnsortedList::clearList(){

}

// Advances the cursor to the next node in the list
void UnsortedList::advanceList(){
    cursor = cursor->next;
}

// Returns the current number of elements in the list
int UnsortedList::getLength() const{
    return length;
}

// Inserts an item at the current position in the list
void UnsortedList::insertItem(int item){

}

// Inserts an item at the beginning of the list
void UnsortedList::insertFirst(int item) {
    ListNode* newNode = new ListNode(item, head);  // Create a new node with 'item' as value, pointing to the current head
    head = newNode;  // Update head to the new node
    cursor = head;   // Set cursor to the beginning of the list
    length++;        // Increment the length of the list
}

// Removes the first occurrence of the given item from the list
void UnsortedList::removeItem(int item){

}

// Searches for an item in the list and positions the cursor at its location
bool UnsortedList::searchItem(int item){
    int curItem;
    bool found = false;
    cursor = head;

    while(!found && cursor != nullptr){
        curItem = cursor->val;
        if(curItem == item) found = true;

        cursor = cursor->next;
    }
    return found;
}

// Removes the item at the current cursor position
void UnsortedList::removeCurrentItem(){

}

// Updates the value of the current item to the provided value
void UnsortedList::updateCurrentItem(int item){

}

// Returns the value of the current item
int UnsortedList::getCurrentItem(){
    int item = -1;

    //check if at end of list
    if(cursor==nullptr) cout << "Error at end of list" << endl;
    else item = cursor->val;
    
    return item;
}

// Sets the passed item by reference to the value of the current item
void UnsortedList::getCurrentItem(int& item){

}

// Prints all the elements in the list to the console
void UnsortedList::printList() const{
    ListNode* current = head;  // Start from the head of the list
    while (current != nullptr) {
        cout << current->val << " ";  // Print the value of the current node
        current = current->next;  // Move to the next node
    }
    cout << endl;  // End the line after printing all elements
}

/**********************************************************************
*                             Predicates                              *
**********************************************************************/

// Checks if the list is empty
bool UnsortedList::isEmpty() const{
    return head==nullptr;
}

// Checks if the cursor is at the end of the list
bool UnsortedList::atEnd() const{
    return cursor==nullptr;
}