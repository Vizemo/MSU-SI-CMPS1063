#include "Robot.h"
#include <fstream>
#include <iomanip>

using namespace std;

// Purpose : Default constructor to initialize the robot's position and stats to default values
// Receives: Nothing
// Returns : Nothing
Robot::Robot() {
    x = 0;
    y = 0;
    rocksProcessed = 0;
    totalWeight = 0.0;
}

// Purpose : Parameterized constructor to initialize the robot with specific position values
// Receives: int xVal, int yVal - robot's position
// Returns : Nothing
Robot::Robot(int xVal, int yVal) {
    x = xVal;
    y = yVal;
    rocksProcessed = 0;
    totalWeight = 0.0;
}

// Purpose : Reads and processes a single rock from the input file
// Receives: ifstream& fin - input file stream, int id - rock identifier
// Returns : Rock object with the loaded data
Rock Robot::loadRock(ifstream& fin, int id) {
    int rockX, rockY;
    double weight;
    fin >> rockX >> rockY >> weight;
    return Rock(id, rockX, rockY, weight);
}

// Purpose : Manually sorts three rocks based on their distance from the robot
// Receives: Rock& rock1, Rock& rock2, Rock& rock3 - references to three Rock objects
// Returns : Nothing
void Robot::sortRocks(Rock& rock1, Rock& rock2, Rock& rock3) {
    double dist1 = rock1.calculateDistance(x, y);
    double dist2 = rock2.calculateDistance(x, y);
    double dist3 = rock3.calculateDistance(x, y);

    // Bubble sort
    if (dist1 > dist2) {
        swap(rock1, rock2);
    }
    if (dist1 > dist3) {
        swap(rock1, rock3);
    }
    if (dist2 > dist3) {
        swap(rock2, rock3);
    }
}

// Purpose : Processes a single rock and outputs its details to a file
// Receives: const Rock& rock - rock object, ofstream& fout - output file stream
// Returns : Nothing
void Robot::processRock(const Rock& rock, ofstream& fout) {
    rocksProcessed++;
    totalWeight += rock.getWeight();

    fout << rock.getID()
        << setw(16) << "(" << setw(3) << rock.getX() << ", " << setw(3) << rock.getY() << ")"
        << setw(20) << fixed << setprecision(2)
        << rock.calculateDistance(x, y)
        << setw(20) << rock.getWeight() << "\n";
}

// Purpose : Prints the robot's total weight of rocks processed to output file
// Receives: ofstream& fout - output file stream
// Returns : Nothing
void Robot::printStatus(ofstream& fout) const {
    fout << "\nTotal weight of all 3 rocks processed: " << fixed << setprecision(1)
        << totalWeight << " lbs\n";
}

// Purpose : Prints the robot's position to the output file
// Receives: ofstream& fout - output file stream
// Returns : Nothing
void Robot::printPosition(ofstream& fout) const {
    fout << "Robot position:    (" << x << ", " << y << ")\n\n";
}

// Purpose : Prints a header for the rock data to the output file
// Receives: ofstream& fout - output file stream
// Returns : Nothing
void Robot::printRockHeader(ofstream& fout) const {
    fout << "Rock Processed    Position         Distance (in miles)    Weight (lbs)\n";
    fout << "----------------------------------------------------------------------\n";
}
