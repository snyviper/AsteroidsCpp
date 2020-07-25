#ifndef ASTEROID_H
#define ASTEROID_H

#include "Coords.h"

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
	Asteroid(int difficulty);
	Asteroid(int difficulty, Coords Position);

	void newSpeed(int difficulty);

	void newFrame(int frame);

	void turnSmall(int difficulty);

	bool isBig();
	Coords getPositionSmall();
	Coords* getPositionBig();
	Coords getSpeed();
};

#endif