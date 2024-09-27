#include "Rock.h"

Rock::Rock() {
	x = 0;
	y = 0;
	weight = 0.0;
}
Rock::Rock(int xF, int yF, double wF) {
	x = xF;
	y = yF;
	weight = wF;
}

int Rock::getRockX() {
	return x;
}

int Rock::getRockY() {
	return y;
}

int Rock::getRockWeight() {
	return weight;
}

void Rock::setRockX(int num) {
	x = num;
}

void Rock::setRockY(int num) {
	y = num;
}

void Rock::setRockWeight(double num) {
	weight = num;
}