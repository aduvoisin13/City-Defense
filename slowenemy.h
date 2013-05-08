#ifndef SLOWENEMY_H
#define SLOWENEMY_H

#include "thing.h"

/** Class that handles every instance of
 * the slow enemy. Inherits from Thing. */
class SlowEnemy : public Thing {
	public:
	/** Default constructor. */
	SlowEnemy();
	/** Move the slow enemy. */
	void move(int speedMult);
	/** Animates the slow enemy's sprite. */
	void animate(int);
	/** Is the slow enemy dead? */
	bool isDead();
	/** Decreases the shots to kill the slow enemy by one. */
	void decreaseShotsToKill();
	/** Increases the score when the enemy is hit. */
	int scoreHit();
	/** Increases the score when the enemy is killed. */
	int scoreKilled();
	/** Sets X Velocity. */
	void setXV(double);
	/** Sets Y Velocity. */
	void setYV(double);
};

#endif
