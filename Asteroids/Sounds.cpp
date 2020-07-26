#include "Sounds.h"
#include <Windows.h>
#pragma comment(lib, "winmm.lib")

namespace Sounds {
	void playMenuSelectSound() {
		PlaySound(TEXT("MenuSelect.wav"), NULL, SND_ASYNC);
	}
	void playMenuHitSound() {
		PlaySound(TEXT("MenuHit.wav"), NULL, SND_ASYNC);
	}
	void playMenuBackSound() {
		PlaySound(TEXT("MenuBack.wav"), NULL, SND_ASYNC);
	}
	void playMenuExitSound() {
		PlaySound(TEXT("MenuBack.wav"), NULL, SND_SYNC);
	}

	void playGunSound() {
		PlaySound(TEXT("LaserGun01.wav"), NULL, SND_ASYNC);
	}
	void playShipExplosionSound() {
		PlaySound(TEXT("Explosion01.wav"), NULL, SND_ASYNC);
	}
	void playAsteroidExplosionSound() {
		PlaySound(TEXT("Explosion01.wav"), NULL, SND_ASYNC);
	}

	void playPauseSound() {
		PlaySound(TEXT("MenuSelect.wav"), NULL, SND_ASYNC);
	}
	void playHelpSound() {
		PlaySound(TEXT("HelpHit.wav"), NULL, SND_ASYNC);
	}

	void playStageCompletedSound() {
		PlaySound(TEXT("Success.wav"), NULL, SND_ASYNC);
	}
	void playGameOverSound() {
		PlaySound(TEXT("Failure.wav"), NULL, SND_ASYNC);
	}
}