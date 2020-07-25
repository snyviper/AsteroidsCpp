#ifndef CURSOR_H
#define CURSOR_H

#include <Windows.h>
#include "Coords.h"

class Cursor
{
//private:
    COORD cursor;

public:
    Cursor();
    void goToXY(unsigned int x, unsigned int y);
    void goToPosition(Coords position);
    void goToShipStart();
    void goToScopeStart();
    void goToInstructionHitJ();
    void goToInstructionToStart();
    void goToInstructionToExit();
    void goToFinalScore(int figures);
    void goToHealth();
    void goToHearts();
    void goToScoreWord(int figures);
    void goToScoreValue(int figures);
    void goToFPS();
    void goToFPSName();
    void goToTopBorder();
    void goToBottomBorder();
    void goToSpace();
    void goToTitle();
    void goToNewGame();
    void goToExit();
    void goToArrowNewGame();
    void goToArrowExit();
    void goToHelpTop();
    void goToHelpMiddle();
    void goToHelpBottom();

    void goToSelectDifficulty();
    void goToDifficultyEasy();
    void goToDifficultyNormal();
    void goToDifficultyHard();
    void goToDifficultyExtreme();
    void goToDifficultyBack();
    void goToDifficultyArrowEasy();
    void goToDifficultyArrowNormal();
    void goToDifficultyArrowHard();
    void goToDifficultyArrowExtreme();
    void goToDifficultyArrowBack();

    void goToPaused();

    void goToHelpW();
    void goToHelpA();
    void goToHelpS();
    void goToHelpD();
    void goToHelpJ();
    void goToHelpK();
};

#endif