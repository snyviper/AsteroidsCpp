#ifndef HUD_H
#define HUD_H

#include "Cursor.h"
#include "ScreenLimit.h"
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

	static void printHealth(int hearts);
	static void printHearts(int hearts);
	static void printTopBorder(ScreenLimit limit);
	static void printScoreWord(int score, ScreenLimit limit);
	static void printFPSName(double fps, ScreenLimit limit);
	static void printBottomBorder(ScreenLimit limit);

	static void printTitle(ScreenLimit limit);
	static void printNewGame(ScreenLimit limit);
	static void printExit(ScreenLimit limit);

public:
	HUD();

	static void printMainScreen(ScreenLimit limit);
	static void printArrowNewGame(ScreenLimit limit);
	static void unprintArrowNewGame(ScreenLimit limit);
	static void printArrowExit(ScreenLimit limit);
	static void unprintArrowExit(ScreenLimit limit);

	static void printDifficultySelection(ScreenLimit limit);
	static void printDifficultyArrowEasy(ScreenLimit limit);
	static void unprintDifficultyArrowEasy(ScreenLimit limit);
	static void printDifficultyArrowNormal(ScreenLimit limit);
	static void unprintDifficultyArrowNormal(ScreenLimit limit);
	static void printDifficultyArrowHard(ScreenLimit limit);
	static void unprintDifficultyArrowHard(ScreenLimit limit);
	static void printDifficultyArrowExtreme(ScreenLimit limit);
	static void unprintDifficultyArrowExtreme(ScreenLimit limit);
	static void printDifficultyArrowBack(ScreenLimit limit);
	static void unprintDifficultyArrowBack(ScreenLimit limit);

	static void blinkShip(Ship ship, ScreenLimit limit, bool visible);
	static void printShip(Ship ship, ScreenLimit limit);
	static void printBullet(Coords bulletPosition, ScreenLimit limit);
	static void printAsteroid(Asteroid asteroid, ScreenLimit limit);

	static void printInstructions(ScreenLimit limit);

	static void refreshHUD(int hearts, int score, double fps, ScreenLimit limit);
	static void cleanScreen();
	static void startMainScreen(ScreenLimit limit);

	static void printScoreValue(int score, ScreenLimit limit);
	static void printFPS(double fps, ScreenLimit limit);

	static void printHelp(ScreenLimit limit);
	static void printHelpIcon(ScreenLimit limit);

	static void printPause(ScreenLimit limit);
};

#endif