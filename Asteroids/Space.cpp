#include "Space.h"
#include "HUD.h"
#include "Sounds.h"
#include <windows.h>
#include <conio.h>

//private
void Space::nextFrame() {
	frame++;
	if (frame >= 12)
		frame = 0;
}

void Space::resetAsteroids(int difficulty) {
	int asteroidAmount;
	switch (difficulty) {
		case 0:
			asteroidAmount = 7 + 2 * stage;
			break;
		case 1:
			asteroidAmount = 14 + 2 * stage;
			break;
		case 2:
			asteroidAmount = 21 + 2 * stage;
			break;
		case 3:
			asteroidAmount = 28 + 2 * stage;
			break;
		default:
			asteroidAmount = 1;
			break;
	}
	asteroid.clear();
	for (int i = 0; i < asteroidAmount; i++)
		asteroid.push_back(Asteroid(difficulty));
}
void Space::damageAsteroid(int index, int difficulty) {
	if (asteroid.at(index).isBig()) {
		addScoreAsteroidBig(difficulty, stage);
		asteroid.at(index).turnSmall(difficulty);
		asteroid.push_back(Asteroid(difficulty, asteroid.at(index).getPositionSmall()));
		while (asteroid.at(index).getSpeed().equals(asteroid.at(asteroid.size() - 1).getSpeed()))
			asteroid.at(asteroid.size() - 1).newSpeed(difficulty);
	}
	else {
		addScoreAsteroidSmall(difficulty, stage);
		asteroid.erase(asteroid.begin() + index);
	}
	HUD::printScoreValue(score);
}

bool Space::asteroidHitShip() {
	if (ship.asteroidHitShip(asteroid)) {
		damageShip();
		HUD::printHearts(hearts);
		return true;
	}
	return false;
}

void Space::movePrintAsteroids() {
	for (int index = 0; index < asteroid.size(); index++) {
		asteroid.at(index).newFrame(frame);
		HUD::printAsteroid(asteroid.at(index));
	}
}
void Space::printAsteroids() {
	for (int index = 0; index < asteroid.size(); index++) {
		HUD::printAsteroid(asteroid.at(index));
	}
}

void Space::printBullets() {
	for (int i = 0; i < ship.getMaxBullets(); i++) {
		if (ship.bulletExists(i))
			HUD::printBullet(ship.getBullet(i));
	}
}

void Space::damageShip() {
	removeHeart();
}

void Space::help(double fps) {
	Sounds::playHelpSound();
	HUD::printHelp();
	Sounds::playHelpSound();
	HUD::printHUD(hearts, score, fps);
}

double Space::getFPS(clock_t refreshRate) {
	refreshRate = clock() - refreshRate;
	double refreshRateDouble = (0.1 - ((double)refreshRate) / CLOCKS_PER_SEC) * 1000;
	if (refreshRateDouble > 0) {
		Sleep((int)refreshRateDouble);
		return 10;
	}
	return 1 / (((double)refreshRate) / CLOCKS_PER_SEC);
}

void Space::beforeStartGame(int difficulty) {
	char key = 'a';
	bool showShip = false, start = false;
	bool* pShowShip = &showShip;
	clock_t refreshRate;
	double fps = 0;
	int index;
	ship.resetShip();
	HUD::printHUD(hearts, score, fps);
	while (!start) {
		refreshRate = clock();
		nextFrame();
		HUD::refreshHUD(fps);
		movePrintAsteroids();
		ship.newBulletsFrame();
		index = ship.bulletsHitAsteroid(asteroid);
		if (index >= 0) {
			damageAsteroid(index, difficulty);
			if (asteroid.size() == 0)
				start = true;
		}
		HUD::blinkShip(ship, pShowShip);
		HUD::printInstructionsStart();
		printBullets();
		if (_kbhit()) { // if key is pressed
			key = _getch();
			while (_kbhit())
				_getch();
			if (key == 'j') { // if key pressed is J, it starts the game
				start = true;
			}
			else if (key == 'h') {
				help(fps);
			}
		}
		fps = getFPS(refreshRate);
	}
}
void Space::startBattle(int difficulty) {
	clock_t refreshRate;
	char key;
	double fps = 0;
	bool shipHit = false;
	int index;
	while (asteroid.size() > 0 && !shipHit) {
		refreshRate = clock();
		nextFrame();
		HUD::refreshHUD(fps);
		movePrintAsteroids();
		if (_kbhit()) { // if key is pressed
			key = _getch();
			switch (key) {
			case 'w':
				ship.accelerate();
				break;
			case 'a':
				ship.turnLeft();
				break;
			case 'd':
				ship.turnRight();
				break;
			case 'k':
				index = ship.shoot(asteroid);
				if (index >= 0)
					damageAsteroid(index, difficulty);
				break;
			case 'j':
				HUD::printShip(ship);
				pauseGame(fps);
				break;
			case 'h':
				help(fps);
				printAsteroids();
				break;
			}
			while (_kbhit()) // loops until key is released
				_getch();
		}
		ship.newFrame(frame);
		HUD::printShip(ship);
		printBullets();
		index = ship.bulletsHitAsteroid(asteroid);
		if (index >= 0)
			damageAsteroid(index, difficulty);
		if (asteroidHitShip())
			shipHit = true;
		fps = getFPS(refreshRate);
	}
	newStage(difficulty);
}

void Space::newStage(int difficulty) {
	if (asteroid.size() == 0) {
		Sounds::playStageCompletedSound();
		stage++;
		addScoreClearAsteroids(difficulty, stage);
		resetAsteroids(difficulty);
		addHeart();
	}
}

void Space::pauseGame(double fps) {
	Sounds::playPauseSound();
	HUD::printPause();
	while (_getch() == 'h') {
		help(fps);
		printAsteroids();
		HUD::printShip(ship);
		HUD::printPause();
	}
	Sounds::playPauseSound();
}

void Space::setHearts(int difficulty) {
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
int Space::getHearts() {
	return hearts;
}
void Space::removeHeart() {
	hearts--;
}
void Space::addHeart() {
	hearts++;
}

void Space::addScoreAsteroidSmall(int difficulty, int stage) {
	score += (20 + stage * 8) * (difficulty * 2 + 1);
}
void Space::addScoreAsteroidBig(int difficulty, int stage) {
	score += (5 + stage * 2) * (difficulty * 2 + 1);
}
void Space::addScoreClearAsteroids(int difficulty, int stage) {
	switch (difficulty) {
	case 0:
		score += 30 + stage * 10;
		break;
	case 1:
		score += 100 + stage * 30;
		break;
	case 2:
		score += 300 + stage * 90;
		break;
	case 3:
		score += 900 + stage * 270;
		break;
	}
}

//public:
Space::Space() {
	ship = Ship();
	stage = frame = score = 0;
	hearts = 1;
	resetAsteroids(4);
}
Space::Space(int difficulty) {
	ship = Ship();
	stage = frame = score = 0;
	setHearts(difficulty);
	resetAsteroids(difficulty);
}



void Space::game(int difficulty) {
	while (getHearts() > 0) {
		beforeStartGame(difficulty);
		startBattle(difficulty);
	}
	HUD::printDeadShip(ship);
	Sounds::playGameOverSound();
	HUD::printFinalScore(score);
	HUD::printInstructionsDead();
	char key = ' ';
	while (key != 'j')
		key = _getch();
}