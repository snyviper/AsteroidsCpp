#ifndef CURSOR_H
#define CURSOR_H

#include <Windows.h>
#include "ScreenLimit.h"

class Cursor
{
//private:
    COORD cursor;

public:
    Cursor();
    void goToXY(unsigned int x, unsigned int y, ScreenLimit limit);
    void goToShipStart(ScreenLimit limit);
    void goToScopeStart(ScreenLimit limit);
    void goToInstruction(ScreenLimit limit);
    void goToInstruction2(ScreenLimit limit);
    void goToHealth();
    void goToHearts();
    void goToScoreWord(int figures, ScreenLimit limit);
    void goToScoreValue(int figures, ScreenLimit limit);
    void goToFPS(ScreenLimit limit);
    void goToFPSName(ScreenLimit limit);
    void goToTopBorder();
    void goToBottomBorder(ScreenLimit limit);
    void goToSpace();
    void goToTitle(ScreenLimit limit);
    void goToNewGame(ScreenLimit limit);
    void goToExit(ScreenLimit limit);
    void goToArrowNewGame(ScreenLimit limit);
    void goToArrowExit(ScreenLimit limit);
    void goToHelpTop(ScreenLimit limit);
    void goToHelpMiddle(ScreenLimit limit);
    void goToHelpBottom(ScreenLimit limit);

    void goToSelectDifficulty(ScreenLimit limit);
    void goToDifficultyEasy(ScreenLimit limit);
    void goToDifficultyNormal(ScreenLimit limit);
    void goToDifficultyHard(ScreenLimit limit);
    void goToDifficultyExtreme(ScreenLimit limit);
    void goToDifficultyBack(ScreenLimit limit);
    void goToDifficultyArrowEasy(ScreenLimit limit);
    void goToDifficultyArrowNormal(ScreenLimit limit);
    void goToDifficultyArrowHard(ScreenLimit limit);
    void goToDifficultyArrowExtreme(ScreenLimit limit);
    void goToDifficultyArrowBack(ScreenLimit limit);

    void goToPaused(ScreenLimit limit);

    /*void goToLastPosition(ScreenLimit limit);
    void goDown(ScreenLimit limit);*/

    void goToHelpW(ScreenLimit limit);
    void goToHelpA(ScreenLimit limit);
    void goToHelpS(ScreenLimit limit);
    void goToHelpD(ScreenLimit limit);
    void goToHelpJ(ScreenLimit limit);
    void goToHelpK(ScreenLimit limit);
};

#endif