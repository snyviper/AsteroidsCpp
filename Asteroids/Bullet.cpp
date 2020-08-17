#include "Bullet.h"

//public:
Bullet::Bullet() : _existence(false), _position(Position(0, 0)), _speed(Speed(0, 0)), _remainingFrames(0) {
	
}
void Bullet::newBullet(Position shipPosition, int facing) {
	// facing
	// 7 0 1
	// 6   2
	// 5 4 3
	switch (facing) {
		case 0:
			_position.setPosition(shipPosition.getX(), shipPosition.getY() - 2);
			_speed.setSpeed(0, -1);
			break;
		case 1:
			_position.setPosition(shipPosition.getX() + 2, shipPosition.getY() - 2);
			_speed.setSpeed(1, -1);
			break;
		case 2:
			_position.setPosition(shipPosition.getX() + 2, shipPosition.getY());
			_speed.setSpeed(1, 0);
			break;
		case 3:
			_position.setPosition(shipPosition.getX() + 2, shipPosition.getY() + 2);
			_speed.setSpeed(1, 1);
			break;
		case 4:
			_position.setPosition(shipPosition.getX(), shipPosition.getY() + 2);
			_speed.setSpeed(0, 1);
			break;
		case 5:
			_position.setPosition(shipPosition.getX() - 2, shipPosition.getY() + 2);
			_speed.setSpeed(-1, 1);
			break;
		case 6:
			_position.setPosition(shipPosition.getX() - 2, shipPosition.getY());
			_speed.setSpeed(-1, 0);
			break;
		case 7:
			_position.setPosition(shipPosition.getX() - 2, shipPosition.getY() - 2);
			_speed.setSpeed(-1, -1);
			break;
	}
	_remainingFrames = 25;
	_existence = true;
}

void Bullet::newFrame() {
	if (_existence) {
		_remainingFrames--;
		if (_remainingFrames <= 0)
			_existence = false;
		else
			_position.moveBullet(_speed);
	}
}

bool Bullet::hitAsteroid(Position positionAsteroid) {
	if (_position.equals(positionAsteroid)) {
		_existence = false;
		_remainingFrames = 0;
		return true;
	}
	return false;
}

bool Bullet::exists() const { return _existence; }
Position Bullet::getPosition() const { return _position; }