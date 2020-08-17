#include "Coords.h"

//public:
Coords::Coords() : _x(0), _y(0) {

}
Coords::Coords(int x, int y) : _x(x), _y(y) {
	
}

bool Coords::equals(Coords coords) const { return _x == coords.getX() && _y == coords.getY(); }
bool Coords::equals(int x, int y) const { return _x == x && _y == y; }

int Coords::getX() const { return _x; }
int Coords::getY() const { return _y; }
