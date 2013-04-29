#ifndef BOUNCINGENEMY_H
#define BOUNCINGENEMY_H

#include "thing.h"

/** Class that handles every instance of
 * the bouncing enemy. Inherits from Thing. */
class BouncingEnemy : public Thing {
	public:
	/** Default constructor. */
	BouncingEnemy();
	/** Move the bouncing enemy. */
	void move(int speedMult);
	/** Animates the bouncing enemy's sprite. */
	void animate(int);
	/** Is the bouncing enemy dead? */
	bool isDead();
	/** Decreases the shots to kill the bouncing enemy by one. */
	void decreaseShotsToKill();
	/** Increases the score when the enemy is hit. */
	int scoreHit();
	/** Increases the score when the enemy is killed. */
	int scoreKilled();
};

#endif
