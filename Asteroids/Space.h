#pragma once
#include <vector>
#include <conio.h>
#include <iostream>
#include <ctime>
#include "Ship.h"
#include "Asteroid.h"
#include "ScreenLimit.h"
#include "HUD.h"
#include "Cursor.h"

class Space
{
//private
	HUD hud;
	int frame;
	int stage;
	Ship ship;
	std::vector<Asteroid> asteroid;

	void nextFrame() {
		frame++;
		if (frame >= 12)
			frame = 0;
	}

	void resetAsteroids(int difficulty, ScreenLimit limit) {
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
	void damageAsteroid(int index, int difficulty, ScreenLimit limit) {
		if (asteroid.at(index).isBig()) {
			hud.addScoreAsteroidBig(difficulty, stage);
			asteroid.at(index).turnSmall(difficulty, limit);
			asteroid.push_back(Asteroid(difficulty, asteroid.at(index).getPositionSmall(), limit));
			while (asteroid.at(index).getSpeed().equalsXY(asteroid.at(asteroid.size() - 1).getSpeed()))
				asteroid.at(asteroid.size() - 1).newSpeed(difficulty);
		}
		else {
			hud.addScoreAsteroidSmall(difficulty, stage);
			asteroid.erase(asteroid.begin() + index);
		}
	}
	/*
	void bulletHitAsteroid(int difficulty, ScreenLimit limit) {
		int index = ship.bulletsHitAsteroid(asteroid);
		if (index >= 0) {
			damageAsteroid(index, difficulty, limit);
			hud.printScoreValue(limit);
		}
	}*/

	bool asteroidHitShip(ScreenLimit limit) {
		if (ship.asteroidHitShip(asteroid, limit)) {
			damageShip();
			return true;
		}
		return false;
	}

	void movePrintAsteroids(ScreenLimit limit) {
		for (int index = 0; index < asteroid.size(); index++) {
			asteroid.at(index).newFrame(limit, frame);
			hud.printAsteroid(asteroid.at(index), limit);
		}
	}
	void printAsteroids(ScreenLimit limit) {
		for (int index = 0; index < asteroid.size(); index++) {
			hud.printAsteroid(asteroid.at(index), limit);
		}
	}

	void printBullets(ScreenLimit limit) {
		for (int i = 0; i < ship.getMaxBullets(); i++) {
			if(ship.bulletExists(i))
				hud.printBullet(ship.getBulletPosition(i), limit);
		}
	}

	void damageShip() {
		hud.removeHeart();
	}

	float getFPS(clock_t refreshRate) {
		refreshRate = clock() - refreshRate;
		float refreshRateFloat = (0.1 - ((float)refreshRate) / CLOCKS_PER_SEC) * 1000;
		if (refreshRateFloat > 0) {
			Sleep((int)refreshRateFloat);
			return 10;
		}
		return 1 / (((float)refreshRate) / CLOCKS_PER_SEC);
	}

	void beforeStartGame(int difficulty, ScreenLimit limit) {
		char key = 'a';
		bool showShip = false, start = false;
		clock_t refreshRate;
		float fps = 0;
		int index;
		hud.refreshHUD(fps, limit);
		while (!start) {
			refreshRate = clock();
			nextFrame();
			hud.refreshHUD(fps, limit);
			movePrintAsteroids(limit);
			ship.newBulletsFrame(limit);
			index = ship.bulletsHitAsteroid(asteroid);
			if (index >= 0) {
				damageAsteroid(index, difficulty, limit);
				if (asteroid.size() == 0)
					start = true;
			}
			hud.blinkShip(ship, limit, showShip);
			hud.printInstructions(limit);
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
	void startBattle(int difficulty, ScreenLimit limit) {
		clock_t refreshRate;
		char key;
		float fps = 0;
		bool shipHit = false;
		int index;
		while (asteroid.size() > 0 && !shipHit) {
			refreshRate = clock();
			nextFrame();
			hud.refreshHUD(fps, limit);
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
						hud.printShip(ship, limit);
						while (hud.pause(limit)) {
							hud.refreshHUD(fps, limit);
							printAsteroids(limit);
							hud.printShip(ship, limit);
						}
						break;
					case 'h':
						hud.printHelp(limit);
						hud.refreshHUD(fps, limit);
						printAsteroids(limit);
						break;
				}
				while (_kbhit()) // loops until key is released
					_getch();
			}
			ship.newFrame(frame, limit);
			hud.printShip(ship, limit);
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

	void newStage(int difficulty, ScreenLimit limit) {
		if (asteroid.size() == 0) {
			stage++;
			hud.addScoreClearAsteroids(difficulty, stage);
			ship.resetShip(limit);
			resetAsteroids(difficulty, limit);
			hud.addHeart();
		}
	}

public:
	Space() { }
	Space(int difficulty, ScreenLimit limit) {
		int asteroidAmount;

		ship = Ship(limit);
		hud = HUD(difficulty);
		stage = frame = 0;

		resetAsteroids(difficulty, limit);
	}

	void game(int difficulty, ScreenLimit limit) {
		ship = Ship(limit);
		hud = HUD(difficulty);
		stage = frame = 0;
		resetAsteroids(difficulty, limit);
		while (hud.getHearts()>0) {
			beforeStartGame(difficulty, limit);
			startBattle(difficulty, limit);
		}
	}

	Cursor getCursor() { return hud.getCursor(); }

	HUD getHUD() { return hud; }
	/*
	void add(Asteroid& asteroid) {

	}*/
};

