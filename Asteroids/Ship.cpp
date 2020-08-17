#include "Ship.h"

//private:
int Ship::bulletHitsAsteroid(std::vector<Asteroid>& asteroid, int index) {
	for (int j = 0; j < asteroid.size(); j++) {
		if (asteroid.at(j).isBig()) {
			for (int k = 0; k < 9; k++) {
				if (bullet[index].hitAsteroid(asteroid.at(j).getPositionBig()[k])) {
					return j;
				}
			}
		}
		else {
			if (bullet[index].hitAsteroid(asteroid.at(j).getPositionSmall())) {
				return j;
			}
		}
	}
	return -1;
}

//public:
Ship::Ship() {
	resetShip();
	for (int i = 0; i < MAX_BULLETS; i++)
		bullet[i] = Bullet();
}
void Ship::resetShip() {
	position.setPositionShipStart();
	scopePosition.setPositionScopeStart();
	speed.setSpeed(0, 0);
	_facing = 0;
}

void Ship::newShipFrame(int frame) {
	position.move(speed, frame);
	scopePosition.move(speed, frame);
}
void Ship::newBulletsFrame() {
	for (int i = 0; i < MAX_BULLETS; i++)
		bullet[i].newFrame();
}

Position Ship::getPosition() { return position; }
Position Ship::getScopePosition() { return scopePosition; }
int Ship::getFacing() { return _facing; }
int Ship::getMaxBullets() { return MAX_BULLETS; }
Bullet Ship::getBullet(int index) { return bullet[index]; }

void Ship::turnRight() {
	if (_facing == 7)
		_facing = 0;
	else
		_facing++;
	scopePosition.scopeMoveRight(_facing);
}
void Ship::turnLeft() {
	if (_facing == 0)
		_facing = 7;
	else
		_facing--;
	scopePosition.scopeMoveLeft(_facing);
}
void Ship::accelerate() { speed.accelerate(_facing); }

bool Ship::asteroidHitShip(std::vector<Asteroid>& asteroid) {
	for (int i = 0; i < asteroid.size(); i++) {
		if (asteroid.at(i).isBig()) {
			for (int j = 0; j < 9; j++) {
				if (position.equals(asteroid.at(i).getPositionBig()[j]) || scopePosition.equals(asteroid.at(i).getPositionBig()[j])) {
					return true;
				}
			}
		}
		else {
			if (position.equals(asteroid.at(i).getPositionSmall()) || scopePosition.equals(asteroid.at(i).getPositionSmall())) {
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
int Ship::shoot(std::vector<Asteroid>& asteroid) {
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (!bullet[i].exists()) {
			bullet[i].newBullet(position, _facing);
			return bulletHitsAsteroid(asteroid, i);
		}
	}
	return -1;
}

bool Ship::bulletExists(int index) { return bullet[index].exists(); }