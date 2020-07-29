#ifndef CURSOR_H
#define CURSOR_H

#include "Position.h"

namespace Cursor {
	//Space
	void goToSpace();

	void goToXY(unsigned int x, unsigned int y);
	void goToPosition(Position position);

	//HUD
	void goToHealth();
	void goToHearts();
	void goToScoreWord(int figures);
	void goToScoreValue(int figures);
	void goToFPS();
	void goToFPSName();
	void goToTopBorder();
	void goToBottomBorder();

	//Message
	void goToInstructionHitJ();
	void goToInstructionToStart();
	void goToInstructionToExit();

	void goToPaused();

	void goToFinalScore(int figures);

	void goToHelpW();
	void goToHelpA();
	void goToHelpS();
	void goToHelpD();
	void goToHelpJ();
	void goToHelpK();

	//Menu
	void goToTitle();
	void goToNewGame();
	void goToExit();

	void goToArrowNewGame();
	void goToArrowExit();

	void goToHelpIconTop();
	void goToHelpIconMiddle();
	void goToHelpIconBottom();

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
};

#endif