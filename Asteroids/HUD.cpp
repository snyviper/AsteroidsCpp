#include "HUD.h"
#include "ScreenLimit.h"
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
void HUD::printScoreWord(int score) {
	cursor.goToScoreWord(6);
	std::cout << "Score: ";
	printScoreValue(score);
}
void HUD::printTopBorder() {
	std::string topBorder = "";
	cursor.goToTopBorder();
	for (int i = 0; i < ScreenLimit().getX(); i++) {
		topBorder += '_';
	}
	std::cout << topBorder;
}
void HUD::printBottomBorder() {
	std::string bottomBorder = "";
	cursor.goToBottomBorder();
	for (int i = 0; i < ScreenLimit().getX()-9; i++) {
		bottomBorder += BOTTOMBORDER;
	}
	std::cout << bottomBorder;
}
void HUD::printFPSName(double fps) {
	cursor.goToFPSName();
	std::cout << "FPS:";
	printFPS(fps);
}

void HUD::printTitle() {
	cursor.goToTitle();
	std::cout << "ASTEROIDS";
}
void HUD::printNewGame() {
	cursor.goToNewGame();
	std::cout << "NEW GAME";
}
void HUD::printExit() {
	cursor.goToExit();
	std::cout << "EXIT";
}

//public:
HUD::HUD() {}

void HUD::printMainScreen() {
	system("cls");
	cursor.goToNewGame();
	std::cout << "New Game";
	cursor.goToExit();
	std::cout << "Exit";
	printHelpIcon();
}
void HUD::printArrowNewGame() {
	cursor.goToArrowNewGame();
	std::cout << ARROW;
}
void HUD::unprintArrowNewGame() {
	cursor.goToArrowNewGame();
	std::cout << ' ';
}
void HUD::printArrowExit() {
	cursor.goToArrowExit();
	std::cout << ARROW;
}
void HUD::unprintArrowExit() {
	cursor.goToArrowExit();
	std::cout << ' ';
}

void HUD::printDifficultySelection() {
	system("cls");
	cursor.goToSelectDifficulty();
	std::cout << "Select Difficulty";
	cursor.goToDifficultyEasy();
	std::cout << "Easy";
	cursor.goToDifficultyNormal();
	std::cout << "Normal";
	cursor.goToDifficultyHard();
	std::cout << "Hard";
	cursor.goToDifficultyExtreme();
	std::cout << "Extreme";
	cursor.goToDifficultyBack();
	std::cout << "Back";
	printHelpIcon();
}
void HUD::printDifficultyArrowEasy() {
	cursor.goToDifficultyArrowEasy();
	std::cout << ARROW;
}
void HUD::unprintDifficultyArrowEasy() {
	cursor.goToDifficultyArrowEasy();
	std::cout << ' ';
}
void HUD::printDifficultyArrowNormal() {
	cursor.goToDifficultyArrowNormal();
	std::cout << ARROW;
}
void HUD::unprintDifficultyArrowNormal() {
	cursor.goToDifficultyArrowNormal();
	std::cout << ' ';
}
void HUD::printDifficultyArrowHard() {
	cursor.goToDifficultyArrowHard();
	std::cout << ARROW;
}
void HUD::unprintDifficultyArrowHard() {
	cursor.goToDifficultyArrowHard();
	std::cout << ' ';
}
void HUD::printDifficultyArrowExtreme() {
	cursor.goToDifficultyArrowExtreme();
	std::cout << ARROW;
}
void HUD::unprintDifficultyArrowExtreme() {
	cursor.goToDifficultyArrowExtreme();
	std::cout << ' ';
}
void HUD::printDifficultyArrowBack() {
	cursor.goToDifficultyArrowBack();
	std::cout << ARROW;
}
void HUD::unprintDifficultyArrowBack() {
	cursor.goToDifficultyArrowBack();
	std::cout << ' ';
}

