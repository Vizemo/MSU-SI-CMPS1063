#include <iostream>
#include "Supercard.h"
using namespace std;

// Default constructor
// Initializes Supercard with one node containing 0
Supercard::Supercard() {
    head = new Node(0);  // Create the initial node
    cursor = head;       // Set cursor to the head
    length = 1;          // Length is 1 because of the initial node
    currentIndex = 0;    // Current index starts at 0
}

// Copy constructor
// Creates a deep copy of the provided Supercard
Supercard::Supercard(Supercard& other) {
    length = other.length;          // Copy the length
    currentIndex = other.currentIndex; // Copy the current index
    head = nullptr;                 // Initialize head to null
    cursor = nullptr;               // Initialize cursor to null

    Node* otherCursor = other.head; // Start copying nodes from other's head
    while (otherCursor) {
        setDigit(length - 1, otherCursor->item); // Add each node to the new Supercard
        otherCursor = otherCursor->next;        // Move to the next node in other
    }
    cursor = head; // Reset cursor to the head of the new Supercard
}

// Destructor
// Clears the linked list and deallocates all nodes
Supercard::~Supercard() {
    clear(); // Use the clear method to remove all nodes
}

// Clears all nodes and resets Supercard to a single node containing 0
void Supercard::clear() {
    Node* temp;
    while (head) {       // Iterate through the linked list
        temp = head;     // Store current node
        head = head->next; // Move head to the next node
        delete temp;     // Delete the current node
    }
    head = new Node(0);  // Reinitialize with a single node containing 0
    cursor = head;       // Reset cursor to the new head
    length = 1;          // Length is now 1
    currentIndex = 0;    // Current index starts at 0
}

// Swaps this Supercard with another Supercard
void Supercard::swap(Supercard& other) {
    Node* tempNode;   // Temporary pointer for swapping nodes
    int tempInt;      // Temporary integer for swapping length and index

    // Swap head pointers
    tempNode = head;
    head = other.head;
    other.head = tempNode;

    // Swap cursor pointers
    tempNode = cursor;
    cursor = other.cursor;
    other.cursor = tempNode;

    // Swap lengths
    tempInt = length;
    length = other.length;
    other.length = tempInt;

    // Swap current indices
    tempInt = currentIndex;
    currentIndex = other.currentIndex;
    other.currentIndex = tempInt;
}

// Returns the number of digits in the Supercard
int Supercard::getLength() const {
    return length;
}

// Moves the cursor to the digit at position 'pos'
void Supercard::moveIndex(int pos) {
    if (pos < 0 || pos >= length) {  // Update bounds for 0-based indexing
        cerr << "Error: Invalid position " << pos << endl;
        return;
    }
    cursor = head;      // Reset cursor to the head
    currentIndex = 0;   // Reset currentIndex to 0
    while (currentIndex < pos) { // Move cursor to the desired position
        cursor = cursor->next;
        currentIndex++;
    }
}

// Retrieves the digit at position 'pos'
int Supercard::getDigit(int pos) {
    int d = -1;
    if (pos < 0 || pos > length) {  // Update bounds for 0-based indexing
        cout << "Error: Invalid position " << pos << endl;
        return d; // Return -1 for invalid position
    }
    moveIndex(pos); 
    int temp// Move cursor to the desired position
    return d = cursor->item; // Return the digit at the current position

}



// Sets the digit at position 'pos' to 'd'
// If 'pos' is one more than the length, appends a new digit
void Supercard::setDigit(int pos, int d) {

    Node* newNode;

    if (pos < 0 || pos > length) { // Update bounds for 0-based indexing
        cerr << "Error: Invalid position " << pos << endl;
        return;
    }
    if (pos == length) { // Append new digit if 'pos' is at the end
        newNode = new Node(d); // Create a new node
        moveIndex(length - 1);       // Move cursor to the last node
        cursor->next = newNode;      // Append the new node
        length++;                    // Increment the length
    }
    else { // Update existing digit
        moveIndex(pos);      // Move cursor to the desired position
        cursor->item = d;    // Update the digit
    }
}
