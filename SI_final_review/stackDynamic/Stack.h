#pragma once

#include <iostream>

// Node structure for the stack
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class using linked list
class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    Stack();               // Constructor
    ~Stack();              // Destructor

    void push(int value);  // Push an element onto the stack
    int pop();             // Pop an element from the stack
    int peek() const;      // Peek at the top element
    bool isEmpty() const;  // Check if the stack is empty
    void deleteStack();    // Clear the stack
};