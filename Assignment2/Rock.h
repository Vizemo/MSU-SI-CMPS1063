#pragma once
#include <cmath>

using namespace std;

class Rock {
private:
    int id;
    int x;
    int y;
    double weight;

public:
    // Purpose : Default constructor to initialize rock's attributes to default values
    // Receives: Nothing
    // Returns : Nothing
    Rock();

    // Purpose : Parameterized constructor to initialize a rock with specific values
    // Receives: int id, int x, int y - rock's position, double weight - rock's weight
    // Returns : Nothing
    Rock(int id, int x, int y, double weight);

    // Purpose : Gets the rock's ID
    // Receives: Nothing
    // Returns : int - the rock's ID
    int getID() const;

    // Purpose : Gets the rock's X position
    // Receives: Nothing
    // Returns : int - the rock's X position
    int getX() const;

    // Purpose : Gets the rock's Y position
    // Receives: Nothing
    // Returns : int - the rock's Y position
    int getY() const;

    // Purpose : Gets the rock's weight
    // Receives: Nothing
    // Returns : double - the rock's weight
    double getWeight() const;

    // Purpose : Calculates the distance from the robot's position
    // Receives: int robotX, int robotY - the robot's position
    // Returns : double - the distance between the rock and the robot
    double calculateDistance(int robotX, int robotY) const;
};
