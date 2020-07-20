#include "Space.h"
#include "HUD.h"
#include <conio.h>

//private
void Space::nextFrame() {
	frame++;
	if (frame >= 12)
		frame = 0;
}

void Space::resetAsteroids(int difficulty, ScreenLimit limit) {
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
	}
	asteroid.clear();
	for (int i = 0; i < asteroidAmount; i++)
		asteroid.push_back(Asteroid(difficulty, limit));
}
void Space::damageAsteroid(int index, int difficulty, ScreenLimit limit) {
	if (asteroid.at(index).isBig()) {
		addScoreAsteroidBig(difficulty, stage);
		asteroid.at(index).turnSmall(difficulty, limit);
		asteroid.push_back(Asteroid(difficulty, asteroid.at(index).getPositionSmall(), limit));
		while (asteroid.at(index).getSpeed().equalsXY(asteroid.at(asteroid.size() - 1).getSpeed()))
			asteroid.at(asteroid.size() - 1).newSpeed(difficulty);
	}
	else {
		addScoreAsteroidSmall(difficulty, stage);
		asteroid.erase(asteroid.begin() + index);
	}
}

bool Space::asteroidHitShip(ScreenLimit limit) {
	if (ship.asteroidHitShip(asteroid, limit)) {
		damageShip();
		return true;
	}
	return false;
}

void Space::movePrintAsteroids(ScreenLimit limit) {
	for (int index = 0; index < asteroid.size(); index++) {
		asteroid.at(index).newFrame(limit, frame);
		HUD().printAsteroid(asteroid.at(index), limit);
	}
}
void Space::printAsteroids(ScreenLimit limit) {
	for (int index = 0; index < asteroid.size(); index++) {
		HUD().printAsteroid(asteroid.at(index), limit);
	}
}

void Space::printBullets(ScreenLimit limit) {
	for (int i = 0; i < ship.getMaxBullets(); i++) {
		if (ship.bulletExists(i))
			HUD().printBullet(ship.getBulletPosition(i), limit);
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

void Space::beforeStartGame(int difficulty, ScreenLimit limit) {
	char key = 'a';
	bool showShip = false, start = false;
	clock_t refreshRate;
	double fps = 0;
	int index;
	HUD().refreshHUD(hearts, score, fps, limit);
	while (!start) {
		refreshRate = clock();
		nextFrame();
		HUD().refreshHUD(hearts, score, fps, limit);
		movePrintAsteroids(limit);
		ship.newBulletsFrame(limit);
		index = ship.bulletsHitAsteroid(asteroid);
		if (index >= 0) {
			damageAsteroid(index, difficulty, limit);
			if (asteroid.size() == 0)
				start = true;
		}
		HUD().blinkShip(ship, limit, showShip);
		HUD().printInstructions(limit);
		showShip = !showShip;
		printBullets(limit);
		if (_kbhit()) { // if key is pressed
			key = _getch();
			while (_kbhit())
				_getch();
			if (key == 'j') { // if key pressed is J, it starts the game
				start = true;
			}
		}
		fps = getFPS(refreshRate);
	}
}
void Space::startBattle(int difficulty, ScreenLimit limit) {
	clock_t refreshRate;
	char key;
	double fps = 0;
	bool shipHit = false;
	int index;
	while (asteroid.size() > 0 && !shipHit) {
		refreshRate = clock();
		nextFrame();
		HUD().refreshHUD(hearts, score, fps, limit);
		movePrintAsteroids(limit);
		if (_kbhit()) { // if key is pressed
			key = _getch();
			switch (key) {
			case 'w':
				ship.accelerate();
				break;
			case 'a':
				ship.turnLeft(limit);
				break;
			case 'd':
				ship.turnRight(limit);
				break;
			case 'k':
				ship.shoot(limit);
				break;
			case 'j':
				HUD().printShip(ship, limit);
				while (pauseGame(limit)) {
					HUD().refreshHUD(hearts, score, fps, limit);
					printAsteroids(limit);
					HUD().printShip(ship, limit);
				}
				break;
			case 'h':
				HUD().printHelp(limit);
				HUD().refreshHUD(hearts, score, fps, limit);
				printAsteroids(limit);
				break;
			}
			while (_kbhit()) // loops until key is released
				_getch();
		}
		ship.newFrame(frame, limit);
		HUD().printShip(ship, limit);
		printBullets(limit);
		index = ship.bulletsHitAsteroid(asteroid);
		if (index >= 0)
			damageAsteroid(index, difficulty, limit);
		if (asteroidHitShip(limit))
			shipHit = true;
		fps = getFPS(refreshRate);
	}
	newStage(difficulty, limit);
}

void Space::newStage(int difficulty, ScreenLimit limit) {
	if (asteroid.size() == 0) {
		stage++;
		addScoreClearAsteroids(difficulty, stage);
		ship.resetShip(limit);
		resetAsteroids(difficulty, limit);
		addHeart();
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

bool Space::pauseGame(ScreenLimit limit) {
	char key;
	HUD().printPause(limit);
	key = _getch();
	if (key == 'h') {
		HUD().printHelp(limit);
		return true;
	}
	else { return false; }
}

//public:
/*Space::Space() {
	ship = Ship();
	stage = frame = score = 0;
	hearts = 1;
}*/
Space::Space(int difficulty, ScreenLimit limit) {
	int asteroidAmount;

	ship = Ship(limit);
	stage = frame = score = 0;
	setHearts(difficulty);

	resetAsteroids(difficulty, limit);
}



void Space::game(int difficulty, ScreenLimit limit) {
	ship = Ship(limit);
	stage = frame = 0;
	resetAsteroids(difficulty, limit);
	while (getHearts() > 0) {
		beforeStartGame(difficulty, limit);
		startBattle(difficulty, limit);
	}
}