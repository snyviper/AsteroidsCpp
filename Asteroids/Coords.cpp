#include "Coords.h"

//protected:

//public:
Coords::Coords() {
	x = 0;
	y = 0;
}
Coords::Coords(int X, int Y) {
	x = X;
	y = Y;
}

bool Coords::equals(Coords coords) { return x == coords.getX() && y == coords.getY(); }
bool Coords::equals(int X, int Y) { return x == X && y == Y; }

int Coords::getX() { return x; }
int Coords::getY() { return y; }

