#include <iostream>
#include <fstream>
#include <string>
#include "Supercard.h"
using namespace std;

// Purpose: Introduces the program.
void printHeading(ofstream& outfile);

// Purpose: Prints message (string) as label and the supercard.
void printSuperCard(ofstream& outfile, string message, Supercard& S);

// Purpose: Prints message (string) as label and the digits of supercard.
void printDigits(ofstream& outfile, Supercard& S, int pos = 0);

// Purpose: Set S1 to the 10s complement of S2
void tensComplement(Supercard& S1, Supercard& S2);

// Purpose: Sets result to sum of S1 and S2
void addSupercards(Supercard& S1, Supercard& S2, Supercard& result);

// Purpose: Opens file to be written to.
void openFiles(ofstream& outfile);

void printEndMessage(ofstream& outfile);
// Purpose: Thanks the user for running SuperCard Program.

int main() {
    Supercard S1, S2, S3;
    ofstream outfile;

    openFiles(outfile);
    printHeading(outfile);

    outfile << "Initialize S1\n";
    for (int i = 0; i < 9; i++)
        S1.setDigit(i, i + 1);
    for (int i = 9; i < 14; i++)
        S1.setDigit(i, 0);

    outfile << "The length of S1 is " << S1.getLength() << endl;

    printSuperCard(outfile, "S1 = ", S1);

    outfile << "Swap S1 and S2\n";
    S1.swap(S2);
    printSuperCard(outfile, "S2 = ", S2);

    outfile << "Reset S2 to 987654321\n";
    S2.clear();
    for (int i = 0; i < 9; i++)
        S2.setDigit(i, 9 - i);
    printSuperCard(outfile, "S2 = ", S2);

    outfile << "Let S1 be the 10's complement of S2\n";
    tensComplement(S1, S2);
    printSuperCard(outfile, "S1 = ", S1);

    addSupercards(S1, S2, S3);
    printSuperCard(outfile, "Sum of S1 and S2 is ", S3);

    outfile << "Getting ready to destruct S1 and S2.\n";
    printEndMessage(outfile);

    return 0;
}

void openFiles(ofstream& outfile) {
    outfile.open("SCOut.txt");
}

void printHeading(ofstream& outfile) {
    outfile << "Catherine Stringfellow\n"
        << "Program 5: Program will process big numbers.\n\n";
}

void printEndMessage(ofstream& outfile) {
    outfile << "Thank you for using the SuperCard Program.\n\n"
        << "If your program does not crash - destructor worked.\n\n"
        << "Goodbye.\n";
}

void printSuperCard(ofstream& outfile, string message, Supercard& S) {
    outfile << message;
    printDigits(outfile, S);
    outfile << endl;
}

void printDigits(ofstream& outfile, Supercard& S, int pos) {
    if (pos >= S.getLength()) return;

    printDigits(outfile, S, pos + 1);

    outfile << S.getDigit(pos);
}

void tensComplement(Supercard& S1, Supercard& S2) {
    S1.clear();
    for (int i = 0; i < S2.getLength(); i++) {
        int digit = S2.getDigit(i);
        S1.setDigit(i, 10 - digit);
    }
}

void addSupercards(Supercard& S1, Supercard& S2, Supercard& result) {
    result.clear();
    int carry = 0;
    int maxLength = max(S1.getLength(), S2.getLength());

    for (int i = 0; i < maxLength; i++) {
        int digit1 = (i < S1.getLength()) ? S1.getDigit(i) : 0;
        int digit2 = (i < S2.getLength()) ? S2.getDigit(i) : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.setDigit(i, sum % 10);
    }

    if (carry) result.setDigit(maxLength, carry);
}
