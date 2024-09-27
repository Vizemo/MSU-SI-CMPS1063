#pragma once
class Robot
{
private:
	int x;
	int y;
	int processed;
	double totalWeight;

public:
	Robot();

	Robot(int x, int y);

	int getRobotX();

	int getRobotY();

	int getRobotProc();

	int getRobotWeight();

	void setRobotX(int num);

	void setRobotY(int num);

	void setRobotProc(int num);

	void setRobotTWeight(double num);
};