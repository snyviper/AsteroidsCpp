#ifndef BULLET_H
#define BULLET_H

#include "Coords.h"
#include "ScreenLimit.h"

class Bullet
{
//private:
	bool existance;
	Coords position;
	Coords speed;
	int remainingFrames;

public:
	Bullet();
	Bullet(ScreenLimit limit);
	void newBullet(Coords shipPosition, int facing, ScreenLimit limit);

	void newFrame(ScreenLimit limit);

	bool hitAsteroid(Coords positionAsteroid);

	bool exists();
	int getX();
	int getY();
	Coords getPosition();
};

#endif