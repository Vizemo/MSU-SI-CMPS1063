#pragma once
class Rock
{
private:
	int x;
	int y;
	double weight;

public:
	Rock();

	Rock(int xF, int yF, double wF);

	int getRockX();

	int getRockY();

	int getRockWeight();

	void setRockX(int num);

	void setRockY(int num);

	void setRockWeight(double num);

};