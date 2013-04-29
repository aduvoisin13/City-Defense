#ifndef SLOWENEMY_H
#define SLOWENEMY_H

#include "thing.h"

class SlowEnemy : public Thing {
	public:
	SlowEnemy();
	void move(int speedMult);
	void animate(int);
	bool isDead();
	void decreaseShotsToKill();
	int scoreHit();
	int scoreKilled();
	private:
};

#endif
