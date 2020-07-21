#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include "Coords.h"
#include "Bullet.h"
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
	void resetShip();

	void newFrame(int frame);
	void newBulletsFrame();

	int getX();
	int getY();
	int getScopeX();
	int getScopeY();
	int getFacing();
	int getMaxBullets();
	Coords getBulletPosition(int index);

	void turnRight();
	void turnLeft();
	void accelerate();

	bool asteroidHitShip(std::vector<Asteroid>& asteroid);

	int bulletsHitAsteroid(std::vector<Asteroid>& asteroid);

	void shoot();

	bool bulletExists(int index);
};

#endif