#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("in_ch.txt");

    char ch;
    cout << "Reading characters from the file:\n";

    while (infile >> ch) { // Reads one character at a time
        cout << ch << " ";
    }

    infile.close();
    return 0;
}