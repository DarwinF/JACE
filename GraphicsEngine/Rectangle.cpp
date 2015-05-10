#include "Rectangle.h"

Rectangle::Rectangle() {
	xPos = 0;
	yPos = 0;
	width = 0;
	height = 0;
	undefined = TRUE;
}
	
Rectangle::Rectangle(int x, int y, int w, int h) {
	xPos = x;
	yPos = y;
	width = w;
	height = h;
	undefined = FALSE;
}

Rectangle::~Rectangle() {

}

void Rectangle::CreateRectangle(int x, int y, int w, int h) {
	Rectangle(x, y, w, h);
}

int Rectangle::GetWidth() {
	int w;

	if (undefined)
		w = NULL;
	else
		w = width;

	return w;
}

int Rectangle::GetHeight() {
	int h;

	if (undefined)
		h = NULL;
	else
		h = height;

	return h;
}

int Rectangle::GetX() {
	int x;

	if (undefined)
		x = NULL;
	else
		x = xPos;

	return x;
}

int Rectangle::GetY() {
	int y;

	if (undefined)
		y = NULL;
	else
		y = yPos;

	return y;
}