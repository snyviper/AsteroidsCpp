#ifndef ASTEROID_H
#define ASTEROID_H

#include "Asteroid.h"
#include "Coords.h"
#include "ScreenLimit.h"
#include "Bullet.h"

class Asteroid
{
//private:
	Coords position[9];
	Coords speed;
	bool big;
	static int s_RandAdd;

	void changeRandomSeed();

	int randomPosition(int maxPosition);

	int randomSpeed(int difficulty);

public:
	Asteroid();
	Asteroid(int difficulty, ScreenLimit limit);
	Asteroid(int difficulty, Coords Position, ScreenLimit limit);

	void newSpeed(int difficulty);

	void newFrame(ScreenLimit limit, int frame);

	bool bulletCollision(Coords bulletPosition);

	void turnSmall(int difficulty, ScreenLimit limit);

	int getX();
	int getY();
	bool isBig();
	Coords getPositionSmall();
	Coords* getPositionBig();
	Coords getSpeed();
};

#endif