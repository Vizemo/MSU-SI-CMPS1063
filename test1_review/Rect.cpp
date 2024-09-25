#include "Rect.h"

// Default constructor: initializes a rectangle with default length and width
Rect::Rect() {
    length = 1;  // Default length
    width = 2;   // Default width
}

// Parameterized constructor: initializes a rectangle with given length and width
Rect::Rect(int l, int w) {
    length = l;
    width = w;
}

// Destructor: empty, as no dynamic memory or resources need to be released
Rect::~Rect() {}

// Function to set the length of the rectangle
void Rect::setLength(int s2) {
    length = s2;
}

// Function to set the width of the rectangle
void Rect::setWidth(int s) {
    width = s;
}

// Function to get the current length of the rectangle
const int Rect::getLength() {
    return length;
}

// Function to get the current width of the rectangle
const int Rect::getWidth() {
    return width;
}

// Function to calculate and return the area of the rectangle
int Rect::findArea() {
    return length * width;
}