#include <iostream>
using namespace std;

int main() {
    int size;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    // Dynamically allocate a 1D array
    int* array = new int[size];

    // Initialize the array
    cout << "Initializing the array with values (index * 2):\n";
    for (int i = 0; i < size; i++) {
        array[i] = i * 2; // Example initialization
    }

    // Display the array
    cout << "The 1D array is:\n";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Deallocate the 1D array
    delete[] array;

    cout << "Memory deallocated successfully." << endl;

    return 0;
}