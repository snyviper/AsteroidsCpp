#ifndef SCREEN_LIMIT_H
#define SCREEN_LIMIT_H

#include <string>

namespace ScreenLimit {
	void setLimits(int X, int Y);
	unsigned int getSpaceX();
	unsigned int getSpaceY();
	unsigned int getX();
	unsigned int getY();
	std::string getCleanSpace();
}

#endif