#ifndef SPEED_H
#define SPEED_H

#include "Coords.h"

class Speed : public Coords
{
//private:
	void accNeg(int* a);
	void accPos(int* a);

public:
	Speed();
	Speed(int X, int Y);
	void setSpeed(int X, int Y);

	bool equals(Speed speed);

	void accelerate(int facing);
};

#endif