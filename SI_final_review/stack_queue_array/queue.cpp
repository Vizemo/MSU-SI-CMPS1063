#include <iostream>
using namespace std;

class QueueType {
private:
    static const int queueSize = 5; // Fixed queue size
    int queueArray[queueSize];      // Fixed-size array for the queue
    int front;                      // Index of the front of the queue
    int rear;                       // Index of the rear of the queue
    int itemCount;                  // Number of items in the queue

public:
    // Constructor
    QueueType() {
        front = 0;
        rear = -1;
        itemCount = 0;
        makeEmpty(); // Initialize all indices to -1
    }

    // Make the queue empty
    void makeEmpty() {
        front = 0;
        rear = -1;
        itemCount = 0;
        for (int i = 0; i < queueSize; i++) {
            queueArray[i] = -1; // Set all indices to -1
        }
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return itemCount == 0;
    }

    // Check if the queue is full
    bool isFull() const {
        return itemCount == queueSize;
    }

    // Enqueue an item into the queue
    void enqueue(int newItem) {
        if (isFull()) {
            cout << "Error: Queue Overflow" << endl;
        }
        else {
            rear = (rear + 1) % queueSize; // Circular increment
            queueArray[rear] = newItem;
            itemCount++;
        }
    }

    // Dequeue an item from the queue
    void dequeue(int& item) {
        if (isEmpty()) {
            cout << "Error: Queue Underflow" << endl;
        }
        else {
            item = queueArray[front];
            queueArray[front] = -1; // Reset the position to -1
            front = (front + 1) % queueSize; // Circular increment
            itemCount--;
        }
    }

    // Peek at the front item
    int peekFront() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queueArray[front];
    }

    // Display the queue
    void display() const {
        cout << "Queue contents: ";
        for (int i = 0; i < queueSize; i++) {
            if (queueArray[i] != -1) {
                cout << queueArray[i] << " ";
            }
            else {
                cout << "-1 ";
            }
        }
        cout << endl;
    }
};

// Main function to test the queue
int main() {
    QueueType queue; // Create a queue with fixed size

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display(); // Display the queue

    queue.makeEmpty(); // Empty the queue and reset indices
    cout << "Queue after makeEmpty(): ";
    queue.display(); // Display the queue after reset

    return 0;
}
