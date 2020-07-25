#include "Space.h"
#include "HUD.h"
#include "Sounds.h"
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
			asteroidAmount = 7 + stage;
			break;
		case 1:
			asteroidAmount = 14 + stage;
			break;
		case 2:
			asteroidAmount = 21 + stage;
			break;
		case 3:
			asteroidAmount = 28 + stage;
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
}

bool Space::asteroidHitShip() {
	if (ship.asteroidHitShip(asteroid)) {
		damageShip();
		return true;
	}
	return false;
}

void Space::movePrintAsteroids() {
	for (int index = 0; index < asteroid.size(); index++) {
		asteroid.at(index).newFrame(frame);
		HUD().printAsteroid(asteroid.at(index));
	}
}
void Space::printAsteroids() {
	for (int index = 0; index < asteroid.size(); index++) {
		HUD().printAsteroid(asteroid.at(index));
	}
}

void Space::printBullets() {
	for (int i = 0; i < ship.getMaxBullets(); i++) {
		if (ship.bulletExists(i))
			HUD().printBullet(ship.getBullet(i));
	}
}

void Space::damageShip() {
	removeHeart();
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
	HUD().refreshHUD(hearts, score, fps);
	while (!start) {
		refreshRate = clock();
		nextFrame();
		HUD().refreshHUD(hearts, score, fps);
		movePrintAsteroids();
		ship.newBulletsFrame();
		index = ship.bulletsHitAsteroid(asteroid);
		if (index >= 0) {
			damageAsteroid(index, difficulty);
			if (asteroid.size() == 0)
				start = true;
		}
		HUD().blinkShip(ship, pShowShip);
		HUD().printInstructionsStart();
		printBullets();
		if (_kbhit()) { // if key is pressed
			key = _getch();
			while (_kbhit())
				_getch();
			if (key == 'j') { // if key pressed is J, it starts the game
				start = true;
			}
			else if (key == 'h') {
				Sounds().playHelpSound();
				HUD().printHelp();
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
		HUD().refreshHUD(hearts, score, fps);
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
				ship.shoot();
				break;
			case 'j':
				HUD().printShip(ship);
				pauseGame(fps);
				break;
			case 'h':
				HUD().printHelp();
				HUD().refreshHUD(hearts, score, fps);
				printAsteroids();
				break;
			}
			while (_kbhit()) // loops until key is released
				_getch();
		}
		ship.newFrame(frame);
		HUD().printShip(ship);
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
		playStageCompletedSound();
		stage++;
		addScoreClearAsteroids(difficulty, stage);
		resetAsteroids(difficulty);
		addHeart();
	}
}

void Space::pauseGame(double fps) {
	Sounds().playPauseSound();
	HUD().printPause();
	while (_getch() == 'h') {
		Sounds().playHelpSound();
		HUD().printHelp();
		HUD().refreshHUD(hearts, score, fps);
		printAsteroids();
		HUD().printShip(ship);
		HUD().printPause();
	}
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
	score += (15 + stage * 3) * (difficulty + 1);
}
void Space::addScoreAsteroidBig(int difficulty, int stage) {
	score += (5 + stage) * (difficulty + 1);
}
void Space::addScoreClearAsteroids(int difficulty, int stage) {
	switch (difficulty) {
	case 0:
		score += 50 + stage * 10;
		break;
	case 1:
		score += 100 + stage * 20;
		break;
	case 2:
		score += 200 + stage * 40;
		break;
	case 3:
		score += 400 + stage * 80;
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
	HUD().printDeadShip(ship);
	playGameOverSound();
	HUD().printFinalScore(score);
	HUD().printInstructionsDead();
	char key = ' ';
	while (key != 'j')
		key = _getch();
}