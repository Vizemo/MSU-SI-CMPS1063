#include "Rect.h"

// Constructor definition
Rect::Rect() {
    length = 1;
    width = 2;
}

Rect::Rect(int l, int w) {
    length = l;
    width = w;
}

Rect::~Rect() {}

// Function to set the length
void Rect::setLength(int s2) {
    length = s2;
}

// Function to set the width
void Rect::setWidth(int s) {
    width = s;
}

// Function to get the length
const int Rect::getLength() {
    return length;
}

// Function to get the width
const int Rect::getWidth() {
    return width;
}

// Function to find the area
int Rect::findArea() {
    return length * width;
}