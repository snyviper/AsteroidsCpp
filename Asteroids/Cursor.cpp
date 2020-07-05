#include "Cursor.h"

Cursor::Cursor() {}

void Cursor::goToXY(unsigned int x, unsigned int y, ScreenLimit limit) {
    if (x < limit.getSpaceX() && y < limit.getSpaceY()) {
        cursor.X = x;
        cursor.Y = y + 2;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
    }
}
void Cursor::goToShipStart(ScreenLimit limit) {
    cursor.X = limit.getSpaceX() / 2;
    cursor.Y = limit.getSpaceY() / 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToScopeStart(ScreenLimit limit) {
    cursor.X = limit.getSpaceX() / 2;
    cursor.Y = (limit.getSpaceY() / 2) - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void Cursor::goToInstruction(ScreenLimit limit) {
    cursor.X = (limit.getSpaceX() / 2) - 2;
    cursor.Y = (limit.getSpaceY() / 2) + 3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToInstruction2(ScreenLimit limit) {
    cursor.X = (limit.getSpaceX() / 2) - 4;
    cursor.Y = (limit.getSpaceY() / 2) + 4;
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
void Cursor::goToScoreWord(int figures, ScreenLimit limit) {
    cursor.X = limit.getX() - figures - 7;
    cursor.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToScoreValue(int figures, ScreenLimit limit) {
    cursor.X = limit.getX() - figures;
    cursor.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToFPS(ScreenLimit limit) {
    cursor.X = 0;
    cursor.Y = limit.getY() - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToFPSName(ScreenLimit limit) {
    cursor.X = 5;
    cursor.Y = limit.getY() - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToTopBorder() {
    cursor.X = 0;
    cursor.Y = 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToBottomBorder(ScreenLimit limit) {
    cursor.X = 8;
    cursor.Y = limit.getY() - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToSpace() {
    cursor.X = 0;
    cursor.Y = 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToTitle(ScreenLimit limit) {
    cursor.X = (limit.getX()/2)-6;
    cursor.Y = (limit.getY()/2)-4;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToNewGame(ScreenLimit limit) {
    cursor.X = (limit.getX()/2)-5;
    cursor.Y = (limit.getY()/2)-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToExit(ScreenLimit limit) {
    cursor.X = (limit.getX()/2)-3;
    cursor.Y = limit.getY()/2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToArrowNewGame(ScreenLimit limit) {
    goToNewGame(limit);
    cursor.X -= 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToArrowExit(ScreenLimit limit) {
    goToExit(limit);
    cursor.X -= 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpTop(ScreenLimit limit) {
    cursor.X = limit.getX() - 7;
    cursor.Y = 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpMiddle(ScreenLimit limit) {
    cursor.X = limit.getX() - 7;
    cursor.Y = 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpBottom(ScreenLimit limit) {
    cursor.X = limit.getX() - 7;
    cursor.Y = 3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void Cursor::goToSelectDifficulty(ScreenLimit limit) {
    cursor.X = limit.getX()/2 - 8;
    cursor.Y = limit.getY()/2 - 4;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyEasy(ScreenLimit limit) {
    cursor.X = limit.getX() / 2 - 2;
    cursor.Y = limit.getY() / 2 - 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyNormal(ScreenLimit limit) {
    cursor.X = limit.getX() / 2 - 3;
    cursor.Y = limit.getY() / 2 - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyHard(ScreenLimit limit) {
    cursor.X = limit.getX() / 2 - 2;
    cursor.Y = limit.getY() / 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyExtreme(ScreenLimit limit) {
    cursor.X = limit.getX() / 2 - 3;
    cursor.Y = limit.getY() / 2 + 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyBack(ScreenLimit limit) {
    cursor.X = limit.getX() / 2 - 2;
    cursor.Y = limit.getY() / 2 + 3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyArrowEasy(ScreenLimit limit) {
    cursor.X = limit.getX() / 2 - 4;
    cursor.Y = limit.getY() / 2 - 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyArrowNormal(ScreenLimit limit) {
    cursor.X = limit.getX() / 2 - 5;
    cursor.Y = limit.getY() / 2 - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyArrowHard(ScreenLimit limit) {
    cursor.X = limit.getX() / 2 - 4;
    cursor.Y = limit.getY() / 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyArrowExtreme(ScreenLimit limit) {
    cursor.X = limit.getX() / 2 - 5;
    cursor.Y = limit.getY() / 2 + 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToDifficultyArrowBack(ScreenLimit limit) {
    cursor.X = limit.getX() / 2 - 4;
    cursor.Y = limit.getY() / 2 + 3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void Cursor::goToPaused(ScreenLimit limit) {
    cursor.X = limit.getSpaceX() / 2 - 5;
    cursor.Y = limit.getSpaceY() / 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

/*
void Cursor::goToLastPosition(ScreenLimit limit) {
    cursor.X -= 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void Cursor::goDown(ScreenLimit limit) {
    if (cursor.Y < limit.getY() - 1) {
        cursor.Y++;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
    }
}
*/
void Cursor::goToHelpW(ScreenLimit limit) {
    cursor.X = 4;
    cursor.Y = 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpA(ScreenLimit limit) {
    cursor.X = 4;
    cursor.Y = 3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpS(ScreenLimit limit) {
    cursor.X = 4;
    cursor.Y = 4;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpD(ScreenLimit limit) {
    cursor.X = 4;
    cursor.Y = 5;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpJ(ScreenLimit limit) {
    cursor.X = 4;
    cursor.Y = 6;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void Cursor::goToHelpK(ScreenLimit limit) {
    cursor.X = 4;
    cursor.Y = 7;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}