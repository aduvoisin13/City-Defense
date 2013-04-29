#include "fastenemy.h"

FastEnemy::FastEnemy() {
	currentFrame = 0;
	shotsToKill = 1;
}

void FastEnemy::move(int speedMult) {
	moveBy(0, 4 * speedMult);
}

void FastEnemy::animate(int time) {
	if(time % 2 == 0) {
		if(currentFrame == 0) {
			setPixmap(QPixmap("fast2.png"));
			currentFrame = 1;
		} else {
			setPixmap(QPixmap("fast1.png"));
			currentFrame = 0;
		}
	}
}

bool FastEnemy::isDead() { return (shotsToKill == 0); }
void FastEnemy::decreaseShotsToKill() { shotsToKill--; }

int FastEnemy::scoreHit() { return 0; }
int FastEnemy::scoreKilled() { return 500; }
