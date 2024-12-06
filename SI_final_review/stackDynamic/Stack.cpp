#include "Stack.h"
using namespace std;

// Constructor
Stack::Stack() {
    top = nullptr;  // Initialize top pointer to nullptr
}

// Destructor
Stack::~Stack() {
    deleteStack();  // Clear the stack on destruction
}

// Push an element onto the stack
void Stack::push(int value) {
    Node* newNode = new Node(value);  // Create a new node
    newNode->next = top;             // Link the new node to the current top
    top = newNode;                   // Update the top pointer to the new node
}

// Pop an element from the stack
int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow. Cannot pop!" << endl;
        return -1;
    }

    Node* temp = top;        // Save the current top node
    int value = top->data;   // Retrieve the value
    top = top->next;         // Move top pointer to the next node
    delete temp;             // Free the memory of the popped node
    return value;
}

// Peek at the top element
int Stack::peek() const {
    if (isEmpty()) {
        cout << "Stack is empty. Cannot peek!" << endl;
        return -1;
    }
    return top->data;
}

// Check if the stack is empty
bool Stack::isEmpty() const {
    return top == nullptr;
}

// Clear the stack
void Stack::deleteStack() {
    while (!isEmpty()) {
        pop();  // Pop all elements to free memory
    }
    cout << "Stack has been cleared." << endl;
}