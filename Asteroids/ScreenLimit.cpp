#include "ScreenLimit.h"

//private:
unsigned int ScreenLimit::x = 100;
unsigned int ScreenLimit::y = 25;

//public:
ScreenLimit::ScreenLimit() {}
ScreenLimit::ScreenLimit(int X, int Y){
	setLimits(X, Y);
}

void ScreenLimit::setLimits(int X, int Y) {
	if (X >= 30 && Y >= 10) {
		x = X;
		y = Y;
	}
}

unsigned int ScreenLimit::getSpaceX() { return x; }
unsigned int ScreenLimit::getSpaceY() { return y - 3; }

unsigned int ScreenLimit::getX() { return x; }
unsigned int ScreenLimit::getY() { return y; }