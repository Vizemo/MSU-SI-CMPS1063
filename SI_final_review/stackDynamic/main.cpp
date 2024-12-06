#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack stack;  // Create a stack using linked list

    cout << "Pushing elements onto the stack...\n";
    for (int i = 1; i <= 5; i++) {
        cout << "Pushing " << i << endl;
        stack.push(i);
    }

    cout << "\nPeeking top element: " << stack.peek() << endl;

    cout << "\nPopping elements from the stack...\n";
    while (!stack.isEmpty()) {
        cout << "Popped: " << stack.pop() << endl;
    }

    cout << "\nTrying to pop from an empty stack...\n";
    stack.pop();

    cout << "\nPushing elements again after clearing the stack...\n";
    stack.push(10);
    stack.push(20);

    cout << "Peeking top element: " << stack.peek() << endl;

    cout << "\nClearing the stack...\n";
    stack.deleteStack();

    return 0;
}

/*Instructions to run in visual studio with g++
Path to folder in terminal

to compile the files
g++ main.cpp Stack.cpp -o stack

to run main.cpp
./stack
*/