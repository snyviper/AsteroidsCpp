#include "ScreenLimit.h"

unsigned int ScreenLimit::x = 100;
unsigned int ScreenLimit::y = 25;

ScreenLimit::ScreenLimit() {}
ScreenLimit::ScreenLimit(int X, int Y){
	setLimits(X, Y);
}

void ScreenLimit::setLimits(int X, int Y) {
	if (X >= 25 && Y >= 8) {
		x = X;
		y = Y;
	}
}

unsigned int ScreenLimit::getSpaceX() { return x; }
unsigned int ScreenLimit::getSpaceY() { return y - 3; }

unsigned int ScreenLimit::getX() { return x; }
unsigned int ScreenLimit::getY() { return y; }