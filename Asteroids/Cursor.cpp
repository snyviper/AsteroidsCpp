#include "Cursor.h"
#include "ScreenLimit.h"

Cursor::Cursor() {}

void Cursor::goToXY(unsigned int x, unsigned int y) {
    if (x < ScreenLimit().getSpaceX() && y < ScreenLimit().getSpaceY()) {
        cursor.X = x;
        cursor.Y = y + 2;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
    }
}
void Cursor::goToPosition(Coords position) {
    if (position.getX() < ScreenLimit().getSpaceX() && position.getY() < ScreenLimit().getSpaceY()) {
        cursor.X = position.getX();
        cursor.Y = position.getY() + 2;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
    }
}

void Cursor::goToShipStart() {
    cursor.X = ScreenLimit().getSpaceX() / 2;
    cursor.Y = ScreenLimit().getSpaceY() / 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToScopeStart() {
    cursor.X = ScreenLimit().getSpaceX() / 2;
    cursor.Y = (ScreenLimit().getSpaceY() / 2) - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void Cursor::goToInstructionHitJ() {
    cursor.X = (ScreenLimit().getSpaceX() / 2) - 2;
    cursor.Y = (ScreenLimit().getSpaceY() / 2) + 3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToInstructionToStart() {
    cursor.X = (ScreenLimit().getSpaceX() / 2) - 4;
    cursor.Y = (ScreenLimit().getSpaceY() / 2) + 4;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToInstructionToExit() {
    cursor.X = (ScreenLimit().getSpaceX() / 2) - 3;
    cursor.Y = (ScreenLimit().getSpaceY() / 2) + 4;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToFinalScore(int figures) {
    cursor.X = (ScreenLimit().getSpaceX() / 2) - (figures + 7) / 2;
    cursor.Y = (ScreenLimit().getSpaceY() / 2) + 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHealth() {
    cursor.X = 0;
    cursor.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHearts() {
    cursor.X = 8;
    cursor.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToScoreWord(int figures) {
    cursor.X = ScreenLimit().getX() - figures - 7;
    cursor.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToScoreValue(int figures) {
    cursor.X = ScreenLimit().getX() - figures;
    cursor.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToFPS() {
    cursor.X = 0;
    cursor.Y = ScreenLimit().getY() - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToFPSName() {
    cursor.X = 5;
    cursor.Y = ScreenLimit().getY() - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToTopBorder() {
    cursor.X = 0;
    cursor.Y = 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToBottomBorder() {
    cursor.X = 8;
    cursor.Y = ScreenLimit().getY() - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToSpace() {
    cursor.X = 0;
    cursor.Y = 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToTitle() {
    cursor.X = (ScreenLimit().getX()/2)-6;
    cursor.Y = (ScreenLimit().getY()/2)-4;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToNewGame() {
    cursor.X = (ScreenLimit().getX()/2)-5;
    cursor.Y = (ScreenLimit().getY()/2)-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToExit() {
    cursor.X = (ScreenLimit().getX()/2)-3;
    cursor.Y = ScreenLimit().getY()/2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToArrowNewGame() {
    goToNewGame();
    cursor.X -= 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToArrowExit() {
    goToExit();
    cursor.X -= 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpTop() {
    cursor.X = ScreenLimit().getX() - 7;
    cursor.Y = 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpMiddle() {
    cursor.X = ScreenLimit().getX() - 7;
    cursor.Y = 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpBottom() {
    cursor.X = ScreenLimit().getX() - 7;
    cursor.Y = 3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void Cursor::goToSelectDifficulty() {
    cursor.X = ScreenLimit().getX()/2 - 8;
    cursor.Y = ScreenLimit().getY()/2 - 4;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyEasy() {
    cursor.X = ScreenLimit().getX() / 2 - 2;
    cursor.Y = ScreenLimit().getY() / 2 - 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyNormal() {
    cursor.X = ScreenLimit().getX() / 2 - 3;
    cursor.Y = ScreenLimit().getY() / 2 - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyHard() {
    cursor.X = ScreenLimit().getX() / 2 - 2;
    cursor.Y = ScreenLimit().getY() / 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyExtreme() {
    cursor.X = ScreenLimit().getX() / 2 - 3;
    cursor.Y = ScreenLimit().getY() / 2 + 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyBack() {
    cursor.X = ScreenLimit().getX() / 2 - 2;
    cursor.Y = ScreenLimit().getY() / 2 + 3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyArrowEasy() {
    Cursor::goToDifficultyEasy();
    cursor.X -= 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyArrowNormal() {
    Cursor::goToDifficultyNormal();
    cursor.X -= 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyArrowHard() {
    Cursor::goToDifficultyHard();
    cursor.X -= 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyArrowExtreme() {
    Cursor::goToDifficultyExtreme();
    cursor.X -= 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyArrowBack() {
    Cursor::goToDifficultyBack();
    cursor.X -= 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void Cursor::goToPaused() {
    cursor.X = ScreenLimit().getSpaceX() / 2 - 5;
    cursor.Y = ScreenLimit().getSpaceY() / 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void Cursor::goToHelpW() {
    cursor.X = 4;
    cursor.Y = 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpA() {
    cursor.X = 4;
    cursor.Y = 3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpS() {
    cursor.X = 4;
    cursor.Y = 4;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpD() {
    cursor.X = 4;
    cursor.Y = 5;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpJ() {
    cursor.X = 4;
    cursor.Y = 6;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpK() {
    cursor.X = 4;
    cursor.Y = 7;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}