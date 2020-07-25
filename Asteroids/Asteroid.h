#ifndef ASTEROID_H
#define ASTEROID_H

#include "Position.h"
#include "Speed.h"

class Asteroid
{
//private:
	Position position[9];
	Speed speed;
	bool big;
	static int s_RandAdd;

	void changeRandomSeed();

	int randomPosition(int maxPosition);

	int randomSpeed(int difficulty);

public:
	Asteroid();
	Asteroid(int difficulty);
	Asteroid(int difficulty, Position Position);

	void newSpeed(int difficulty);

	void newFrame(int frame);

	void turnSmall(int difficulty);

	bool isBig();
	Position getPositionSmall();
	Position* getPositionBig();
	Speed getSpeed();
};

#endif