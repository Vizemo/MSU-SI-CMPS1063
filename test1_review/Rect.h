#pragma once  // Ensures the header is included only once during compilation

// Definition of the Rect class
class Rect {
private:
    int length;  // The length of the rectangle
    int width;   // The width of the rectangle

public:
    // Default constructor
    Rect();

    // Parameterized constructor
    Rect(int l, int w);

    // Destructor
    ~Rect();

    // Setter for the length
    void setLength(int s2);

    // Setter for the width
    void setWidth(int s);

    // Getter for the length
    const int getLength();

    // Getter for the width
    const int getWidth();

    // Function to calculate the area of the rectangle
    int findArea();
};