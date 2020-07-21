#include "Ship.h"

Ship::Ship() {
	resetShip();
	for (int index = 0; index < MAX_BULLETS; index++) {
		bullet[index] = Bullet();
	}
}
void Ship::resetShip() {
	position.setPositionShipStart();
	scopePosition.setPositionScopeStart();
	speed.setSpeed(0, 0);
	facing = 0;
}

void Ship::newFrame(int frame) {
	position.move(speed, frame);
	scopePosition.move(speed, frame);
	newBulletsFrame();
}
void Ship::newBulletsFrame() {
	for (int index = 0; index < MAX_BULLETS; index++) {
		bullet[index].newFrame();
	}
}

int Ship::getX() { return position.getX(); }
int Ship::getY() { return position.getY(); }
int Ship::getScopeX() { return scopePosition.getX(); }
int Ship::getScopeY() { return scopePosition.getY(); }
int Ship::getFacing() { return facing; }
int Ship::getMaxBullets() { return MAX_BULLETS; }
Coords Ship::getBulletPosition(int index) {
	return bullet[index].getPosition();
}

void Ship::turnRight() {
	if (facing == 7)
		facing = 0;
	else
		facing++;
	scopePosition.scopeMoveRight(facing);
}
void Ship::turnLeft() {
	if (facing == 0)
		facing = 7;
	else
		facing--;
	scopePosition.scopeMoveLeft(facing);
}
void Ship::accelerate() { speed.accelerate(facing); }

bool Ship::asteroidHitShip(std::vector<Asteroid>& asteroid) {
	for (int i = 0; i < asteroid.size(); i++) {
		if (asteroid.at(i).isBig()) {
			for (int j = 0; j < 9; j++) {
				if (position.equalsXY(asteroid.at(i).getPositionBig()[j])) {
					//resetShip();
					return true;
				}
			}
		}
		else {
			if (position.equalsXY(asteroid.at(i).getPositionSmall())) {
				//resetShip();
				return true;
			}
		}
	}
	return false;
}

int Ship::bulletsHitAsteroid(std::vector<Asteroid>& asteroid) {
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (bullet[i].exists()) {
			for (int j = 0; j < asteroid.size(); j++) {
				if (asteroid.at(j).isBig()) {
					for (int k = 0; k < 9; k++) {
						if (bullet[i].hitAsteroid(asteroid.at(j).getPositionBig()[k]))
							return j;
					}
				}
				else {
					if (bullet[i].hitAsteroid(asteroid.at(j).getPositionSmall()))
						return j;
				}
			}
		}
	}
	return -1;
}

void Ship::shoot() {
	for (int index = 0; index < MAX_BULLETS; index++) {
		if (!bullet[index].exists()) {
			bullet[index].newBullet(position, facing);
			break;
		}
	}
}

bool Ship::bulletExists(int index) { return bullet[index].exists(); }