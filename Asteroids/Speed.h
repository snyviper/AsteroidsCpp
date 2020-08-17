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
	Speed(int x, int y);
	void setSpeed(int x, int y);

	bool equals(Speed speed) const;

	void accelerate(int facing);
};

#endif