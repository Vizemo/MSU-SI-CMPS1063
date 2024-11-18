// Catherine Stringfellow and ????
//
//
//

#include <iostream>
#include <fstream>
#include <string>
#include "Supercard.h"
using namespace std;

// Purpose: Introduces the program.
// Requires: Outfile.
void printHeading(ofstream& outfile);

// Purpose: Prints message (string) as label and the supercard.
// Requires: A Supercard and outfile.
void printSuperCard(ofstream& outfile, string message, Supercard& S);

// Purpose: Prints message (string) as label and the digits of supercard.
// Requires: A Supercard and outfile.
void printDigits(ofstream& outfile, Supercard& S, int pos = 1);

// Purpose: Set S1 to the 10s complement of S2
// Requires: Two Supercards S1 and S2
void tensComplement(Supercard& S1, Supercard& S2);

// Purpose: Sets result to sum of S1 and S2
// Requires: Three supercards  S1, S2, and S3
void addSupercards(Supercard& S1, Supercard& S2, Supercard& result);

// Purpose: Opens file to be written to.
void openFiles(ofstream& outfile);

void printEndMessage(ofstream& outfile);
// Purpose: Thanks the user for running SuperCard Program.
// Requires: outfile.

int main() {
    Supercard S1, S2, S3;
    ofstream outfile;

    openFiles(outfile);
    printHeading(outfile);

    // Test SetDigit and initialize S1
    outfile << "Initialize S1\n";
    for (int i = 1; i <= 9; i++)
        S1.setDigit(i, i);
    for (int i = 10; i <= 14; i++)
        S1.setDigit(i, 0);

    // Test length
    outfile << "The length of S1 is " << S1.getLength() << endl;

    // Output value of S1
    printSuperCard(outfile, "S1 = ", S1);

    // Swap S1 and S2 and print S2
    outfile << "Swap S1 and S2\n";
    S1.swap(S2);
    printSuperCard(outfile, "S2 = ", S2);

    // Clear S2 and reset it to 987654321 and output value of S2
    outfile << "Reset S2 to 987654321\n";
    S2.clear();
    for (int i = 1; i <= 9; i++)
        S2.setDigit(i, i);
    printSuperCard(outfile, "S2 = ", S2);

    // Test getDigit and compute 10's complement of S2
    outfile << "Let S1 be the 10's complement of S2\n";
    tensComplement(S1, S2);
    // Output the new value of S1
    printSuperCard(outfile, "S1 = ", S1);

    // Add S1 and S2, store in S3 and print it
    addSupercards(S1, S2, S3);
    printSuperCard(outfile, "Sum of S1 and S2 is ", S3);

    // Test destructor
    outfile << "Getting ready to destruct S1 and S2.\n";

    printEndMessage(outfile);

    return 0;
}

void openFiles(ofstream& outfile) {
    // Opens file to be written to.
    outfile.open("SCOut.txt");
}

void printHeading(ofstream& outfile) {
    outfile << "Catherine Stringfellow" << endl
        << "Program 5: Program will process big numbers." << endl << endl;
}

void printEndMessage(ofstream& outfile) {
    outfile << "Thank you for using the SuperCard Program. \n\n";
    outfile << "If your program does not crash - destructor worked.\n\n";
    outfile << "Goodbye." << endl;
}

// Print the Supercard with a message label
void printSuperCard(ofstream& outfile, string message, Supercard& S) {
    outfile << message;
    printDigits(outfile, S); // Start recursion from position 1
    outfile << endl;
}

// Recursive function to print the digits of a Supercard in reverse order
void printDigits(ofstream& outfile, Supercard& S, int pos) {
    if (pos > S.getLength()) return; // Base case: stop if position exceeds length

    // Recursive case: move to the next position
    printDigits(outfile, S, pos + 1);

    // Print the current digit
    outfile << S.getDigit(pos);
}

// Compute the 10's complement of S2 and store in S1
void tensComplement(Supercard& S1, Supercard& S2) {
    S1.clear(); // Clear S1
    for (int i = 1; i <= S2.getLength(); i++) {
        int digit = S2.getDigit(i);
        S1.setDigit(i, 10 - digit); // Compute 10's complement for each digit
    }
}

// Add two Supercards and store the result in a third Supercard
void addSupercards(Supercard& S1, Supercard& S2, Supercard& result) {
    result.clear(); // Clear the result Supercard
    int carry = 0;  // Initialize carry to 0
    int maxLength = max(S1.getLength(), S2.getLength());

    for (int i = 1; i <= maxLength; i++) {
        int digit1 = (i <= S1.getLength()) ? S1.getDigit(i) : 0; // Get digit from S1
        int digit2 = (i <= S2.getLength()) ? S2.getDigit(i) : 0; // Get digit from S2

        int sum = digit1 + digit2 + carry; // Add digits and carry
        carry = sum / 10;                  // Compute carry
        result.setDigit(i, sum % 10);      // Store the result digit
    }

    if (carry) result.setDigit(maxLength + 1, carry); // Add the last carry if exists
}