#include "bouncingenemy.h"

BouncingEnemy::BouncingEnemy() {
	xv = -3;
	yv = 1.5;
	currentFrame = 0;
	shotsToKill = 1;
}

void BouncingEnemy::move(int speedMult) {
	moveBy(xv * speedMult, yv * speedMult);
	if(x() < 0 || x() > 300 - pixmap().width()) {
		xv *= -1;
		if(x() > 300 - pixmap().width())
			setX(300 - pixmap().width());
	}
}

void BouncingEnemy::animate(int time) {
	
}

bool BouncingEnemy::isDead() { return (shotsToKill == 0); }
void BouncingEnemy::decreaseShotsToKill() { shotsToKill--; }

int BouncingEnemy::scoreHit() { return 0; }
int BouncingEnemy::scoreKilled() { return 500; }
