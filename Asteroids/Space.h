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
	void printAsteroids() const;

	void printBullets() const;

	void damageShip();

	void help(double fps) const;

	double getFPS(clock_t refreshRate) const;

	bool spaceHasAnyBullet() const;
	bool spaceHasAllBullets() const;

	void beforeStartBattle();
	void startBattle();

	void newStage();

	void setHearts();

	void addScoreAsteroidSmall();
	void addScoreAsteroidBig();
	void addScoreClearAsteroids();

	void pauseGame(double fps) const;

public:
	Space();
	Space(int difficulty, double maxFps);

	void game();
};

#endif