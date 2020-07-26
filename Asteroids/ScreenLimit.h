#ifndef SCREEN_LIMIT_H
#define SCREEN_LIMIT_H

#include <iostream>
//#include <string.h>

class ScreenLimit
{
//private:
	static unsigned int x;
	static unsigned int y;
	static std::string cleanSpace;
public:
	ScreenLimit();
	ScreenLimit(int x, int y);
	static void setLimits(int X, int Y);
	static unsigned int getSpaceX();
	static unsigned int getSpaceY();
	static unsigned int getX();
	static unsigned int getY();
	static std::string getCleanSpace();
};

#endif
