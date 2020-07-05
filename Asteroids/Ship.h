#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include "Coords.h"
#include "Bullet.h"
#include "ScreenLimit.h"
#include "Asteroid.h"

class Ship
{
//private:
	Coords scopePosition;
	Coords position;
	Coords speed;
	static const int MAX_BULLETS = 3;
	Bullet bullet[MAX_BULLETS];
	int facing;

public:
	Ship();
	Ship(ScreenLimit limit);
	void resetShip(ScreenLimit limit);

	void newFrame(int frame, ScreenLimit limit);
	void newBulletsFrame(ScreenLimit limit);

	int getX();
	int getY();
	int getScopeX();
	int getScopeY();
	int getFacing();
	int getMaxBullets();
	Coords getBulletPosition(int index);

	void turnRight(ScreenLimit limit);
	void turnLeft(ScreenLimit limit);
	void accelerate();

	bool asteroidHitShip(std::vector<Asteroid>& asteroid, ScreenLimit limit);

	int bulletsHitAsteroid(std::vector<Asteroid>& asteroid);

	void shoot(ScreenLimit limit);

	bool bulletExists(int index);
};

#endif