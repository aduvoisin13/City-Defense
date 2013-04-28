#ifndef BOUNCINGENEMY_H
#define BOUNCINGENEMY_H

#include "thing.h"

class BouncingEnemy : public Thing {
	public:
	BouncingEnemy();
	void move();
	void animate(int);
	void setShotsToKill(int);
	int getShotsToKill();
	private:
};

#endif
