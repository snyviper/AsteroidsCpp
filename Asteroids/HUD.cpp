#include "HUD.h"
#include "ScreenLimit.h"
#include "Cursor.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

namespace HUD {
	namespace {
		const char ARROW = 175, BOTTOMBORDER = 238, ASTEROID = 219, HEART = 3, BULLET = 250;
		const char SHIP_BODY = 'O', FACE_HORIZONTAL = 196, FACE_VERTICAL = '|', FACE_135_DEGREES = '\\', FACE_45_DEGREES = '/';
		const char HELP_TOP_LEFT = 201, HELP_HORIZONTAL = 205, HELP_TOP_RIGHT = 187;
		const char HELP_VERTICAL = 186, HELP_BOTTOM_LEFT = 200, HELP_BOTTOM_RIGHT = 188;

		void printHelpIcon() {
			Cursor::goToHelpIconTop();
			std::cout << HELP_TOP_LEFT << HELP_HORIZONTAL << HELP_HORIZONTAL << HELP_HORIZONTAL << HELP_TOP_RIGHT;
			Cursor::goToHelpIconMiddle();
			std::cout << HELP_VERTICAL << " H " << HELP_VERTICAL;
			Cursor::goToHelpIconBottom();
			std::cout << HELP_BOTTOM_LEFT << HELP_HORIZONTAL << HELP_HORIZONTAL << HELP_HORIZONTAL << HELP_BOTTOM_RIGHT;
		}
		void cleanSpace() {
			Cursor::goToSpace();
			std::cout << ScreenLimit::getCleanSpace();
		}
		void printHealth(int hearts) {
			Cursor::goToHealth();
			std::cout << "Health:";
			printHearts(hearts);
		}
		void printScoreName(int score) {
			Cursor::goToScoreWord(6);
			std::cout << "Score: ";
			printScoreValue(score);
		}
		void printTopBorder() {
			std::string topBorder = "";
			Cursor::goToTopBorder();
			for (int i = 0; i < ScreenLimit::getX(); i++)
				topBorder += '_';
			std::cout << topBorder;
		}
		void printBottomBorder() {
			std::string bottomBorder = "";
			Cursor::goToBottomBorder();
			for (int i = 0; i < ScreenLimit::getX() - 9; i++)
				bottomBorder += BOTTOMBORDER;
			std::cout << bottomBorder;
		}
		void printFPSValue(double fps) {
			Cursor::goToFPS();
			if (fps > 99.9)
				std::cout << "99.9";
			else
				std::cout << std::internal << std::fixed << std::setprecision(1) << std::setfill('0') << std::setw(4) << fps;
		}
		void printFPSName(double fps) {
			Cursor::goToFPSName();
			std::cout << "FPS:";
			printFPSValue(fps);
		}

		void printTitle() {
			Cursor::goToTitle();
			std::cout << "ASTEROIDS";
		}
		void printNewGame() {
			Cursor::goToNewGame();
			std::cout << "NEW GAME";
		}
		void printExit() {
			Cursor::goToExit();
			std::cout << "EXIT";
		}
	}

	void printMainScreen() {
		system("cls");
		printTitle();
		printNewGame();
		printExit();
		printHelpIcon();
	}
	void printArrowNewGame() {
		Cursor::goToArrowNewGame();
		std::cout << ARROW;
	}
	void unprintArrowNewGame() {
		Cursor::goToArrowNewGame();
		std::cout << ' ';
	}
	void printArrowExit() {
		Cursor::goToArrowExit();
		std::cout << ARROW;
	}
	void unprintArrowExit() {
		Cursor::goToArrowExit();
		std::cout << ' ';
	}

	void printDifficultySelection() {
		system("cls");
		Cursor::goToSelectDifficulty();
		std::cout << "Select Difficulty";
		Cursor::goToDifficultyEasy();
		std::cout << "Easy";
		Cursor::goToDifficultyNormal();
		std::cout << "Normal";
		Cursor::goToDifficultyHard();
		std::cout << "Hard";
		Cursor::goToDifficultyExtreme();
		std::cout << "Extreme";
		Cursor::goToDifficultyBack();
		std::cout << "Back";
		printHelpIcon();
	}
	void printDifficultyArrowEasy() {
		Cursor::goToDifficultyArrowEasy();
		std::cout << ARROW;
	}
	void unprintDifficultyArrowEasy() {
		Cursor::goToDifficultyArrowEasy();
		std::cout << ' ';
	}
	void printDifficultyArrowNormal() {
		Cursor::goToDifficultyArrowNormal();
		std::cout << ARROW;
	}
	void unprintDifficultyArrowNormal() {
		Cursor::goToDifficultyArrowNormal();
		std::cout << ' ';
	}
	void printDifficultyArrowHard() {
		Cursor::goToDifficultyArrowHard();
		std::cout << ARROW;
	}
	void unprintDifficultyArrowHard() {
		Cursor::goToDifficultyArrowHard();
		std::cout << ' ';
	}
	void printDifficultyArrowExtreme() {
		Cursor::goToDifficultyArrowExtreme();
		std::cout << ARROW;
	}
	void unprintDifficultyArrowExtreme() {
		Cursor::goToDifficultyArrowExtreme();
		std::cout << ' ';
	}
	void printDifficultyArrowBack() {
		Cursor::goToDifficultyArrowBack();
		std::cout << ARROW;
	}
	void unprintDifficultyArrowBack() {
		Cursor::goToDifficultyArrowBack();
		std::cout << ' ';
	}

