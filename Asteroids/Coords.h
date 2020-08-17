#ifndef COORDS_H
#define COORDS_H

class Coords
{
protected:
	int _x;
	int _y;

public:
	Coords();
	Coords(int x, int y);

	bool equals(Coords coords) const;
	bool equals(int x, int y) const;

	int getX() const;
	int getY() const;
};

#endif