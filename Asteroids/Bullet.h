#ifndef BULLET_H
#define BULLET_H

#include "Position.h"
//#include "Speed.h"

class Bullet
{
//private:
	bool existence;
	Position position;
	Speed speed;
	int remainingFrames;

public:
	Bullet();
	void newBullet(Position shipPosition, int facing);

	void newFrame();

	bool hitAsteroid(Position positionAsteroid);

	bool exists();
	Position getPosition();
};

#endif