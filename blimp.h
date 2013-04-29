#ifndef BLIMP_H
#define BLIMP_H

#include "thing.h"

class Blimp : public Thing {
	public:
	Blimp();
	void move(int speedMult);
	void animate(int);
	bool isDead();
	void decreaseShotsToKill();
	int scoreHit();
	int scoreKilled();
	private:
};

#endif
