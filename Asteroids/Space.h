#ifndef SPACE_H
#define SPACE_H

#include <vector>
#include <ctime>
#include "Ship.h"
#include "Asteroid.h"
#include "Sounds.h"

class Space : Sounds
{
//private
	int frame;
	int stage;
	int hearts;
	int score;
	Ship ship;
	std::vector<Asteroid> asteroid;

	void nextFrame();

	void resetAsteroids(int difficulty);
	void damageAsteroid(int index, int difficulty);

	bool asteroidHitShip();

	void movePrintAsteroids();
	void printAsteroids();

	void printBullets();

	void damageShip();

	void help();

	double getFPS(clock_t refreshRate);

	void beforeStartGame(int difficulty);
	void startBattle(int difficulty);

	void newStage(int difficulty);

	void setHearts(int difficulty);
	int getHearts();
	void removeHeart();
	void addHeart();

	void addScoreAsteroidSmall(int difficulty, int stage);
	void addScoreAsteroidBig(int difficulty, int stage);
	void addScoreClearAsteroids(int difficulty, int stage);

	void pauseGame(double fps);

public:
	Space();
	Space(int difficulty);

	void game(int difficulty);
};

#endif