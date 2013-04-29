#ifndef BOUNCINGENEMY_H
#define BOUNCINGENEMY_H

#include "thing.h"

class BouncingEnemy : public Thing {
	public:
	BouncingEnemy();
	void move(int speedMult);
	void animate(int);
	bool isDead();
	void decreaseShotsToKill();
	int scoreHit();
	int scoreKilled();
	private:
};

#endif
