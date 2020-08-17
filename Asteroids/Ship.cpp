#include "Ship.h"

//private:
int Ship::bulletHitsAsteroid(std::vector<Asteroid>& asteroid, int index) {
	for (int j = 0; j < asteroid.size(); j++) {
		if (asteroid.at(j).isBig()) {
			for (int k = 0; k < 9; k++) {
				if (_bullet[index].hitAsteroid(asteroid.at(j).getPositionBig()[k])) {
					return j;
				}
			}
		}
		else {
			if (_bullet[index].hitAsteroid(asteroid.at(j).getPositionSmall())) {
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
		_bullet[i] = Bullet();
}
void Ship::resetShip() {
	_position.setPositionShipStart();
	_scopePosition.setPositionScopeStart();
	_speed.setSpeed(0, 0);
	_facing = 0;
}

void Ship::newShipFrame(int frame) {
	_position.move(_speed, frame);
	_scopePosition.move(_speed, frame);
}
void Ship::newBulletsFrame() {
	for (int i = 0; i < MAX_BULLETS; i++)
		_bullet[i].newFrame();
}

Position Ship::getPosition() { return _position; }
Position Ship::getScopePosition() { return _scopePosition; }
int Ship::getFacing() { return _facing; }
int Ship::getMaxBullets() { return MAX_BULLETS; }
Bullet Ship::getBullet(int index) { return _bullet[index]; }

void Ship::turnRight() {
	if (_facing == 7)
		_facing = 0;
	else
		_facing++;
	_scopePosition.scopeMoveRight(_facing);
}
void Ship::turnLeft() {
	if (_facing == 0)
		_facing = 7;
	else
		_facing--;
	_scopePosition.scopeMoveLeft(_facing);
}
void Ship::accelerate() { _speed.accelerate(_facing); }

bool Ship::asteroidHitShip(std::vector<Asteroid>& asteroid) {
	for (int i = 0; i < asteroid.size(); i++) {
		if (asteroid.at(i).isBig()) {
			for (int j = 0; j < 9; j++) {
				if (_position.equals(asteroid.at(i).getPositionBig()[j]) || _scopePosition.equals(asteroid.at(i).getPositionBig()[j])) {
					return true;
				}
			}
		}
		else {
			if (_position.equals(asteroid.at(i).getPositionSmall()) || _scopePosition.equals(asteroid.at(i).getPositionSmall())) {
				return true;
			}
		}
	}
	return false;
}
int Ship::bulletsHitAsteroid(std::vector<Asteroid>& asteroid) {
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (_bullet[i].exists()) {
			for (int j = 0; j < asteroid.size(); j++) {
				if (asteroid.at(j).isBig()) {
					for (int k = 0; k < 9; k++) {
						if (_bullet[i].hitAsteroid(asteroid.at(j).getPositionBig()[k]))
							return j;
					}
				}
				else {
					if (_bullet[i].hitAsteroid(asteroid.at(j).getPositionSmall()))
						return j;
				}
			}
		}
	}
	return -1;
}
int Ship::shoot(std::vector<Asteroid>& asteroid) {
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (!_bullet[i].exists()) {
			_bullet[i].newBullet(_position, _facing);
			return bulletHitsAsteroid(asteroid, i);
		}
	}
	return -1;
}

bool Ship::bulletExists(int index) { return _bullet[index].exists(); }