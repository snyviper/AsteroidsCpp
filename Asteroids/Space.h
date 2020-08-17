#ifndef SPACE_H
#define SPACE_H

#include <vector>
#include <ctime>
#include "Ship.h"
#include "Asteroid.h"

class Space
{
//private
	Ship _ship;
	std::vector<Asteroid> _asteroid;
	int _difficulty, _stage, _frame, _hearts, _score;
	double MAX_FPS, MAX_REFRESH_RATE; // in order to make these "const", Main.cpp has to be rewritten to accomodate this change

	void nextFrame();

	void resetAsteroids();
	void damageAsteroid(int index);

	bool asteroidHitShip();

	void movePrintAsteroids();
	void printAsteroids();

	void printBullets();

	void damageShip();

	void help(double fps);

	double getFPS(clock_t refreshRate);

	bool spaceHasAnyBullet();
	bool spaceHasAllBullets();

	void beforeStartBattle();
	void startBattle();

	void newStage();

	void setHearts();
	void removeHeart();
	void addHeart();

	void addScoreAsteroidSmall();
	void addScoreAsteroidBig();
	void addScoreClearAsteroids();

	void pauseGame(double fps);

public:
	Space();
	Space(int difficulty, double maxFps);

	void game();
};

#endif