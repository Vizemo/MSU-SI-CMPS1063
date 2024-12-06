#include <iostream>
#include <fstream>

using namespace std;

void reverse(ifstream& infile) {
    char ch;
    if (infile.get(ch)) { // Read a character from the file
        reverse(infile); // Recursive call to process the rest of the file
        cout << ch; // Print the character after the recursive call
    }
}

int main() {
    ifstream infile("example.txt"); // Open the file
    if (!infile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    reverse(infile); // Call the reverse function
    infile.close(); // Close the file

    return 0;
}