#ifndef BLIMP_H
#define BLIMP_H

#include "thing.h"

/** Class that handles every instance of
 * the blimp. Inherits from Thing. */
class Blimp : public Thing {
	public:
	/** Default constructor. */
	Blimp();
	/** Move the blimp. */
	void move(int speedMult);
	/** Animates the blimp's sprite. */
	void animate(int);
	/** Is the blimp dead? */
	bool isDead();
	/** Decreases the shots to kill the blimp by one. */
	void decreaseShotsToKill();
	/** Increases the score when the blimp is hit. */
	int scoreHit();
	/** Increases the score when the blimp is killed. */
	int scoreKilled();
};

#endif
