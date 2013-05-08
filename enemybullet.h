#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "thing.h"

/** Class that handles every instance of
 * the enemy bullet. Inherits from Thing. */
class EnemyBullet : public Thing {
	public:
	/** Default constructor. */
	EnemyBullet();
	/** Move the enemy bullet. */
	void move(int speedMult);
	/** Animates the enemy bullet's sprite. */
	void animate(int);
	/** Is the enemy bullet dead? */
	bool isDead();
	/** Decreases the shots to kill the enemy bullet by one. */
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
