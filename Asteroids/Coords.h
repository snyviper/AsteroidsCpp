#ifndef COORDS_H
#define COORDS_H

#include "ScreenLimit.h"

class Coords
{
//private:
	int x;
	int y;

	void verifyLimit(ScreenLimit limit);

	void accNeg(int* a);
	void accPos(int* a);
public:
	Coords();
	Coords(int X, int Y, ScreenLimit limit);
	void setPosition(int X, int Y, ScreenLimit limit);
	void setPositionShipStart(ScreenLimit limit);
	void setPositionScopeStart(ScreenLimit limit);
	void setSpeed(int X, int Y);
	bool equalsXY(Coords position);

	short getX();
	short getY();

	//position

	void moveBullet(Coords speed, ScreenLimit limit);

	void move(Coords speed, int frame, ScreenLimit limit);

	//scope position
	void scopeMoveLeft(int facing, ScreenLimit limit);
	void scopeMoveRight(int facing, ScreenLimit limit);

	//speed
	void accelerate(int facing);
};

#endif