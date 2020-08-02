#ifndef SCREEN_LIMIT_H
#define SCREEN_LIMIT_H

#include <string>

namespace ScreenLimit {
	void setLimits(int X, int Y);
	int getSpaceX();
	int getSpaceY();
	int getX();
	int getY();
	std::string getCleanSpace();
	std::string getTopBorder();
	std::string getBottomBorder();
}

#endif