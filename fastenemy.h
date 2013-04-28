#ifndef FASTENEMY_H
#define FASTENEMY_H

#include "thing.h"

class FastEnemy : public Thing {
	public:
	FastEnemy();
	void move();
	void animate(int);
	void setShotsToKill(int);
	int getShotsToKill();
	private:
};

#endif
