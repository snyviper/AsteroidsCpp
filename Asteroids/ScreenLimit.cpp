#include "ScreenLimit.h"

namespace ScreenLimit {

	namespace {
		unsigned int x = 100;
		unsigned int y = 25;
		std::string cleanSpace = "";
	}

	void setLimits(int X, int Y) {
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

	unsigned int getSpaceX() { return x; }
	unsigned int getSpaceY() { return y - 3; }

	unsigned int getX() { return x; }
	unsigned int getY() { return y; }

	std::string getCleanSpace() { return cleanSpace; }
}