void HUD::blinkShip(Ship ship, bool* visible) {
	
	if (*visible) {
		printShip(ship);
		*visible = false;
	}
	else {
		cursor.goToPosition(ship.getPosition());
		std::cout << ' ';
		cursor.goToPosition(ship.getScopePosition());
		std::cout << ' ';
		*visible = true;
	}
}
void HUD::printShip(Ship ship) {
	cursor.goToPosition(ship.getPosition());
	std::cout << SHIP_BODY;
	cursor.goToPosition(ship.getScopePosition());
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

void HUD::printBullet(Bullet bullet) {
	cursor.goToPosition(bullet.getPosition());
	std::cout << BULLET;
}

void HUD::printAsteroid(Asteroid asteroid) {
	if (asteroid.isBig()) {
		int tempX, tempY;
		for (int i = 0; i < 9; i++) {
			tempX = asteroid.getPositionBig()[i].getX();
			tempY = asteroid.getPositionBig()[i].getY();
			if (tempX < 0)
				tempX += ScreenLimit().getSpaceX();
			else if (tempX >= ScreenLimit().getSpaceX())
				tempX -= ScreenLimit().getSpaceX();
			if (tempY < 0)
				tempY += ScreenLimit().getSpaceY();
			else if (tempY >= ScreenLimit().getSpaceY())
				tempY -= ScreenLimit().getSpaceY();
			cursor.goToXY(tempX, tempY);
			std::cout << ASTEROID;
		}
	}
	else {
		cursor.goToPosition(asteroid.getPositionSmall());
		std::cout << ASTEROID;
	}
}

void HUD::printInstructionsStart() {
	cursor.goToInstructionHitJ();
	std::cout << "Hit J";
	cursor.goToInstructionToStart();
	std::cout << "to start";
}

void HUD::printDeadShip(Ship ship) {
	printShip(ship);
	cursor.goToPosition(ship.getPosition());
	std::cout << 'X';
}
void HUD::printFinalScore(int score) {
	double temp = score;
	int figures = 1;
	while (temp >= 1) {
		temp /= 10;
		if (temp >= 1)
			figures++;
	}
	cursor.goToFinalScore(figures);
	std::cout << "Score: " << score;
}

void HUD::printInstructionsDead() {
	cursor.goToInstructionHitJ();
	std::cout << "Hit J";
	cursor.goToInstructionToExit();
	std::cout << "to exit";
}

void HUD::refreshHUD(int hearts, int score, double fps) {
	system("cls");
	printHealth(hearts);
	printTopBorder();
	printScoreWord(score);
	printFPSName(fps);
	printBottomBorder();
}

void HUD::startMainScreen() {
	printTitle();
	printNewGame();
	printExit();
	printHelp();
}

void HUD::printScoreValue(int score) {
	cursor.goToScoreValue(6);
	if (score > 999999)
		std::cout << "999999";
	else
		std::cout << std::internal << std::setfill('0') << std::setw(6) << score;
}

void HUD::printFPS(double fps) {
	cursor.goToFPS();
	if (fps > 99.9)
		std::cout << "99.9";
	else
		std::cout << std::internal << std::fixed << std::setprecision(1) << std::setfill('0') << std::setw(4) << fps;
}

void HUD::printHelp() {
	system("cls");
	cursor.goToHelpW();
	std::cout << "w: move up in menu / accelerate";
	cursor.goToHelpS();
	std::cout << "s: move down in menu";
	cursor.goToHelpA();
	std::cout << "a: turn left";
	cursor.goToHelpD();
	std::cout << "d: turn right";
	cursor.goToHelpJ();
	std::cout << "j: accept / start the game / pause the game";
	cursor.goToHelpK();
	std::cout << "k: shoot";
	_getch();
}

void HUD::printHelpIcon() {
	cursor.goToHelpTop();
	std::cout << HELP_TOP_LEFT << HELP_HORIZONTAL << HELP_HORIZONTAL << HELP_HORIZONTAL << HELP_TOP_RIGHT;
	cursor.goToHelpMiddle();
	std::cout << HELP_VERTICAL << " H " << HELP_VERTICAL;
	cursor.goToHelpBottom();
	std::cout << HELP_BOTTOM_LEFT << HELP_HORIZONTAL << HELP_HORIZONTAL << HELP_HORIZONTAL << HELP_BOTTOM_RIGHT;
}

void HUD::printPause() {
	cursor.goToPaused();
	std::cout << "* Paused *";
}