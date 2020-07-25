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
	x = 0;
	y = 0;
}
Speed::Speed(int X, int Y) {
	setSpeed(X, Y);
}
void Speed::setSpeed(int X, int Y) {
	x = X;
	y = Y;
}

bool Speed::equals(Speed speed) {
	return x == speed.getX() && y == speed.getY();
}

void Speed::accelerate(int facing) {
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