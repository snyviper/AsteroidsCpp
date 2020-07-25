#ifndef SOUNDS_H
#define SOUNDS_H

class Sounds
{
public:
	Sounds();

	static void playMenuSelectSound();
	static void playMenuHitSound();
	static void playMenuBackSound();
	static void playMenuExitSound();

	static void playShipExplosionSound();
	static void playAsteroidExplosionSound();
	static void playGunSound();
	static void playPauseSound();
	static void playHelpSound();

	static void playGameOverSound();
	static void playStageCompletedSound();
};

#endif