#pragma once
#include "Rock.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Robot {
private:
    int x;
    int y;
    int rocksProcessed;
    double totalWeight;

public:
    // Purpose : Default constructor to initialize the robot's position and stats to default values
    // Receives: Nothing
    // Returns : Nothing
    Robot();

    // Purpose : Parameterized constructor to initialize the robot with specific position values
    // Receives: int x, int y - robot's position
    // Returns : Nothing
    Robot(int x, int y);

    // Purpose : Reads and processes a single rock from a file
    // Receives: ifstream& fin - input file stream, int id - rock identifier
    // Returns : Rock object with the loaded data
    Rock loadRock(ifstream& fin, int id);

    // Purpose : Manually sorts three rocks based on their distance from the robot
    // Receives: Rock& rock1, Rock& rock2, Rock& rock3 - references to three Rock objects
    // Returns : Nothing
    void sortRocks(Rock& rock1, Rock& rock2, Rock& rock3);

    // Purpose : Processes a single rock and outputs its details to a file
    // Receives: const Rock& rock - a rock object, ofstream& fout - output file stream
    // Returns : Nothing
    void processRock(const Rock& rock, ofstream& fout);

    // Purpose : Prints the robot's status (total weight processed) to the output file
    // Receives: ofstream& fout - output file stream
    // Returns : Nothing
    void printStatus(ofstream& fout) const;

    // Purpose : Prints the robot's current position to the output file
    // Receives: ofstream& fout - output file stream
    // Returns : Nothing
    void printPosition(ofstream& fout) const;

    // Purpose : Prints a header for the rock data to the output file
    // Receives: ofstream& fout - output file stream
    // Returns : Nothing
    void printRockHeader(ofstream& fout) const;
};
