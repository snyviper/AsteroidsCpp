#ifndef BULLET_H
#define BULLET_H

#include "Coords.h"

class Bullet
{
//private:
	bool existance;
	Coords position;
	Coords speed;
	int remainingFrames;

public:
	Bullet();
	void newBullet(Coords shipPosition, int facing);

	void newFrame();

	bool hitAsteroid(Coords positionAsteroid);

	bool exists();
	int getX();
	int getY();
	Coords getPosition();
};

#endif