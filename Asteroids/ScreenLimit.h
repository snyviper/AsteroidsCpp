#ifndef SCREEN_LIMIT_H
#define SCREEN_LIMIT_H

class ScreenLimit
{
//private:
	unsigned int x;
	unsigned int y;
public:
	ScreenLimit();
	ScreenLimit(int x, int y);
	void setLimits(int X, int Y);
	unsigned int getSpaceX();
	unsigned int getSpaceY();
	unsigned int getX();
	unsigned int getY();
};

#endif
