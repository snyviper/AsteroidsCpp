#ifndef SHIP_H
#define SHIP_H

#include <vector>
//#include "Position.h"
//#include "Speed.h"
#include "Bullet.h"
#include "Asteroid.h"

class Ship
{
//private:
	Position _scopePosition;
	Position _position;
	Speed _speed;
	static const int MAX_BULLETS = 3;
	Bullet _bullet[MAX_BULLETS];
	int _facing;

	int bulletHitsAsteroid(std::vector<Asteroid>& asteroid, int index);

public:
	Ship();
	void resetShip();

	void newShipFrame(int frame);
	void newBulletsFrame();

	Position getPosition();
	Position getScopePosition();
	int getFacing();
	int getMaxBullets();
	Bullet getBullet(int index);

	void turnRight();
	void turnLeft();
	void accelerate();

	bool asteroidHitShip(std::vector<Asteroid>& asteroid);
	int bulletsHitAsteroid(std::vector<Asteroid>& asteroid);
	int shoot(std::vector<Asteroid>& asteroid);

	bool bulletExists(int index);
};

#endif