#include <iostream>
#include <fstream>
#include "Rect.h"

using namespace std;

int main() {
	Rect rect1;

	cout << "Length is: " << rect1.getLength() << "\nWidth is: " << rect1.getWidth() << endl;
	cout << "Area is: " << rect1.findArea() << endl << endl;

	int num1 = 10;
	rect1.setLength(num1);
	int num2 = 16;
	rect1.setWidth(num2);

	cout << "Length is: " << rect1.getLength() << "\nWidth is: " << rect1.getWidth() << endl;
	cout << "Area is: " << rect1.findArea() << endl << endl;

	Rect rect2(5, 10);
	cout << "Length is: " << rect2.getLength() << "\nWidth is: " << rect2.getWidth() << endl;
	cout << "Area is: " << rect2.findArea() << endl << endl;

	return 0;
}