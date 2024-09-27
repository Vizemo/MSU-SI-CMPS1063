#include <iostream>
#include <fstream>
#include <iomanip>
#include "Rock.h"

using namespace std;

/* Purpose: Opens input and output files based on user - provided filenames
   Receives: ifstream& infile - reference to input file stream
           ofstream& outfile - reference to output file stream
   Returns : Nothing */
void openFiles(ifstream& infile, ofstream& outfile);

/* Purpose: Writes the program heading to the output file
   Receives: ofstream& fout - reference to the output file stream
   Returns : Nothing */
void heading(ofstream& fout);


int main() {
    ifstream fin;
    ofstream fout;

    openFiles(fin, fout);

    heading(fout);

    Rock rock1;

    Rock rock1


    return 0;
}

void openFiles(ifstream& infile, ofstream& outfile) {
    string inputFileName, outputFileName;

    cout << "Enter the input file name: ";
    cin >> inputFileName;
    infile.open(inputFileName); // Open input file
    //infile.open("in.txt");

    cout << "Enter the output file name: ";
    cin >> outputFileName;
    outfile.open(outputFileName); // Open output file
    //outfile.open("out.txt");
}

void heading(ofstream& fout) {
    fout << "Victor Marchesi\n";
    fout << "SI CMPS 1063 Program 2\n" << endl;
}