//Catherine Stringfellow and ???
//

#include<iostream>
#include "Supercard.h"
using namespace std;

//like UnsortedList constructor, just put one node in it
Supercard::Supercard ( )  //like UnsortedList constructor, just put one node in it
{   
    //insert a new node with 0 in it
	head = new Node(0);

	//initialize other 3 member data
	cursor = head;
	length = 1;
	currentIndex = 1;
}

//like UnsortedList copy constructor, except you need copy value of current index
Supercard::Supercard(Supercard& other)
{
	//copy length and current index from other supercard
	length = other.length;
	currentIndex = other.currentIndex;

	//reset cursor of other supercard
	other.moveIndex(1);

	//initialize this supercard as empty
	head = nullptr;
	cursor = nullptr;
	Node* temp = other.head; //temporary pointer to traverse the other supercard

	// while more nodes
	while (temp != nullptr) {
		//get node value from the other supercard
		int value = temp->item;

		//create a new node with that value
		if (head == nullptr) {
			head = new Node(value); // First node
			cursor = head;
		}
		//insert it in the current position
		else {
			cursor->next = new Node(value);
			cursor = cursor->next;
		}

		//move to the next node in the other supercard
		temp = temp->next;
	}

	//reset both cursors
	cursor = head;
	other.moveIndex(1);
}

//like ~UnsortedList but you'll insert a node with 0 in it and update length and currentIndex
void Supercard::clear ( )
{   	
	//declare a temp Node pointer 
	Node* temp;

	//reset cursor 
	cursor = head;
	//while more nodes get rid of them
	while (cursor != nullptr) {
		temp = cursor;
		cursor = cursor->next;
		delete temp;
	}

	//insert a node with 0 in it 
	head = new Node(0);

	//update other member data
	cursor = head;
	length = 1;
	currentIndex = 1;
}

Supercard::~Supercard()
{
	//clear the list of ALL nodes - deallocate them
	clear();
}

//Swap supercards
void Supercard::swap(Supercard & other)
{
	//declare temp variables
	int temp;
	Node* tempptr;

	//swap lengths
	temp = length;
	length = other.length;
	other.length = temp;

	//swap index
	temp = currentIndex;
	currentIndex = other.currentIndex;
	other.currentIndex = temp;

	//swap heads
	tempptr = head;
	head = other.head;
	other.head = tempptr;

	//swap cursors
	tempptr = cursor;
	cursor = other.cursor;
	other.cursor = tempptr;
}

int Supercard::getLength ( ) const
{  
	return length;
}

//like UnsortedList advance method, except you also have to change index
void Supercard::moveIndex(int pos)
{
	//write error message if pos illegal
	if (pos < 1 || pos > length) {
		cout << "Error: Position out of bounds.\n";
		return;
	}

	//else pos legal
	else {
		//reset cursor and index
		cursor = head;
		currentIndex = 1;
		// while not in correct position, move index forward
		while (currentIndex < pos) {
			cursor = cursor->next;
			currentIndex++;
		}
	}	
}

//NOT like UnsortedList insert or insertFirst, you need to insert at end, or update
void Supercard::setDigit(int pos, int d) {
	// Declare a temporary pointer
	Node* temp;

	// Write error message if position is illegal
	if (pos < 1 || pos > length + 1) {
		cout << "Error: Position out of bounds.\n";
		return;
	}

	// Else if position is legal
	else {
		// Check if inserting a new digit at the end of the list
		if (pos == length + 1) {
			// Move index to pos right before the digit
			moveIndex(length);

			// Get a new node and update pointers
			temp = new Node(d); // Create a new node with the digit
			cursor->next = temp; // Link the new node to the list

			// Update any other index and cursor
			length++; // Increase the length of the Supercard
		}

		// Else update an old digit
		else {
			// Reset cursor and index
			moveIndex(pos); // Move to the specified position

			// Move index to pos
			cursor->item = d; // Update the digit at the current node
		}
	}
}

//like UnsortedList getCurrentItem, except you need to get to the correct node first
int Supercard::getDigit (int pos)
{
	int d = -1;  // in case pos not legal

	//write error message if pos illegal
	if (pos < 1 || pos > length) {
		cout << "Error: Position out of bounds.\n";
		return d;
	}
    //else pos legal
	else {
		//reset index and cursor
		cursor = head;
		currentIndex = 1;

		//loop to move index and cursor to correct position
		while (currentIndex < pos) {
			cursor = cursor->next;
			currentIndex++;
		}

		//get digit in current node
		d = cursor->item;
	}
	
	//return digit
	return d;
}