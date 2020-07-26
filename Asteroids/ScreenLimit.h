#ifndef SCREEN_LIMIT_H
#define SCREEN_LIMIT_H

#include <string>

/*class ScreenLimit
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
};*/

namespace ScreenLimit {
	void setLimits(int X, int Y);
	unsigned int getSpaceX();
	unsigned int getSpaceY();
	unsigned int getX();
	unsigned int getY();
	std::string getCleanSpace();
}

#endif
