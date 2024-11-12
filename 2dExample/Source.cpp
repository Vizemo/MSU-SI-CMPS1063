#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int row, col;

	cout << "Enter num of rows: ";
	cin >> row;

	cout << "Enter num of cols: ";
	cin >> col;

	// creates a 2d array dynamically
	char** grid = new char* [row];

	for (int i = 0; i < row; i++) {
		grid[i] = new char[col];
	}


	grid[0][0] = 'A';


	// deallocates the 2d array to free up memory
	for (int i = 0; i < row; i++) {
		delete[] grid[i];
	}
	delete[] grid;

	return 0;
}