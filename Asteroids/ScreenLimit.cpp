#include "ScreenLimit.h"

namespace ScreenLimit {

	namespace {
		int x = 100;
		int y = 25;
		std::string cleanSpace = "";
		std::string topBorder = "";
		std::string bottomBorder = "";
	}

	void setLimits(int X, int Y) {
		if (X >= 30 && Y >= 10) {
			char BOTTOMBORDER = 238;
			x = X;
			y = Y;
			cleanSpace = "";
			topBorder = "";
			bottomBorder = "";
			for (int i = 0; i < getSpaceY(); i++) {
				for (int j = 0; j < getSpaceX(); j++) {
					cleanSpace += " ";
				}
				cleanSpace += "\n";
			}
			for (int i = 0; i < getSpaceX(); i++) {
				topBorder += "_";
			}
			for (int i = 0; i < getSpaceX() - 9; i++) {
				bottomBorder += BOTTOMBORDER;
			}
		}
	}

	int getSpaceX() { return x; }
	int getSpaceY() { return y - 3; }

	int getX() { return x; }
	int getY() { return y; }

	std::string getCleanSpace() { return cleanSpace; }
	std::string getTopBorder() { return topBorder; }
	std::string getBottomBorder() { return bottomBorder; }
}