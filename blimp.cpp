#include "blimp.h"

Blimp::Blimp() {
	shotsToKill = 1;
}

void Blimp::move(int speedMult) {
	moveBy(3 * speedMult, 0);
}

void Blimp::animate(int timer) { }

bool Blimp::isDead() { return (shotsToKill == 0); }
void Blimp::decreaseShotsToKill() { shotsToKill--; }

int Blimp::scoreHit() { return 0; }
int Blimp::scoreKilled() { return 1000; }
