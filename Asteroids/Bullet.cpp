#include "Bullet.h"

Bullet::Bullet() {
	existance = false;
	position.setPosition(0, 0);
	speed.setSpeed(0, 0);
	remainingFrames = 0;
}
void Bullet::newBullet(Coords shipPosition, int facing) {
	// facing
	// 7 0 1
	// 6   2
	// 5 4 3
	switch (facing) {
		case 0:
			position.setPosition(shipPosition.getX(), shipPosition.getY() - 2);
			speed.setSpeed(0, -1);
			break;
		case 1:
			position.setPosition(shipPosition.getX() + 2, shipPosition.getY() - 2);
			speed.setSpeed(1, -1);
			break;
		case 2:
			position.setPosition(shipPosition.getX() + 2, shipPosition.getY());
			speed.setSpeed(1, 0);
			break;
		case 3:
			position.setPosition(shipPosition.getX() + 2, shipPosition.getY() + 2);
			speed.setSpeed(1, 1);
			break;
		case 4:
			position.setPosition(shipPosition.getX(), shipPosition.getY() + 2);
			speed.setSpeed(0, 1);
			break;
		case 5:
			position.setPosition(shipPosition.getX() - 2, shipPosition.getY() + 2);
			speed.setSpeed(-1, 1);
			break;
		case 6:
			position.setPosition(shipPosition.getX() - 2, shipPosition.getY());
			speed.setSpeed(-1, 0);
			break;
		case 7:
			position.setPosition(shipPosition.getX() - 2, shipPosition.getY() - 2);
			speed.setSpeed(-1, -1);
			break;
	}
	remainingFrames = 25;
	existance = true;
}

void Bullet::newFrame() {
	if (existance) {
		remainingFrames--;
		if (remainingFrames <= 0)
			existance = false;
		else
			position.moveBullet(speed);
	}
}

bool Bullet::hitAsteroid(Coords positionAsteroid) {
	if (position.equals(positionAsteroid)) {
		existance = false;
		remainingFrames = 0;
		return true;
	}
	return false;
}

bool Bullet::exists() { return existance; }
Coords Bullet::getPosition(){ return position; }