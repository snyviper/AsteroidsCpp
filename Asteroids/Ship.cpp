#include "Ship.h"
#include <Windows.h>
#include <string>
#include <thread>

//public:
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

Coords Ship::getPosition() { return position; }
Coords Ship::getScopePosition() { return scopePosition; }
int Ship::getFacing() { return facing; }
int Ship::getMaxBullets() { return MAX_BULLETS; }
Bullet Ship::getBullet(int index) {
	return bullet[index];
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
				if (position.equals(asteroid.at(i).getPositionBig()[j]) || scopePosition.equals(asteroid.at(i).getPositionBig()[j])) {
					std::thread tPlayShipExplosionSound(playShipExplosionSound);
					tPlayShipExplosionSound.detach();
					return true;
				}
			}
		}
		else {
			if (position.equals(asteroid.at(i).getPositionSmall()) || scopePosition.equals(asteroid.at(i).getPositionSmall())) {
				std::thread tPlayShipExplosionSound(playShipExplosionSound);
				tPlayShipExplosionSound.detach();
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
						if (bullet[i].hitAsteroid(asteroid.at(j).getPositionBig()[k])) {
							std::thread tPlayAsteroidExplosionSound(playAsteroidExplosionSound);
							tPlayAsteroidExplosionSound.detach();
							return j;
						}
					}
				}
				else {
					if (bullet[i].hitAsteroid(asteroid.at(j).getPositionSmall())) {
						std::thread tPlayAsteroidExplosionEffect(playAsteroidExplosionSound);
						tPlayAsteroidExplosionEffect.detach();
						return j;
					}
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
			//create thread
			std::thread tPlayShipGunSoundEffect(playGunSound);
			tPlayShipGunSoundEffect.detach();
			break;
		}
	}
}

bool Ship::bulletExists(int index) { return bullet[index].exists(); }