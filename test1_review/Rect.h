#pragma once

class Rect {
private:
	int length;
	int width;

public:
	Rect();

	Rect(int l, int w);

	~Rect();

	void setLength(int s2);

	void setWidth(int s);

	const int getLength();

	const int getWidth();

	int findArea();

};