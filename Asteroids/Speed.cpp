#include "Speed.h"

//private:
void Speed::accNeg(int* a) {
	switch (*a) {
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
void Speed::accPos(int* a) {
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

//public:
Speed::Speed() {
	_x = 0;
	_y = 0;
}
Speed::Speed(int x, int y) {
	setSpeed(x, y);
}
void Speed::setSpeed(int x, int y) {
	_x = x;
	_y = y;
}

bool Speed::equals(Speed speed) {
	return _x == speed.getX() && _y == speed.getY();
}

void Speed::accelerate(int facing) {
	// facing
	// 7 0 1
	// 6   2
	// 5 4 3
	switch (facing) {
		case 0:
			accNeg(&_y);
			break;
		case 1:
			accPos(&_x);
			accNeg(&_y);
			break;
		case 2:
			accPos(&_x);
			break;
		case 3:
			accPos(&_x);
			accPos(&_y);
			break;
		case 4:
			accPos(&_y);
			break;
		case 5:
			accNeg(&_x);
			accPos(&_y);
			break;
		case 6:
			accNeg(&_x);
			break;
		case 7:
			accNeg(&_x);
			accNeg(&_y);
			break;
	}
}