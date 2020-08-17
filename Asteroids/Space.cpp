#include "Space.h"
#include "HUD.h"
#include "Sounds.h"
#include <windows.h>
#include <conio.h>

//private
void Space::nextFrame() {
	_frame++;
	if (_frame >= 12)
		_frame = 0;
}

void Space::resetAsteroids() {
	int asteroidAmount;
	switch (_difficulty) {
		case 0:
			asteroidAmount = 7 + 2 * _stage;
			break;
		case 1:
			asteroidAmount = 14 + 2 * _stage;
			break;
		case 2:
			asteroidAmount = 21 + 2 * _stage;
			break;
		case 3:
			asteroidAmount = 28 + 2 * _stage;
			break;
		default:
			asteroidAmount = 1;
			break;
	}
	_asteroid.clear();
	for (int i = 0; i < asteroidAmount; i++)
		_asteroid.push_back(Asteroid(_difficulty));
}

void Space::damageAsteroid(int index) {
	if(index>=0){
		Sounds::playAsteroidExplosionSound();
		if (_asteroid.at(index).isBig()) {
			addScoreAsteroidBig();
			_asteroid.at(index).turnSmall(_difficulty);
			_asteroid.push_back(Asteroid(_difficulty, _asteroid.at(index).getPositionSmall()));
			while (_asteroid.at(index).getSpeed().equals(_asteroid.at(_asteroid.size() - 1).getSpeed()))
				_asteroid.at(_asteroid.size() - 1).newSpeed(_difficulty);
		}
		else {
			addScoreAsteroidSmall();
			_asteroid.erase(_asteroid.begin() + index);
		}
		HUD::printScoreValue(_score);
	}
}

bool Space::asteroidHitShip() {
	if (_ship.asteroidHitShip(_asteroid)) {
		Sounds::playShipExplosionSound();
		damageShip();
		HUD::printHearts(_hearts);
		return true;
	}
	return false;
}

void Space::movePrintAsteroids() {
	for (int i = 0; i < _asteroid.size(); i++) {
		_asteroid.at(i).newFrame(_frame);
		HUD::printAsteroid(_asteroid.at(i));
	}
}
void Space::printAsteroids() {
	for (int i = 0; i < _asteroid.size(); i++)
		HUD::printAsteroid(_asteroid.at(i));
}

void Space::printBullets() {
	for (int i = 0; i < _ship.getMaxBullets(); i++)
		if (_ship.bulletExists(i))
			HUD::printBullet(_ship.getBullet(i));
}

void Space::damageShip() {
	removeHeart();
}

void Space::help(double fps) {
	Sounds::playHelpSound();
	HUD::printHelp();
	Sounds::playHelpSound();
	HUD::printHUD(_hearts, _score, fps);
}

double Space::getFPS(clock_t refreshRate) {
	refreshRate = clock() - refreshRate;
	double refreshRateDouble = (MAX_REFRESH_RATE - ((double)refreshRate) / CLOCKS_PER_SEC) * 1000;
	if (refreshRateDouble > 0) {
		Sleep((int)refreshRateDouble);
		return MAX_FPS;
	}
	return 1 / (((double)refreshRate) / CLOCKS_PER_SEC);
}

bool Space::spaceHasAnyBullet(){
	for(int i = 0; i < _ship.getMaxBullets(); i++){
		if(_ship.bulletExists(i)){
			return true;
		}
	}
	return false;
}
bool Space::spaceHasAllBullets() {
	int count = 0;
	for (int i = 0; i < _ship.getMaxBullets(); i++){
		if (_ship.bulletExists(i)){
			count++;
		}
	}
	return count == _ship.getMaxBullets();
}

