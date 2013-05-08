#ifndef FOLLOWINGENEMY_H
#define FOLLOWINGENEMY_H

#include "thing.h"

/** Class that handles every instance of
 * the following enemy. Inherits from Thing. */
class FollowingEnemy : public Thing {
	public:
	/** Default constructor. */
	FollowingEnemy();
	/** Move the following enemy. */
	void move(int speedMult);
	/** Animates the following enemy's sprite. */
	void animate(int);
	/** Is the following enemy dead? */
	bool isDead();
	/** Decreases the shots to kill the following enemy by one. */
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
