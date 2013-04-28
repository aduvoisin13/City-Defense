#include "fastenemy.h"

FastEnemy::FastEnemy() {
	currentFrame = 0;
	shotsToKill = 1;
}

void FastEnemy::move() {
	moveBy(0, 4);
}

void FastEnemy::animate(int time) {
	if(currentFrame == 0) {
		setPixmap(QPixmap("fast2.png"));
		currentFrame = 1;
	} else {
		setPixmap(QPixmap("fast1.png"));
		currentFrame = 0;
	}
}

void FastEnemy::setShotsToKill(int stk) { shotsToKill = stk; }
int FastEnemy::getShotsToKill() { return shotsToKill; }
