#ifndef SPACE_H
#define SPACE_H

#include <vector>
#include <ctime>
#include "Ship.h"
#include "Asteroid.h"
#include "ScreenLimit.h"

class Space
{
//private
	int frame;
	int stage;
	int hearts;
	int score;
	Ship ship;
	std::vector<Asteroid> asteroid;

	void nextFrame();

	void resetAsteroids(int difficulty, ScreenLimit limit);
	void damageAsteroid(int index, int difficulty, ScreenLimit limit);

	bool asteroidHitShip(ScreenLimit limit);

	void movePrintAsteroids(ScreenLimit limit);
	void printAsteroids(ScreenLimit limit);

	void printBullets(ScreenLimit limit);

	void damageShip();

	double getFPS(clock_t refreshRate);

	void beforeStartGame(int difficulty, ScreenLimit limit);
	void startBattle(int difficulty, ScreenLimit limit);

	void newStage(int difficulty, ScreenLimit limit);

	void setHearts(int difficulty);
	int getHearts();
	void removeHeart();
	void addHeart();

	void addScoreAsteroidSmall(int difficulty, int stage);
	void addScoreAsteroidBig(int difficulty, int stage);
	void addScoreClearAsteroids(int difficulty, int stage);

	bool pauseGame(ScreenLimit limit);

public:
	//Space();
	Space(int difficulty, ScreenLimit limit);

	void game(int difficulty, ScreenLimit limit);
};

#endif