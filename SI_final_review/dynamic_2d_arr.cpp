#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Input the size of the array
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Dynamically allocate a 2D array
    int** array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }

    // Initialize the array
    cout << "Initializing the array with values (row * col):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = i * j;
        }
    }

    // Display the array
    cout << "The 2D array is:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate the 2D array
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;

    cout << "Memory deallocated successfully." << endl;

    return 0;
}