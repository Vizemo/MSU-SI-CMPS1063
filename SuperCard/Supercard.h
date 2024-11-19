#pragma once
#include <iostream>
using namespace std;

//File : Supercard.h
//This file describes the class Supercard - an unordered sequence of integer 
//digits used to store big numbers
//Catherine Stringfellow

class Supercard {
private:
    //Node is a helper class to store data in a node
    class Node {
        friend Supercard; //Needed so Supercard can access default private data
        int item;
        Node* next;

        //constructor for a node, if last arg is missing, set it to NULL
        Node(int item1, Node* next1 = nullptr) : item(item1), next(next1) {}
    };

    //Data for a Supercard
    int length;
    int currentIndex;
    Node* cursor;
    Node* head;

public:
    //create a supercard with the value of 0 (a linked list with one node containing 0)
    Supercard();

    //create a supercard by copying the other supercard
    Supercard(Supercard& other);

    //Purpose: reset the supercard to just the digit 0
    void clear();

    //Destruct the supercard and return all allocated data to memory
    ~Supercard();

    //Swap this Supercard with other
    void swap(Supercard& other);

    //Returns: the number of digits in the Supercard
    int getLength() const;

    //Purpose: Moves the current index to the digit at position pos (0-based index),
    //if it exists
    //Requires/Checks:  0 <= pos < length
    void moveIndex(int pos);

    //Returns: Returns the digit at position pos (0-based index).
    //Requires/Checks:  0 <= pos < length
    int getDigit(int pos);

    //Purpose: Inserts the digit d in the supercard in the proper position.
    //If pos is equal to the length, it appends the digit.
    //Requires:  0 <= pos <= length
    void setDigit(int pos, int d);
};
