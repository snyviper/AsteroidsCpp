#ifndef COORDS_H
#define COORDS_H

class Coords
{
//private:
	int x;
	int y;

	void verifyLimit();

	void accNeg(int* a);
	void accPos(int* a);
public:
	Coords();
	Coords(int X, int Y);
	void setPosition(int X, int Y);
	void setPositionShipStart();
	void setPositionScopeStart();
	void setSpeed(int X, int Y);
	bool equals(Coords position);

	short getX();
	short getY();

	//position

	void plusOneXY();

	void moveBullet(Coords speed);

	void move(Coords speed, int frame);

	//scope position
	void scopeMoveLeft(int facing);
	void scopeMoveRight(int facing);

	//speed
	void accelerate(int facing);
};

#endif