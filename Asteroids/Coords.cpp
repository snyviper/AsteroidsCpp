#include "Coords.h"

void Coords::verifyLimit(ScreenLimit limit) {
	if (x < 0) { x += limit.getSpaceX(); }
	if (y < 0) { y += limit.getSpaceY(); }
	if (x >= limit.getSpaceX()) { x -= limit.getSpaceX(); }
	if (y >= limit.getSpaceY()) { y -= limit.getSpaceY(); }
}

void Coords::accNeg(int* a) {
	switch (*a)	{
		case -2:
			*a = -1;
			break;
		case -3:
			*a = -2;
			break;
		case -4:
			*a = -3;
			break;
		case -6:
			*a = -4;
			break;
		case 0:
			*a = -6;
			break;
		case 6:
			*a = 0;
			break;
		case 4:
			*a = 6;
			break;
		case 3:
			*a = 4;
			break;
		case 2:
			*a = 3;
			break;
		case 1:
			*a = 2;
			break;
	}
}
void Coords::accPos(int* a) {
	switch (*a) {
		case -1:
			*a = -2;
			break;
		case -2:
			*a = -3;
			break;
		case -3:
			*a = -4;
			break;
		case -4:
			*a = -6;
			break;
		case -6:
			*a = 0;
			break;
		case 0:
			*a = 6;
			break;
		case 6:
			*a = 4;
			break;
		case 4:
			*a = 3;
			break;
		case 3:
			*a = 2;
			break;
		case 2:
			*a = 1;
			break;
	}
}

Coords::Coords() {
	x = 0;
	y = 0;
}
Coords::Coords(int X, int Y, ScreenLimit limit) {
	x = X;
	y = Y;
	verifyLimit(limit);
}
void Coords::setPosition(int X, int Y, ScreenLimit limit) {
	x = X;
	y = Y;
	verifyLimit(limit);
}
void Coords::setPositionShipStart(ScreenLimit limit) {
	x = limit.getSpaceX() / 2;
	y = limit.getSpaceY() / 2;
}
void Coords::setPositionScopeStart(ScreenLimit limit) {
	x = limit.getSpaceX() / 2;
	y = (limit.getSpaceY() / 2) - 1;
}
void Coords::setSpeed(int X, int Y) {
	x = X;
	y = Y;
}
bool Coords::equalsXY(Coords position) {
	return x == position.getX() && y == position.getY();
}

short Coords::getX() { return x; }
short Coords::getY() { return y; }

//position

void Coords::moveBullet(Coords speed, ScreenLimit limit) {
	x += speed.x;
	y += speed.y;
	verifyLimit(limit);
}

void Coords::move(Coords speed, int frame, ScreenLimit limit) {
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
	verifyLimit(limit);
}

//scope position
void Coords::scopeMoveLeft(int facing, ScreenLimit limit) {
	// facing
	// 7 0 1
	// 6   2
	// 5 4 3
	switch (facing) {
		case 0:
			x -= 1;
			break;
		case 1:
			y -= 1;
			break;
		case 2:
			y -= 1;
			break;
		case 3:
			x += 1;
			break;
		case 4:
			x += 1;
			break;
		case 5:
			y += 1;
			break;
		case 6:
			y += 1;
			break;
		case 7:
			x -= 1;
			break;
	}
	verifyLimit(limit);
}
void Coords::scopeMoveRight(int facing, ScreenLimit limit) {
	// facing
	// 7 0 1
	// 6   2
	// 5 4 3
	switch (facing) {
		case 0:
			x += 1;
			break;
		case 1:
			x += 1;
			break;
		case 2:
			y += 1;
			break;
		case 3:
			y += 1;
			break;
		case 4:
			x -= 1;
			break;
		case 5:
			x -= 1;
			break;
		case 6:
			y -= 1;
			break;
		case 7:
			y -= 1;
			break;
	}
	verifyLimit(limit);
}

//speed
void Coords::accelerate(int facing) {
	// facing
	// 7 0 1
	// 6   2
	// 5 4 3
	switch (facing) {
		case 0:
			accNeg(&y);
			break;
		case 1:
			accPos(&x);
			accNeg(&y);
			break;
		case 2:
			accPos(&x);
			break;
		case 3:
			accPos(&x);
			accPos(&y);
			break;
		case 4:
			accPos(&y);
			break;
		case 5:
			accNeg(&x);
			accPos(&y);
			break;
		case 6:
			accNeg(&x);
			break;
		case 7:
			accNeg(&x);
			accNeg(&y);
			break;
	}
}
