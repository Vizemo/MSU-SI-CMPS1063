#include <iostream>
#include <fstream>
#include <iomanip> // For formatting
#include "Robot.h"

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

/* Purpose: Reads the robot's initial X and Y positions from user input
 Receives: int& x - reference to the robot's X position
           int& y - reference to the robot's Y position
 Returns : Nothing */
void readRobotPositionXY(int& x, int& y); 

int main() {
    ifstream fin;
    ofstream fout;

    // Open files
    openFiles(fin, fout);

    // Write heading to output file
    heading(fout);

    // Initialize robot position of x, y
    int robotX = 0, robotY = 0;
  
    readRobotPositionXY(robotX, robotY);

    // Create the robot
    Robot robot(robotX, robotY);

    // Print robot's position
    robot.printPosition(fout);

    // Load individual rocks
    Rock rock1 = robot.loadRock(fin, 1);
    Rock rock2 = robot.loadRock(fin, 2);
    Rock rock3 = robot.loadRock(fin, 3);

    // Sort the rocks by distance
    robot.sortRocks(rock1, rock2, rock3);

    // Print rock data header
    robot.printRockHeader(fout);

    // Process each rock and output to file
    robot.processRock(rock1, fout);
    robot.processRock(rock2, fout);
    robot.processRock(rock3, fout);

    // Print the final robot status
    robot.printStatus(fout);

    // Close files
    fin.close();
    fout.close();

    return 0;
}

void openFiles(ifstream& infile, ofstream& outfile) {
    string inputFileName, outputFileName;

    cout << "Enter the input file name: ";
    cin >> inputFileName;
    infile.open(inputFileName); // Open input file

    cout << "Enter the output file name: ";
    cin >> outputFileName;
    outfile.open(outputFileName); // Open output file
}

void heading(ofstream& fout) {
    fout << "Victor Marchesi\n";
    fout << "SI CMPS 1063 Program 2\n" << endl;
}

void readRobotPositionXY(int& x, int& y) {
    cout << "Enter the robot's initial X position and hit enter: ";
    cin >> x;
    cout << "Enter the robot's initial Y position and hit enter: ";
    cin >> y;
}