	void blinkShip(Ship ship, bool* visible) {

		if (*visible) {
			printShip(ship);
			*visible = false;
		}
		else {
			Cursor::goToPosition(ship.getPosition());
			std::cout << ' ';
			Cursor::goToPosition(ship.getScopePosition());
			std::cout << ' ';
			*visible = true;
		}
	}
	void printShip(Ship ship) {
		Cursor::goToPosition(ship.getPosition());
		std::cout << SHIP_BODY;
		Cursor::goToPosition(ship.getScopePosition());
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

	void printBullet(Bullet bullet) {
		Cursor::goToPosition(bullet.getPosition());
		std::cout << BULLET;
	}

	void printAsteroid(Asteroid asteroid) {
		if (asteroid.isBig()) {
			int tempX, tempY;
			for (int i = 0; i < 9; i++) {
				tempX = asteroid.getPositionBig()[i].getX();
				tempY = asteroid.getPositionBig()[i].getY();
				if (tempX < 0)
					tempX += ScreenLimit::getSpaceX();
				else if (tempX >= ScreenLimit::getSpaceX())
					tempX -= ScreenLimit::getSpaceX();
				if (tempY < 0)
					tempY += ScreenLimit::getSpaceY();
				else if (tempY >= ScreenLimit::getSpaceY())
					tempY -= ScreenLimit::getSpaceY();
				Cursor::goToXY(tempX, tempY);
				std::cout << ASTEROID;
			}
		}
		else {
			Cursor::goToPosition(asteroid.getPositionSmall());
			std::cout << ASTEROID;
		}
	}

	void printInstructionsStart() {
		Cursor::goToInstructionHitJ();
		std::cout << "Hit J";
		Cursor::goToInstructionToStart();
		std::cout << "to start";
	}

	void printDeadShip(Ship ship) {
		printShip(ship);
		Cursor::goToPosition(ship.getPosition());
		std::cout << 'X';
	}
	void printFinalScore(int score) {
		double temp = score;
		int figures = 1;
		while (temp >= 1) {
			temp /= 10;
			if (temp >= 1)
				figures++;
		}
		Cursor::goToFinalScore(figures);
		std::cout << "Score: " << score;
	}

	void printInstructionsDead() {
		Cursor::goToInstructionHitJ();
		std::cout << "Hit J";
		Cursor::goToInstructionToExit();
		std::cout << "to exit";
	}

	void printHUD(int hearts, int score, double fps) {
		system("cls");
		printHealth(hearts);
		printTopBorder();
		printScoreName(score);
		printFPSName(fps);
		printBottomBorder();
	}
	void refreshHUD(double fps) {
		cleanSpace();
		printFPSValue(fps);
	}

	void printHearts(int hearts) {
		std::string allHearts = "";
		Cursor::goToHearts();
		for (int i = 0; i < hearts; i++)
			allHearts += HEART;
		std::cout << std::setfill(' ') << std::setw(4) << std::left << allHearts;
	}
	void printScoreValue(int score) {
		Cursor::goToScoreValue(6);
		if (score > 999999)
			std::cout << "999999";
		else
			std::cout << std::internal << std::setfill('0') << std::setw(6) << score;
	}

	void printHelp() {
		system("cls");
		Cursor::goToHelpW();
		std::cout << "w: move up in menu / accelerate";
		Cursor::goToHelpS();
		std::cout << "s: move down in menu";
		Cursor::goToHelpA();
		std::cout << "a: turn left";
		Cursor::goToHelpD();
		std::cout << "d: turn right";
		Cursor::goToHelpJ();
		std::cout << "j: accept / start the game / pause the game";
		Cursor::goToHelpK();
		std::cout << "k: shoot";
		_getch();
	}

	void printPause() {
		Cursor::goToPaused();
		std::cout << "* Paused *";
	}
}