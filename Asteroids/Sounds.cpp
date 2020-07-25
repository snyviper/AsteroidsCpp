#include "Sounds.h"
#include <Windows.h>

//public:
Sounds::Sounds() {}

void Sounds::playMenuSelectSound() {
	PlaySound(TEXT("MenuSelect.wav"), NULL, SND_ASYNC);
}
void Sounds::playMenuHitSound() {
	PlaySound(TEXT("MenuHit.wav"), NULL, SND_ASYNC);
}
void Sounds::playMenuBackSound() {
	PlaySound(TEXT("MenuBack.wav"), NULL, SND_ASYNC);
}
void Sounds::playMenuExitSound() {
	PlaySound(TEXT("MenuBack.wav"), NULL, SND_SYNC);
}

void Sounds::playShipExplosionSound() {
	PlaySound(TEXT("Explosion01.wav"), NULL, SND_ASYNC);
}
void Sounds::playAsteroidExplosionSound() {
	PlaySound(TEXT("Explosion01.wav"), NULL, SND_ASYNC);
}
void Sounds::playGunSound() {
	PlaySound(TEXT("LaserGun01.wav"), NULL, SND_ASYNC);
}
void Sounds::playPauseSound() {
	PlaySound(TEXT("MenuSelect.wav"), NULL, SND_ASYNC);
}
void Sounds::playHelpSound() {
	PlaySound(TEXT("HelpHit.wav"), NULL, SND_ASYNC);
}

void Sounds::playGameOverSound() {
	PlaySound(TEXT("Failure.wav"), NULL, SND_ASYNC);
}
void Sounds::playStageCompletedSound() {
	PlaySound(TEXT("Success.wav"), NULL, SND_ASYNC);
}