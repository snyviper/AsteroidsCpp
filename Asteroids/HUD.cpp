#include "HUD.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

//private:

void HUD::printHealth() {
	cursor.goToHealth();
	std::cout << "Health:";
	printHearts();
}
void HUD::printHearts() {
	std::string allHearts = "";
	cursor.goToHearts();
	for (int i = 0; i < hearts; i++) {
		allHearts += HEART;
	}
	std::cout << std::setfill(' ') << std::setw(4) << std::left << allHearts;
}
void HUD::printScoreWord(ScreenLimit limit) {
	cursor.goToScoreWord(6, limit);
	std::cout << "Score: ";
	printScoreValue(limit);
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
void HUD::printFPSName(float fps, ScreenLimit limit) {
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
HUD::HUD() {
	hearts = 3;
	score = 0;
}
HUD::HUD(int difficulty) {
	setHearts(difficulty);
	score = 0;
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
	std::cout << 'O';
	cursor.goToXY(ship.getScopeX(), ship.getScopeY(), limit);
	// 7 0 1
	// 6   2
	// 5 4 3
	switch (ship.getFacing()) {
		case 0:
			std::cout << '|';
			break;
		case 1:
			std::cout << '/';
			break;
		case 2:
			std::cout << FACE_HORIZONTAL;
			break;
		case 3:
			std::cout << '\\';
			break;
		case 4:
			std::cout << '|';
			break;
		case 5:
			std::cout << '/';
			break;
		case 6:
			std::cout << FACE_HORIZONTAL;
			break;
		case 7:
			std::cout << '\\';
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

void HUD::setHearts(int difficulty) {
	switch (difficulty) {
		case 0:
			hearts = 4;
			break;
		case 1:
			hearts = 3;
			break;
		case 2:
			hearts = 2;
			break;
		case 3:
			hearts = 1;
			break;
	}
}
int HUD::getHearts() {
	return hearts;
}
void HUD::removeHeart() {
	hearts--;
}
void HUD::addHeart() {
	hearts++;
}

void HUD::addScoreAsteroidSmall(int difficulty, int stage) {
	score += (15+stage*3)*(difficulty+1);
}
void HUD::addScoreAsteroidBig(int difficulty, int stage) {
	score += (5+stage)*(difficulty+1);
}
void HUD::addScoreClearAsteroids(int difficulty, int stage) {
	switch (difficulty) {
		case 0:
			score += 50 + stage*10;
			break;
		case 1:
			score += 100 + stage*20;
			break;
		case 2:
			score += 200 + stage*40;
			break;
		case 3:
			score += 400 + stage*80;
			break;
	}
}

void HUD::refreshHUD(float fps, ScreenLimit limit) {
	system("cls");
	printHealth();
	printTopBorder(limit);
	printScoreWord(limit);
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

void HUD::printArrowNewGame(ScreenLimit limit) {
	cursor.goToArrowNewGame(limit);
	std::cout << ARROW;
}
void HUD::printArrowExit(ScreenLimit limit) {
	cursor.goToArrowExit(limit);
	std::cout << ARROW;
}

void HUD::printScoreValue(ScreenLimit limit) {
	cursor.goToScoreValue(6, limit);
	if (score > 999999)
		std::cout << "999999";
	else
		std::cout << std::internal << std::setfill('0') << std::setw(6) << score;
}

void HUD::printFPS(float fps, ScreenLimit limit) {
	cursor.goToFPS(limit);
	if (fps > 99.9)
		std::cout << "99.9";
	else
		std::cout << std::internal << std::fixed << std::setprecision(1) << std::setfill('0') << std::setw(4) << fps;
}

Cursor HUD::getCursor() { return cursor; }

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

bool HUD::pause(ScreenLimit limit) {
	char key;
	cursor.goToPaused(limit);
	std::cout << "* Paused *";
	key = _getch();
	if (key == 'h') {
		printHelp(limit);
		return true;
	}
	else { return false; }
}