#include "Robot.h"

Robot::Robot() {
	x = 0;
	y = 0;
	processed = 0;
	totalWeight = 0.0;
}

Robot::Robot(int xF, int yF) {
	x = xF;
	y = yF;
	processed = 0;
	totalWeight = 0.0;
}

int Robot::getRobotX() {
	return x;
}

int Robot::getRobotY() {
	return y;
}

int Robot::getRobotProc() {
	return processed;
}

int Robot::getRobotWeight() {
	return totalWeight;
}

void Robot::setRobotX(int num) {
	x = num;
}

void Robot::setRobotY(int num) {
	y = num;
}

void Robot::setRobotProc(int num) {
	processed = num;
}

void Robot::setRobotTWeight(double num) {
	totalWeight = num;
}