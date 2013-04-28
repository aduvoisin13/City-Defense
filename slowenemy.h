#ifndef SLOWENEMY_H
#define SLOWENEMY_H

#include "thing.h"

class SlowEnemy : public Thing {
	public:
	SlowEnemy();
	void move();
	void animate(int);
	void setShotsToKill(int);
	int getShotsToKill();
	private:
};

#endif
