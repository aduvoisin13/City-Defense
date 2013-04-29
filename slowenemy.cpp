#include "slowenemy.h"

SlowEnemy::SlowEnemy() {
	currentFrame = 0;
	shotsToKill = 3;
}

void SlowEnemy::move(int speedMult) {
	moveBy(0, 1 * speedMult);
}

void SlowEnemy::animate(int time) {
	if(time % 10 == 0) {
		if(currentFrame == 0) {
			setPixmap(QPixmap("slow2.png"));
			currentFrame = 1;
		} else {
			setPixmap(QPixmap("slow1.png"));
			currentFrame = 0;
		}
	}
}

bool SlowEnemy::isDead() { return (shotsToKill == 0); }
void SlowEnemy::decreaseShotsToKill() { shotsToKill--; }

int SlowEnemy::scoreHit() { return 100; }
int SlowEnemy::scoreKilled() { return 0; }
