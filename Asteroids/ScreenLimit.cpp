#include "ScreenLimit.h"

//private:
unsigned int ScreenLimit::x = 100;
unsigned int ScreenLimit::y = 25;
std::string ScreenLimit::cleanSpace = "";

//public:
ScreenLimit::ScreenLimit() {}
ScreenLimit::ScreenLimit(int X, int Y){
	setLimits(X, Y);
}

void ScreenLimit::setLimits(int X, int Y) {
	if (X >= 30 && Y >= 10) {
		x = X;
		y = Y;
		for (int i = 0; i < getSpaceY(); i++) {
			for (int j = 0; j < getSpaceX(); j++) {
				cleanSpace += " ";
			}
			cleanSpace += "\n";
		}
	}
}

unsigned int ScreenLimit::getSpaceX() { return x; }
unsigned int ScreenLimit::getSpaceY() { return y - 3; }

unsigned int ScreenLimit::getX() { return x; }
unsigned int ScreenLimit::getY() { return y; }

std::string ScreenLimit::getCleanSpace() { return cleanSpace; }