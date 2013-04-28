#include "slowenemy.h"

SlowEnemy::SlowEnemy() {
	currentFrame = 0;
	shotsToKill = 3;
}

void SlowEnemy::move() {
	moveBy(0, 1);
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

void SlowEnemy::setShotsToKill(int stk) { shotsToKill = stk; }
int SlowEnemy::getShotsToKill() { return shotsToKill; }
