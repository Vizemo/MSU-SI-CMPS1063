#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;

    cout << "Enter a full line of text: ";
    getline(cin, line); // Reads the entire line, including spaces

    cout << "You entered: " << line << endl;

    return 0;
}