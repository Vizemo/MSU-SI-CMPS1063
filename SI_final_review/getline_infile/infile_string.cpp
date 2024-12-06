#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("in_string.txt");

    string word;
    cout << "Reading words from the file:\n";

    while (infile >> word) { // Reads one word at a time
        cout << word << endl;
    }

    infile.close();
    return 0;
}