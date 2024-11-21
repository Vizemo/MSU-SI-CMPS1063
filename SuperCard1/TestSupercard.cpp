//Catherine Stringfellow and ????
//
//

#include<iostream>
#include<fstream>
#include <string>
#include "Supercard.h"
using namespace std;

//Purpose: Introduces the program.
//Requires: Outfile.
void printHeading(ofstream &outfile);

//Purpose: Prints message (string) as label and the supercard.
//Requires: A Supercard and outfile.
void printSuperCard(ofstream & outfile, string message, Supercard & S);

//Purpose: Prints message (string) as label and the digits of supercard.
//Requires: A Supercard and outfile.
void printDigits(ofstream& outfile,  Supercard& S, int pos);

//Purpose: Set S1 to the 10s complement of S2
//Requires: Two Supercards S1 and S2
void tensComplement(Supercard & S1, Supercard & S2);

//Purpose: Sets result to sum of S1 and S2
//Requires: Three supercards  S1, S2, and S3
void addSupercards(Supercard & S1, Supercard & S2, Supercard & result);

//Purpose: Opens file to be written to.
void openFiles(ofstream &outfile);

void printEndMessage(ofstream & outfile);
//Purpose: Thanks the user for running SuperCard Program.
//Requires: outfile.

int main()
{
	Supercard S1, S2, S3;
	ofstream outfile;

	openFiles(outfile);
	printHeading(outfile);

	//test SetDigit and initialize S1
	outfile << "Initialize S1\n";
	for (int i = 1; i <= 9; i++)
		S1.setDigit(i, i);
	for (int i = 10; i <= 14; i++)
		S1.setDigit(i, 0);

	//test length
	outfile << "The length of S1 is " << S1.getLength() << endl;

	//output value of S1
	printSuperCard(outfile, "S1 = ", S1);

	//swap S1 and S2 and print S2
	outfile << "Swap S1 and s2" << endl;
	S1.swap(S2);
	printSuperCard(outfile, "S2 = ", S2);

	//clear S2 and reset it to 987654321 and ouput value of S2
	outfile << "Reset S2 to 987654321\n";
	S2.clear();
	for (int i = 1; i <= 9; i++)
		S2.setDigit(i, i);
	printSuperCard(outfile, "S2 = ", S2);

	//test get digit and compute 10's complement of S2
	outfile << "Let S1 be the 10's complement of S2\n";
	tensComplement(S1, S2);
	//output the new value of S1
	printSuperCard(outfile, "S1 = ", S1);

	//add S1 and S2, store in S3 and print it
	addSupercards(S1, S2, S3);
	printSuperCard(outfile, "Sum of S1 and S2 is ", S3);

	//test destructor
	outfile << "Getting ready to destruct S1 and S2.\n";

	printEndMessage(outfile);

	return 0;
}

void openFiles(ofstream &outfile)
{
	//opens file to be written to.
	outfile.open("SCOut.txt");
}

void printHeading(ofstream & outfile)
{
	outfile << "Catherine Stringfellow" << endl
		<< "Program 5: Program will process big numbers." << endl << endl;
}
void printEndMessage(ofstream & outfile)
{
	outfile << "Thank you for using the SuperCard Program. \n\n";
	outfile << "If your program does not crash - destructor worked.\n\n";
	outfile << "Goodbye." << endl;
}

void printSuperCard(ofstream& outfile, string message, Supercard& S) {
	//print the message
	outfile << message;

	//reset the cursor
	S.moveIndex(1);

	//call the function printDigits below
	printDigits(outfile, S, S.getLength());
	
	//add a newline at the end
	outfile << endl;
}

// This is a recursive function to print the digits in reverse
void printDigits(ofstream& outfile, Supercard& S, int pos) {
	//base case: If pos is less than 1, stop recursion
	if (pos < 1) {
		return;
	}

	//print the digit at the current position
	outfile << S.getDigit(pos);

	//recursive call to print the previous digit
	printDigits(outfile, S, pos - 1);
}


void tensComplement(Supercard & S1, Supercard & S2)
{
	//clear S1
	S1.clear();
	
	//set each digit of S1 to 10 - the corresponding digit in S2
	for (int i = 1; i <= S2.getLength(); i++) {
		int digit = 10 - S2.getDigit(i);
		S1.setDigit(i, digit);
	}
}

void addSupercards(Supercard & S1, Supercard & S2, Supercard & result)
{
	//clear result
	result.clear();

	//declare variables needed
	int carry = 0, pos = 1;

	//while more digits in either S1 or S2, keep adding digits
	while (pos <= S1.getLength() || pos <= S2.getLength()) {
		//get digit from S1, if none set digit to 0
		int digit1 = (pos <= S1.getLength()) ? S1.getDigit(pos) : 0;

		//get digit from S2, if none set digit to 0
		int digit2 = (pos <= S2.getLength()) ? S2.getDigit(pos) : 0;

		//sum digits and compute carry 
		int sum = digit1 + digit2 + carry;
		carry = sum / 10;

		//set sum to just the one's digit
		sum = sum % 10;

		//set the proper digit in result
		result.setDigit(pos, sum);

		//update pos
		pos++;
	}

	//take care of last carry if 1
	if (carry > 0) {
		result.setDigit(pos, carry);
	}
}