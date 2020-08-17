#include "Cursor.h"
#include "ScreenLimit.h"
#include <Windows.h>

namespace Cursor
{
	namespace { COORD cursor; }

	//Space
	void goToSpace() {
		cursor.X = 0;
		cursor.Y = 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}

	void goToXY(int x, int y) {
		if (x < ScreenLimit::getSpaceX() && y < ScreenLimit::getSpaceY()) {
			cursor.X = x;
			cursor.Y = y + 2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
		}
	}
	void goToPosition(Position position) {
		if (position.getX() < ScreenLimit::getSpaceX() && position.getY() < ScreenLimit::getSpaceY()) {
			cursor.X = position.getX();
			cursor.Y = position.getY() + 2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
		}
	}

	//HUD
	void goToHealth() {
		cursor.X = 0;
		cursor.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToHearts() {
		cursor.X = 8;
		cursor.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}

	void goToScoreWord(int figures) {
		cursor.X = ScreenLimit::getX() - figures - 7;
		cursor.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToScoreValue(int figures) {
		cursor.X = ScreenLimit::getX() - figures;
		cursor.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}

	void goToFPS() {
		cursor.X = 0;
		cursor.Y = ScreenLimit::getY() - 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToFPSName() {
		cursor.X = 5;
		cursor.Y = ScreenLimit::getY() - 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}

	void goToTopBorder() {
		cursor.X = 0;
		cursor.Y = 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToBottomBorder() {
		cursor.X = 8;
		cursor.Y = ScreenLimit::getY() - 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}

	//Message
	void goToInstructionHitJ() {
		cursor.X = (ScreenLimit::getSpaceX() / 2) - 2;
		cursor.Y = (ScreenLimit::getSpaceY() / 2) + 3;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToInstructionToStart() {
		cursor.X = (ScreenLimit::getSpaceX() / 2) - 4;
		cursor.Y = (ScreenLimit::getSpaceY() / 2) + 4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToInstructionToExit() {
		cursor.X = (ScreenLimit::getSpaceX() / 2) - 3;
		cursor.Y = (ScreenLimit::getSpaceY() / 2) + 4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}

	void goToPaused() {
		cursor.X = ScreenLimit::getSpaceX() / 2 - 5;
		cursor.Y = ScreenLimit::getSpaceY() / 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}

	void goToFinalScore(int figures) {
		cursor.X = (ScreenLimit::getSpaceX() / 2) - (figures + 7) / 2;
		cursor.Y = (ScreenLimit::getSpaceY() / 2) + 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}

	void goToHelpW() {
		cursor.X = 4;
		cursor.Y = 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToHelpA() {
		cursor.X = 4;
		cursor.Y = 3;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToHelpS() {
		cursor.X = 4;
		cursor.Y = 4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToHelpD() {
		cursor.X = 4;
		cursor.Y = 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToHelpJ() {
		cursor.X = 4;
		cursor.Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToHelpK() {
		cursor.X = 4;
		cursor.Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}

	//Menu
	void goToStart() {
		cursor.X = 0;
		cursor.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToTitle() {
		cursor.X = (ScreenLimit::getX()/2)-6;
		cursor.Y = (ScreenLimit::getY()/2)-4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToNewGame() {
		cursor.X = (ScreenLimit::getX()/2)-5;
		cursor.Y = (ScreenLimit::getY()/2)-1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToExit() {
		cursor.X = (ScreenLimit::getX()/2)-3;
		cursor.Y = ScreenLimit::getY()/2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}

	void goToArrowNewGame() {
		goToNewGame();
		cursor.X -= 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToArrowExit() {
		goToExit();
		cursor.X -= 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}

	void goToHelpIconTop() {
		cursor.X = ScreenLimit::getX() - 7;
		cursor.Y = 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToHelpIconMiddle() {
		cursor.X = ScreenLimit::getX() - 7;
		cursor.Y = 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToHelpIconBottom() {
		cursor.X = ScreenLimit::getX() - 7;
		cursor.Y = 3;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}

	void goToSelectDifficulty() {
		cursor.X = ScreenLimit::getX()/2 - 8;
		cursor.Y = ScreenLimit::getY()/2 - 4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToDifficultyEasy() {
		cursor.X = ScreenLimit::getX() / 2 - 2;
		cursor.Y = ScreenLimit::getY() / 2 - 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToDifficultyNormal() {
		cursor.X = ScreenLimit::getX() / 2 - 3;
		cursor.Y = ScreenLimit::getY() / 2 - 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToDifficultyHard() {
		cursor.X = ScreenLimit::getX() / 2 - 2;
		cursor.Y = ScreenLimit::getY() / 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToDifficultyExtreme() {
		cursor.X = ScreenLimit::getX() / 2 - 3;
		cursor.Y = ScreenLimit::getY() / 2 + 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToDifficultyBack() {
		cursor.X = ScreenLimit::getX() / 2 - 2;
		cursor.Y = ScreenLimit::getY() / 2 + 3;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}

	void goToDifficultyArrowEasy() {
		goToDifficultyEasy();
		cursor.X -= 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToDifficultyArrowNormal() {
		goToDifficultyNormal();
		cursor.X -= 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToDifficultyArrowHard() {
		goToDifficultyHard();
		cursor.X -= 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToDifficultyArrowExtreme() {
		goToDifficultyExtreme();
		cursor.X -= 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
	void goToDifficultyArrowBack() {
		goToDifficultyBack();
		cursor.X -= 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	}
}