#include "bouncingenemy.h"

BouncingEnemy::BouncingEnemy() {
	xv = -3;
	yv = 1.5;
	currentFrame = 0;
	shotsToKill = 1;
}

void BouncingEnemy::move() {
	moveBy(xv, yv);
	if(x() < 0 || x() > 300 - pixmap().width())
		xv *= -1;
}

void BouncingEnemy::animate(int time) {
	
}

void BouncingEnemy::setShotsToKill(int stk) { shotsToKill = stk; }
int BouncingEnemy::getShotsToKill() { return shotsToKill; }
