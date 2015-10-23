#ifndef __JACE_RECTANGLE_H_
#define __JACE_RECTANGLE_H_

#include "../JACE_Common.h"

class Rectangle
{
public:
	Rectangle();
	Rectangle(int, int, int, int);
	~Rectangle();

	void CreateRectangle(int, int, int, int);

	void SetWidth(int w) { width = w; };
	void SetHeight(int h) { height = h; };
	void SetX(int x) { xPos = x; };
	void SetY(int y) { yPos = y; };

	int GetWidth();
	int GetHeight();
	int GetX();
	int GetY();
private:
	int xPos;
	int yPos;
	int width;
	int height;

	Boolean undefined;
};

#endif