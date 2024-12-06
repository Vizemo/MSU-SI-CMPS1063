#include <iostream>
using namespace std;

class StackType {
private:
    int top;                        // Index of the top of the stack
    static const int stackSize = 5; // Fixed stack size
    int stackArray[stackSize];      // Fixed-size array for the stack

public:
    // Constructor
    StackType() {
        top = -1; // Indicates an empty stack
        makeEmpty(); // Initialize all indices to -1
    }

    // Make the stack empty
    void makeEmpty() {
        top = -1; // Reset the top index
        for (int i = 0; i < stackSize; i++) {
            stackArray[i] = -1; // Set all indices to -1
        }
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() const {
        return top == stackSize - 1;
    }

    // Push an item onto the stack
    void push(int newItem) {
        if (isFull()) {
            cout << "Error: Stack Overflow" << endl;
        }
        else {
            top++;
            stackArray[top] = newItem;
        }
    }

    // Pop an item off the stack
    void pop(int& item) {
        if (isEmpty()) {
            cout << "Error: Stack Underflow" << endl;
        }
        else {
            item = stackArray[top];
            stackArray[top] = -1; // Reset the position to -1
            top--;
        }
    }

    // Peek at the top item
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stackArray[top];
    }

    // Display the stack
    void display() const {
        cout << "Stack contents: ";
        for (int i = 0; i < stackSize; i++) {
            if (stackArray[i] != -1) {
                cout << stackArray[i] << " ";
            }
            else {
                cout << "-1 ";
            }
        }
        cout << endl;
    }
};

// Main function to test the stack
int main() {
    StackType stack; // Create a stack with fixed size

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display(); // Display the stack

    stack.makeEmpty(); // Empty the stack and reset indices
    cout << "Stack after makeEmpty(): ";
    stack.display(); // Display the stack after reset

    return 0;
}
