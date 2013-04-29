#ifndef FASTENEMY_H
#define FASTENEMY_H

#include "thing.h"

/** Class that handles every instance of
 * the fast enemy. Inherits from Thing. */
class FastEnemy : public Thing {
	public:
	/** Default constructor. */
	FastEnemy();
	/** Move the fast enemy. */
	void move(int speedMult);
	/** Animates the fast enemy's sprite. */
	void animate(int);
	/** Is the fast enemy dead? */
	bool isDead();
	/** Decreases the shots to kill the fast enemy by one. */
	void decreaseShotsToKill();
	/** Increases the score when the enemy is hit. */
	int scoreHit();
	/** Increases the score when the enemy is killed. */
	int scoreKilled();
};

#endif
