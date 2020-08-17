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
	Position(int x, int y);

	void setPosition(int x, int y);
	void setPositionShipStart();
	void setPositionScopeStart();
	void plusOneXY();

	bool equals(Position position) const;

	void moveBullet(Speed speed);

	void move(Speed speed, int frame);

	//scope position
	void scopeMoveLeft(int facing);
	void scopeMoveRight(int facing);
};

#endif