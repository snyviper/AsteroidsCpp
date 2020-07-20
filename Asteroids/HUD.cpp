#include "HUD.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

//private:

Cursor HUD::cursor = Cursor();

void HUD::printHealth(int hearts) {
	cursor.goToHealth();
	std::cout << "Health:";
	printHearts(hearts);
}
void HUD::printHearts(int hearts) {
	std::string allHearts = "";
	cursor.goToHearts();
	for (int i = 0; i < hearts; i++)
		allHearts += HEART;
	std::cout << std::setfill(' ') << std::setw(4) << std::left << allHearts;
}
void HUD::printScoreWord(int score, ScreenLimit limit) {
	cursor.goToScoreWord(6, limit);
	std::cout << "Score: ";
	printScoreValue(score, limit);
}
void HUD::printTopBorder(ScreenLimit limit) {
	std::string topBorder = "";
	cursor.goToTopBorder();
	for (int i = 0; i < limit.getX(); i++) {
		topBorder += '_';
	}
	std::cout << topBorder;
}
void HUD::printBottomBorder(ScreenLimit limit) {
	std::string bottomBorder = "";
	cursor.goToBottomBorder(limit);
	for (int i = 0; i < limit.getX()-9; i++) {
		bottomBorder += BOTTOMBORDER;
	}
	std::cout << bottomBorder;
}
void HUD::printFPSName(double fps, ScreenLimit limit) {
	cursor.goToFPSName(limit);
	std::cout << "FPS:";
	printFPS(fps, limit);
}

void HUD::printTitle(ScreenLimit limit) {
	cursor.goToTitle(limit);
	std::cout << "ASTEROIDS";
}
void HUD::printNewGame(ScreenLimit limit) {
	cursor.goToNewGame(limit);
	std::cout << "NEW GAME";
}
void HUD::printExit(ScreenLimit limit) {
	cursor.goToExit(limit);
	std::cout << "EXIT";
}

//public:
HUD::HUD() {}

void HUD::printMainScreen(ScreenLimit limit) {
	system("cls");
	cursor.goToNewGame(limit);
	std::cout << "New Game";
	cursor.goToExit(limit);
	std::cout << "Exit";
	printHelpIcon(limit);
}
void HUD::printArrowNewGame(ScreenLimit limit) {
	cursor.goToArrowNewGame(limit);
	std::cout << ARROW;
}
void HUD::unprintArrowNewGame(ScreenLimit limit) {
	cursor.goToArrowNewGame(limit);
	std::cout << ' ';
}
void HUD::printArrowExit(ScreenLimit limit) {
	cursor.goToArrowExit(limit);
	std::cout << ARROW;
}
void HUD::unprintArrowExit(ScreenLimit limit) {
	cursor.goToArrowExit(limit);
	std::cout << ' ';
}

void HUD::printDifficultySelection(ScreenLimit limit) {
	system("cls");
	cursor.goToSelectDifficulty(limit);
	std::cout << "Select Difficulty";
	cursor.goToDifficultyEasy(limit);
	std::cout << "Easy";
	cursor.goToDifficultyNormal(limit);
	std::cout << "Normal";
	cursor.goToDifficultyHard(limit);
	std::cout << "Hard";
	cursor.goToDifficultyExtreme(limit);
	std::cout << "Extreme";
	cursor.goToDifficultyBack(limit);
	std::cout << "Back";
	printHelpIcon(limit);
}
void HUD::printDifficultyArrowEasy(ScreenLimit limit) {
	cursor.goToDifficultyArrowEasy(limit);
	std::cout << ARROW;
}
void HUD::unprintDifficultyArrowEasy(ScreenLimit limit) {
	cursor.goToDifficultyArrowEasy(limit);
	std::cout << ' ';
}
void HUD::printDifficultyArrowNormal(ScreenLimit limit) {
	cursor.goToDifficultyArrowNormal(limit);
	std::cout << ARROW;
}
void HUD::unprintDifficultyArrowNormal(ScreenLimit limit) {
	cursor.goToDifficultyArrowNormal(limit);
	std::cout << ' ';
}
void HUD::printDifficultyArrowHard(ScreenLimit limit) {
	cursor.goToDifficultyArrowHard(limit);
	std::cout << ARROW;
}
void HUD::unprintDifficultyArrowHard(ScreenLimit limit) {
	cursor.goToDifficultyArrowHard(limit);
	std::cout << ' ';
}
void HUD::printDifficultyArrowExtreme(ScreenLimit limit) {
	cursor.goToDifficultyArrowExtreme(limit);
	std::cout << ARROW;
}
void HUD::unprintDifficultyArrowExtreme(ScreenLimit limit) {
	cursor.goToDifficultyArrowExtreme(limit);
	std::cout << ' ';
}
void HUD::printDifficultyArrowBack(ScreenLimit limit) {
	cursor.goToDifficultyArrowBack(limit);
	std::cout << ARROW;
}
void HUD::unprintDifficultyArrowBack(ScreenLimit limit) {
	cursor.goToDifficultyArrowBack(limit);
	std::cout << ' ';
}

