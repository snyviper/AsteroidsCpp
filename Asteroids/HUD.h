#ifndef HUD_H
#define HUD_H

#include "Cursor.h"
#include "Ship.h"
#include "Asteroid.h"

class HUD
{
//private:
	static const char ARROW = 175, BOTTOMBORDER = 238, ASTEROID = 219, HEART = 3, BULLET = 250;
	static const char SHIP_BODY = 'O', FACE_HORIZONTAL = 196, FACE_VERTICAL = '|', FACE_135_DEGREES = '\\', FACE_45_DEGREES = '/';
	static const char HELP_TOP_LEFT = 201, HELP_HORIZONTAL = 205, HELP_TOP_RIGHT = 187;
	static const char HELP_VERTICAL = 186, HELP_BOTTOM_LEFT = 200, HELP_BOTTOM_RIGHT = 188;
	static Cursor cursor;

	static void cleanSpace();
	static void printHealth(int hearts);
	static void printTopBorder();
	static void printScoreName(int score);
	static void printFPSName(double fps);
	static void printBottomBorder();

	static void printTitle();
	static void printNewGame();
	static void printExit();

public:
	HUD();

	static void printMainScreen();
	static void printArrowNewGame();
	static void unprintArrowNewGame();
	static void printArrowExit();
	static void unprintArrowExit();

	static void printDifficultySelection();
	static void printDifficultyArrowEasy();
	static void unprintDifficultyArrowEasy();
	static void printDifficultyArrowNormal();
	static void unprintDifficultyArrowNormal();
	static void printDifficultyArrowHard();
	static void unprintDifficultyArrowHard();
	static void printDifficultyArrowExtreme();
	static void unprintDifficultyArrowExtreme();
	static void printDifficultyArrowBack();
	static void unprintDifficultyArrowBack();

	static void blinkShip(Ship ship, bool* visible);
	static void printShip(Ship ship);
	static void printBullet(Bullet bullet);
	static void printAsteroid(Asteroid asteroid);

	static void printInstructionsStart();

	static void printDeadShip(Ship ship);
	static void printFinalScore(int score);

	static void printInstructionsDead();

	static void printHUD(int hearts, int score, double fps);
	static void refreshHUD(double fps);
	static void startMainScreen();

	static void printHearts(int hearts);
	static void printScoreValue(int score);
	static void printFPSValue(double fps);

	static void printHelp();
	static void printHelpIcon();

	static void printPause();
};

#endif