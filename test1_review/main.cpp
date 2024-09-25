#include <iostream>   // For standard input and output
#include "Rect.h"     // Including the header file for the Rect class

using namespace std;

int main() {
    // Creating an object of Rect with default constructor
    Rect rect1;

    // Displaying the length and width of the rectangle
    cout << "Length is: " << rect1.getLength() << "\nWidth is: " << rect1.getWidth() << endl;
    // Displaying the area of the rectangle
    cout << "Area is: " << rect1.findArea() << endl << endl;

    // Setting new length and width values for the first rectangle
    int num1 = 10;
    rect1.setLength(num1);
    int num2 = 16;
    rect1.setWidth(num2);

    // Displaying the updated length, width, and area after setting new values
    cout << "Length is: " << rect1.getLength() << "\nWidth is: " << rect1.getWidth() << endl;
    cout << "Area is: " << rect1.findArea() << endl << endl;

    // Creating a second Rect object using parameterized constructor
    Rect rect2(5, 10);
    
    // Displaying the length, width, and area of the second rectangle
    cout << "Length is: " << rect2.getLength() << "\nWidth is: " << rect2.getWidth() << endl;
    cout << "Area is: " << rect2.findArea() << endl << endl;

    return 0;
}