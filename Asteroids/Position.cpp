#include "Position.h"
#include "ScreenLimit.h"

//private
void Position::verifyLimit() {
	if (x < 0)
		x += ScreenLimit().getSpaceX();
	else if (x >= ScreenLimit().getSpaceX())
		x -= ScreenLimit().getSpaceX();
	if (y < 0)
		y += ScreenLimit().getSpaceY();
	else if (y >= ScreenLimit().getSpaceY())
		y -= ScreenLimit().getSpaceY();
}

//public

Position::Position() {}
Position::Position(int X, int Y) {
	setPosition(X, Y);
}

void Position::setPosition(int X, int Y) {
	x = X;
	y = Y;
	verifyLimit();
}
void Position::setPositionShipStart() {
	x = ScreenLimit().getSpaceX() / 2;
	y = ScreenLimit().getSpaceY() / 2;
}
void Position::setPositionScopeStart() {
	x = ScreenLimit().getSpaceX() / 2;
	y = (ScreenLimit().getSpaceY() / 2) - 1;
}
void Position::plusOneXY() {
	setPosition(x + 1, y + 1);
}

bool Position::equals(Position position) {
	return x == position.getX() && y == position.getY();
}

void Position::move(Speed speed, int frame) {
	if (speed.getX() != 0 && frame % speed.getX() == 0) {
		if (speed.getX() > 0)
			x++;
		else
			x--;
	}
	if (speed.getY() != 0 && frame % speed.getY() == 0) {
		if (speed.getY() > 0)
			y++;
		else
			y--;
	}
	verifyLimit();
}
void Position::moveBullet(Speed speed) {
	x += speed.getX();
	y += speed.getY();
	verifyLimit();
}

void Position::scopeMoveLeft(int facing) {
	// facing
	// 7 0 1
	// 6   2
	// 5 4 3
	switch (facing) {
	case 0:
		x--;
		break;
	case 1:
		y--;
		break;
	case 2:
		y--;
		break;
	case 3:
		x++;
		break;
	case 4:
		x++;
		break;
	case 5:
		y++;
		break;
	case 6:
		y++;
		break;
	case 7:
		x--;
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
		x++;
		break;
	case 1:
		x++;
		break;
	case 2:
		y++;
		break;
	case 3:
		y++;
		break;
	case 4:
		x--;
		break;
	case 5:
		x--;
		break;
	case 6:
		y--;
		break;
	case 7:
		y--;
		break;
	}
	verifyLimit();
}