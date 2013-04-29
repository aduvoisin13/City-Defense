#ifndef FASTENEMY_H
#define FASTENEMY_H

#include "thing.h"

class FastEnemy : public Thing {
	public:
	FastEnemy();
	void move(int speedMult);
	void animate(int);
	bool isDead();
	void decreaseShotsToKill();
	int scoreHit();
	int scoreKilled();
	private:
};

#endif
