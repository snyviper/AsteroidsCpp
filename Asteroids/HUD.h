#ifndef HUD_H
#define HUD_H

#include "Cursor.h"
#include "ScreenLimit.h"
#include "Ship.h"
#include "Asteroid.h"

class HUD
{
//private:
	static const char SCOPE = 196, BULLET = 250, BOTTOMBORDER = 238, ASTEROID = 219, HEART = 3, FACE_HORIZONTAL = 196;
	static const char HELP_TOP_LEFT = 201, HELP_HORIZONTAL = 205, HELP_TOP_RIGHT = 187;
	static const char HELP_VERTICAL = 186, HELP_BOTTOM_LEFT = 200, HELP_BOTTOM_RIGHT = 188, ARROW = 175;
	int hearts;
	int score;
	Cursor cursor;

	void printHealth();
	void printHearts();
	void printTopBorder(ScreenLimit limit);
	void printScoreWord(ScreenLimit limit);
	void printFPSName(float fps, ScreenLimit limit);
	void printBottomBorder(ScreenLimit limit);

	void printTitle(ScreenLimit limit);
	void printNewGame(ScreenLimit limit);
	void printExit(ScreenLimit limit);
public:
	HUD();
	HUD(int difficulty);

	void blinkShip(Ship ship, ScreenLimit limit, bool visible);
	void printShip(Ship ship, ScreenLimit limit);
	void printBullet(Coords bulletPosition, ScreenLimit limit);
	void printAsteroid(Asteroid asteroid, ScreenLimit limit);

	void printInstructions(ScreenLimit limit);

	void setHearts(int difficulty);
	int getHearts();
	void removeHeart();
	void addHeart();

	void addScoreAsteroidSmall(int difficulty, int stage);
	void addScoreAsteroidBig(int difficulty, int stage);
	void addScoreClearAsteroids(int difficulty, int stage);

	void refreshHUD(float fps, ScreenLimit limit);
	void cleanScreen();
	void startMainScreen(ScreenLimit limit);

	void printArrowNewGame(ScreenLimit limit);
	void printArrowExit(ScreenLimit limit);

	void printScoreValue(ScreenLimit limit);
	void printFPS(float fps, ScreenLimit limit);

	Cursor getCursor();
	void printHelp(ScreenLimit limit);
	void printHelpIcon(ScreenLimit limit);

	bool pause(ScreenLimit limit);
};

#endif