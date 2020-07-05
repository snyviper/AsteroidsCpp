#include "Bullet.h"

Bullet::Bullet() {
	existance = false;
}
Bullet::Bullet(ScreenLimit limit) {
	existance = false;
	position.setPosition(0, 0, limit);
	speed.setSpeed(0, 0);
	remainingFrames = 0;
}
void Bullet::newBullet(Coords shipPosition, int facing, ScreenLimit limit) {
	// facing
	// 7 0 1
	// 6   2
	// 5 4 3
	switch (facing) {
		case 0:
			position.setPosition(shipPosition.getX(), shipPosition.getY() - 2, limit);
			speed.setSpeed(0, -1);
			break;
		case 1:
			position.setPosition(shipPosition.getX() + 2, shipPosition.getY() - 2, limit);
			speed.setSpeed(1, -1);
			break;
		case 2:
			position.setPosition(shipPosition.getX() + 2, shipPosition.getY(), limit);
			speed.setSpeed(1, 0);
			break;
		case 3:
			position.setPosition(shipPosition.getX() + 2, shipPosition.getY() + 2, limit);
			speed.setSpeed(1, 1);
			break;
		case 4:
			position.setPosition(shipPosition.getX(), shipPosition.getY() + 2, limit);
			speed.setSpeed(0, 1);
			break;
		case 5:
			position.setPosition(shipPosition.getX() - 2, shipPosition.getY() + 2, limit);
			speed.setSpeed(-1, 1);
			break;
		case 6:
			position.setPosition(shipPosition.getX() - 2, shipPosition.getY(), limit);
			speed.setSpeed(-1, 0);
			break;
		case 7:
			position.setPosition(shipPosition.getX() - 2, shipPosition.getY() - 2, limit);
			speed.setSpeed(-1, -1);
			break;
	}
	remainingFrames = 25;
	existance = true;
}

void Bullet::newFrame(ScreenLimit limit) {
	if (existance) {
		remainingFrames--;
		if (remainingFrames <= 0)
			existance = false;
		else
			position.moveBullet(speed, limit);
	}
}

bool Bullet::hitAsteroid(Coords positionAsteroid) {
	if (position.equalsXY(positionAsteroid)) {
		existance = false;
		remainingFrames = 0;
		return true;
	}
	return false;
}

bool Bullet::exists() { return existance; }
int Bullet::getX() { return position.getX(); }
int Bullet::getY() { return position.getY(); }
Coords Bullet::getPosition(){ return position; }