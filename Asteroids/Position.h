#ifndef POSITION_H
#define POSITION_H

#include "Coords.h"
#include "Speed.h"

class Position : public Coords
{
	//private:
	void verifyLimit();

public:
	Position();
	Position(int X, int Y);

	void setPosition(int X, int Y);
	void setPositionShipStart();
	void setPositionScopeStart();
	void plusOneXY();

	bool equals(Position position);

	void moveBullet(Speed speed);

	void move(Speed speed, int frame);

	//scope position
	void scopeMoveLeft(int facing);
	void scopeMoveRight(int facing);
};

#endif