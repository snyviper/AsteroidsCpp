#include "Position.h"
#include "ScreenLimit.h"

//private
void Position::verifyLimit() {
	if (_x < 0)
		_x += ScreenLimit::getSpaceX();
	else if (_x >= ScreenLimit::getSpaceX())
		_x -= ScreenLimit::getSpaceX();
	if (_y < 0)
		_y += ScreenLimit::getSpaceY();
	else if (_y >= ScreenLimit::getSpaceY())
		_y -= ScreenLimit::getSpaceY();
}

//public
Position::Position() {}
Position::Position(int x, int y) {
	setPosition(x, y);
}

void Position::setPosition(int x, int y) {
	_x = x;
	_y = y;
	verifyLimit();
}
void Position::setPositionShipStart() {
	_x = ScreenLimit::getSpaceX() / 2;
	_y = ScreenLimit::getSpaceY() / 2;
}
void Position::setPositionScopeStart() {
	_x = ScreenLimit::getSpaceX() / 2;
	_y = (ScreenLimit::getSpaceY() / 2) - 1;
}
void Position::plusOneXY() {
	setPosition(_x + 1, _y + 1);
}

bool Position::equals(Position position) {
	return _x == position.getX() && _y == position.getY();
}

void Position::move(Speed speed, int frame) {
	if (speed.getX() != 0 && frame % speed.getX() == 0) {
		if (speed.getX() > 0)
			_x++;
		else
			_x--;
	}
	if (speed.getY() != 0 && frame % speed.getY() == 0) {
		if (speed.getY() > 0)
			_y++;
		else
			_y--;
	}
	verifyLimit();
}
void Position::moveBullet(Speed speed) {
	_x += speed.getX();
	_y += speed.getY();
	verifyLimit();
}

void Position::scopeMoveLeft(int facing) {
	// facing
	// 7 0 1
	// 6   2
	// 5 4 3
	switch (facing) {
	case 0:
		_x--;
		break;
	case 1:
		_y--;
		break;
	case 2:
		_y--;
		break;
	case 3:
		_x++;
		break;
	case 4:
		_x++;
		break;
	case 5:
		_y++;
		break;
	case 6:
		_y++;
		break;
	case 7:
		_x--;
		break;
	}
	verifyLimit();
}
void Position::scopeMoveRight(int facing) {
	// facing
	// 7 0 1
	// 6   2
	// 5 4 3
	switch (facing) {
	case 0:
		_x++;
		break;
	case 1:
		_x++;
		break;
	case 2:
		_y++;
		break;
	case 3:
		_y++;
		break;
	case 4:
		_x--;
		break;
	case 5:
		_x--;
		break;
	case 6:
		_y--;
		break;
	case 7:
		_y--;
		break;
	}
	verifyLimit();
}