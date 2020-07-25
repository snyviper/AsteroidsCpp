#include "Asteroid.h"
#include "ScreenLimit.h"
#include <windows.h>
#include <time.h>

int Asteroid::s_RandAdd;

void Asteroid::changeRandomSeed() {
	s_RandAdd+=23;
	if (s_RandAdd > 32000) {
		s_RandAdd = 0;
	}
}

int Asteroid::randomPosition(int maxPosition) {
	int random;
	srand(time(NULL) + s_RandAdd);
	random = rand() % maxPosition;
	changeRandomSeed();
	return random;
}

int Asteroid::randomSpeed(int difficulty) {
	int random;
	srand(time(NULL) + s_RandAdd);
	switch (difficulty) {
		case 0:
			random = rand() % 6;
			changeRandomSeed();
			switch (random) {
				case 0:
					return -3;
				case 1:
					return -4;
				case 2:
					return -6;
				case 3:
					return 6;
				case 4:
					return 4;
				case 5:
					return 3;
			}
		case 1:
			random = rand() % 8;
			changeRandomSeed();
			switch (random) {
				case 0:
					return -2;
				case 1:
					return -3;
				case 2:
					return -4;
				case 3:
					return -6;
				case 4:
					return 6;
				case 5:
					return 4;
				case 6:
					return 3;
				case 7:
					return 2;
			}
		case 2:
			random = rand() % 6;
			changeRandomSeed();
			switch (random) {
				case 0:
					return -2;
				case 1:
					return -3;
				case 2:
					return -4;
				case 3:
					return 4;
				case 4:
					return 3;
				case 5:
					return 2;
			}
		case 3:
			random = rand() % 8;
			changeRandomSeed();
			switch (random) {
				case 0:
					return -1;
				case 1:
					return -2;
				case 2:
					return -3;
				case 3:
					return -4;
				case 4:
					return 4;
				case 5:
					return 3;
				case 6:
					return 2;
				case 7:
					return 1;
			}
	}
}

Asteroid::Asteroid() { }

Asteroid::Asteroid(int difficulty) { // creates a big asteroid
	big = true;
	int x = randomPosition(ScreenLimit().getSpaceX()), y = randomPosition(ScreenLimit().getSpaceY());
	for (int i = -1, index = 0; i <= 1; i++) {
		for (int j = -1; j <= 1; j++, index++)
			position[index].setPosition(x + j, y + i);
	}
	speed.setSpeed(randomSpeed(difficulty), randomSpeed(difficulty));
}
Asteroid::Asteroid(int difficulty, Coords Position) { // creates a small asteroid
	big = false;
	position[0] = Position;
	speed.setSpeed(randomSpeed(difficulty), randomSpeed(difficulty));
}

void Asteroid::newSpeed(int difficulty) {
	speed.setSpeed(randomSpeed(difficulty), randomSpeed(difficulty));
}

void Asteroid::newFrame(int frame) {
	if (big) {
		for (int index = 0; index < 9; index++)
			position[index].move(speed, frame);
	}
	else
		position[0].move(speed, frame);
}

void Asteroid::turnSmall(int difficulty) {
	big = false;
	position[0].plusOneXY();
	speed.setSpeed(randomSpeed(difficulty), randomSpeed(difficulty));
}

bool Asteroid::isBig() { return big; }
Coords Asteroid::getPositionSmall() { return position[0]; }
Coords* Asteroid::getPositionBig() { return position; }
Coords Asteroid::getSpeed() { return speed; }