void Space::beforeStartBattle() {
	bool showShip = false, start = false, hasBullet = spaceHasAnyBullet();
	bool* pShowShip = &showShip;
	clock_t refreshRate;
	double fps = 0;
	_ship.resetShip();
	HUD::printHUD(_hearts, _score, fps);
	while (!start) {
		refreshRate = clock();
		nextFrame();
		HUD::refreshHUD(fps);
		movePrintAsteroids();
		HUD::blinkShip(_ship, pShowShip);
		HUD::printInstructionsStart();
		if(hasBullet){
			_ship.newBulletsFrame();
			damageAsteroid(_ship.bulletsHitAsteroid(_asteroid));
			if (_asteroid.size() == 0)
				start = true;
			printBullets();
		}
		if (_kbhit()) { // if key is pressed
			switch(_getch()){
				case 'j': // if key pressed is J, and there's no asteroid behind ship, it starts the game
					if (!_ship.asteroidHitShip(_asteroid))
						start = true;
					break;
				case 'h':
					help(fps);
					break;
			}
			while (_kbhit())
				_getch();
		}
		fps = getFPS(refreshRate);
	}
}
void Space::startBattle() {
	clock_t refreshRate;
	double fps = 0;
	bool shipHit = false;
	while (_asteroid.size() > 0 && !shipHit) {
		refreshRate = clock();
		nextFrame();
		HUD::refreshHUD(fps);
		movePrintAsteroids();
		if (_kbhit()) { // if key is pressed
			switch (_getch()) {
			case 'w':
				_ship.accelerate();
				break;
			case 'a':
				_ship.turnLeft();
				break;
			case 'd':
				_ship.turnRight();
				break;
			case 'k':
				if(!spaceHasAllBullets())
					Sounds::playGunSound();
				damageAsteroid(_ship.shoot(_asteroid));
				break;
			case 'j':
				HUD::printShip(_ship);
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
		_ship.newShipFrame(_frame);
		HUD::printShip(_ship);
		if (spaceHasAnyBullet()) {
			_ship.newBulletsFrame();
			printBullets();
			damageAsteroid(_ship.bulletsHitAsteroid(_asteroid));
		}
		shipHit = asteroidHitShip();
		fps = getFPS(refreshRate);
	}
	newStage();
}

void Space::newStage() {
	if (_asteroid.size() == 0) {
		Sounds::playStageCompletedSound();
		_stage++;
		addScoreClearAsteroids();
		resetAsteroids();
		addHeart();
	}
}

void Space::pauseGame(double fps) {
	Sounds::playPauseSound();
	HUD::printPause();
	while (_getch() == 'h') {
		help(fps);
		printAsteroids();
		HUD::printShip(_ship);
		HUD::printPause();
	}
	Sounds::playPauseSound();
}

void Space::setHearts() {
	switch (_difficulty) {
	case 0:
		_hearts = 4;
		break;
	case 1:
		_hearts = 3;
		break;
	case 2:
		_hearts = 2;
		break;
	case 3:
		_hearts = 1;
		break;
	}
}
void Space::removeHeart() {
	_hearts--;
}
void Space::addHeart() {
	_hearts++;
}

void Space::addScoreAsteroidSmall() {
	_score += (20 + _stage * 8) * (_difficulty * 2 + 1);
}
void Space::addScoreAsteroidBig() {
	_score += (5 + _stage * 2) * (_difficulty * 2 + 1);
}
void Space::addScoreClearAsteroids() {
	switch (_difficulty) {
	case 0:
		_score += 30 + _stage * 10;
		break;
	case 1:
		_score += 100 + _stage * 30;
		break;
	case 2:
		_score += 300 + _stage * 90;
		break;
	case 3:
		_score += 900 + _stage * 270;
		break;
	}
}

//public:
Space::Space() : MAX_FPS(10), MAX_REFRESH_RATE(0.1) { }
Space::Space(int difficulty, double maxFps) : _ship(Ship()), _difficulty(difficulty), _stage(0), _frame(0), _score(0), MAX_FPS(maxFps), MAX_REFRESH_RATE(1.0/maxFps) {
	resetAsteroids();
	setHearts();
}

void Space::game() {
	while (_hearts > 0) {
		beforeStartBattle();
		startBattle();
	}
	HUD::printDeadShip(_ship);
	Sounds::playGameOverSound();
	HUD::printFinalScore(_score);
	HUD::printInstructionsDead();
	while (_getch() != 'j');
}