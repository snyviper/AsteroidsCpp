#include "Bullet.h"

Bullet::Bullet() {
	existence = false;
	position = Position(0, 0);
	speed = Speed(0, 0);
	remainingFrames = 0;
}
void Bullet::newBullet(Position shipPosition, int facing) {
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
	existence = true;
}

void Bullet::newFrame() {
	if (existence) {
		remainingFrames--;
		if (remainingFrames <= 0)
			existence = false;
		else
			position.moveBullet(speed);
	}
}

bool Bullet::hitAsteroid(Position positionAsteroid) {
	if (position.equals(positionAsteroid)) {
		existence = false;
		remainingFrames = 0;
		return true;
	}
	return false;
}

bool Bullet::exists() { return existence; }
Position Bullet::getPosition(){ return position; }