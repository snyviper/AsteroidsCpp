#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include "Coords.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "Sounds.h"

class Ship : Sounds
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

	Coords getPosition();
	Coords getScopePosition();
	int getFacing();
	int getMaxBullets();
	Bullet getBullet(int index);

	void turnRight();
	void turnLeft();
	void accelerate();

	bool asteroidHitShip(std::vector<Asteroid>& asteroid);
	int bulletsHitAsteroid(std::vector<Asteroid>& asteroid);
	void shoot();

	bool bulletExists(int index);
};

#endif