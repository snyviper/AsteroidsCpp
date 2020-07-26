#ifndef COORDS_H
#define COORDS_H

class Coords
{
protected:
	int x;
	int y;

public:
	Coords();
	Coords(int X, int Y);

	bool equals(Coords coords);
	bool equals(int X, int Y);

	int getX();
	int getY();
};

#endif