void HUD::blinkShip(Ship ship, ScreenLimit limit, bool visible) {
	
	if (visible) {
		printShip(ship, limit);
	}
	else {
		cursor.goToXY(ship.getX(), ship.getY(), limit);
		std::cout << ' ';
		cursor.goToXY(ship.getScopeX(), ship.getScopeY(), limit);
		std::cout << ' ';
	}
}
void HUD::printShip(Ship ship, ScreenLimit limit) {
	cursor.goToXY(ship.getX(), ship.getY(), limit);
	std::cout << SHIP_BODY;
	cursor.goToXY(ship.getScopeX(), ship.getScopeY(), limit);
	// 7 0 1
	// 6   2
	// 5 4 3
	switch (ship.getFacing()) {
		case 0:
			std::cout << FACE_VERTICAL;
			break;
		case 1:
			std::cout << FACE_45_DEGREES;
			break;
		case 2:
			std::cout << FACE_HORIZONTAL;
			break;
		case 3:
			std::cout << FACE_135_DEGREES;
			break;
		case 4:
			std::cout << FACE_VERTICAL;
			break;
		case 5:
			std::cout << FACE_45_DEGREES;
			break;
		case 6:
			std::cout << FACE_HORIZONTAL;
			break;
		case 7:
			std::cout << FACE_135_DEGREES;
			break;
	}
}

void HUD::printBullet(Coords bulletPosition, ScreenLimit limit) {
	cursor.goToXY(bulletPosition.getX(), bulletPosition.getY(), limit);
	std::cout << BULLET;
}

void HUD::printAsteroid(Asteroid asteroid, ScreenLimit limit) {
	if (asteroid.isBig()) {
		int tempX, tempY;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				tempX = asteroid.getX() + j;
				tempY = asteroid.getY() + i;
				if (tempX < 0)
					tempX += limit.getSpaceX();
				if (tempY < 0)
					tempY += limit.getSpaceY();
				if (tempX >= limit.getSpaceX())
					tempX -= limit.getSpaceX();
				if (tempY >= limit.getSpaceY())
					tempY -= limit.getSpaceY();
				cursor.goToXY(tempX, tempY, limit);
				std::cout << ASTEROID;
			}
		}
	}
	else {
		cursor.goToXY(asteroid.getX(), asteroid.getY(), limit);
		std::cout << ASTEROID;
	}
}

void HUD::printInstructions(ScreenLimit limit) {
	cursor.goToInstruction(limit);
	std::cout << "Hit J";
	cursor.goToInstruction2(limit);
	std::cout << "to start";
}

void HUD::refreshHUD(int hearts, int score, double fps, ScreenLimit limit) {
	system("cls");
	printHealth(hearts);
	printTopBorder(limit);
	printScoreWord(score, limit);
	printFPSName(fps, limit);
	printBottomBorder(limit);
}
void HUD::cleanScreen() {
	system("cls");
}

void HUD::startMainScreen(ScreenLimit limit) {
	printTitle(limit);
	printNewGame(limit);
	printExit(limit);
	printHelp(limit);
}

void HUD::printScoreValue(int score, ScreenLimit limit) {
	cursor.goToScoreValue(6, limit);
	if (score > 999999)
		std::cout << "999999";
	else
		std::cout << std::internal << std::setfill('0') << std::setw(6) << score;
}

void HUD::printFPS(double fps, ScreenLimit limit) {
	cursor.goToFPS(limit);
	if (fps > 99.9)
		std::cout << "99.9";
	else
		std::cout << std::internal << std::fixed << std::setprecision(1) << std::setfill('0') << std::setw(4) << fps;
}

void HUD::printHelp(ScreenLimit limit) {
	system("cls");
	cursor.goToHelpW(limit);
	std::cout << "w: move up in menu / accelerate";
	cursor.goToHelpS(limit);
	std::cout << "s: move down in menu";
	cursor.goToHelpA(limit);
	std::cout << "a: turn left";
	cursor.goToHelpD(limit);
	std::cout << "d: turn right";
	cursor.goToHelpJ(limit);
	std::cout << "j: accept / start the game / pause the game";
	cursor.goToHelpK(limit);
	std::cout << "k: shoot";
	_getch();
}

void HUD::printHelpIcon(ScreenLimit limit) {
	cursor.goToHelpTop(limit);
	std::cout << HELP_TOP_LEFT << HELP_HORIZONTAL << HELP_HORIZONTAL << HELP_HORIZONTAL << HELP_TOP_RIGHT;
	cursor.goToHelpMiddle(limit);
	std::cout << HELP_VERTICAL << " H " << HELP_VERTICAL;
	cursor.goToHelpBottom(limit);
	std::cout << HELP_BOTTOM_LEFT << HELP_HORIZONTAL << HELP_HORIZONTAL << HELP_HORIZONTAL << HELP_BOTTOM_RIGHT;
}

void HUD::printPause(ScreenLimit limit) {
	cursor.goToPaused(limit);
	std::cout << "* Paused *";
}