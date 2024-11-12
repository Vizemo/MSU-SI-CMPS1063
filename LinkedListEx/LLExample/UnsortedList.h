/********OPTIONAL************OPTIONAL*************OPTIONAL*************
Link to learn more about Deep vs Shallow copy constructors:
https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/#
*********OPTIONAL************OPTIONAL*************OPTIONAL************/

#pragma once

class UnsortedList {
private:
    struct ListNode {
        int val; // Value stored in the node
        ListNode* next; // Pointer to the next node

        // Constructor to initialize the node
        ListNode(int x, ListNode* nextF = nullptr) {
            val = x;
            next = nextF;
        }
        // OPTIONAL: Same constructor as above with initialization syntax
        //ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode* head; // Pointer to the first node in the list
    ListNode* cursor; // Pointer used to traverse the list
    int length; // Number of elements in the list

public:
    /**********************************************************************
    *                            Constructors                             *
    **********************************************************************/

    UnsortedList(); // Default constructor

    UnsortedList(int item, ListNode *itemNext = nullptr); // Parameterized constructor

    UnsortedList(UnsortedList& other); // Deep copy constructor

    ~UnsortedList(); // Destructor

    /**********************************************************************
    *                              Methods                                *
    **********************************************************************/

    // Resets the list to have nothing in it
    void resetList();

    // Resets the list to have nothing in it
    void clearList();

    // Advances the cursor to the next node in the list
    void advanceList();

    // Returns the current number of elements in the list
    int getLength() const;

    // Inserts an item at the current position in the list
    void insertItem(int item);

    // Inserts an item at the beginning of the list
    void insertFirst(int item);

    // Removes the first occurrence of the given item from the list
    void removeItem(int item);

    // Searches for an item in the list and positions the cursor at its location
    bool searchItem(int item);

    // Removes the item at the current cursor position
    void removeCurrentItem();

    // Updates the value of the current item to the provided value
    void updateCurrentItem(int item);

    // Returns the value of the current item
    int getCurrentItem();

    // Sets the passed item by reference to the value of the current item
    void getCurrentItem(int& item);

    // Prints all the elements in the list to the console
    void printList() const;

    /**********************************************************************
    *                             Predicates                              *
    **********************************************************************/

    // Checks if the list is empty
    bool isEmpty() const;

    // Checks if the cursor is at the end of the list
    bool atEnd() const;
};