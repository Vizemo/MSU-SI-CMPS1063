#include "Rock.h"

// Default constructor
Rock::Rock() {
    id = 0;
    x = 0;
    y = 0;
    weight = 0.0;
}

// Parameterized constructor
Rock::Rock(int idVal, int xVal, int yVal, double weightVal) {
    id = idVal;
    x = xVal;
    y = yVal;
    weight = weightVal;
}

// Getter methods
int Rock::getID() const {
    return id;
}

int Rock::getX() const {
    return x;
}

int Rock::getY() const {
    return y;
}

double Rock::getWeight() const {
    return weight;
}

// Distance calculation method
double Rock::calculateDistance(int robotX, int robotY) const {
    return sqrt(pow(x - robotX, 2) + pow(y - robotY, 2));
}
