#include "slowenemy.h"

/** Default constructor.
 *
 * @return Nothing.
 */
SlowEnemy::SlowEnemy() {
	currentFrame = 0;
	shotsToKill = 3;
}

/** Moves the enemy.
 *
 * @param speedMult The speed multiplier; increases as the game progresses.
 * @return Nothing.
 */
void SlowEnemy::move(int speedMult) {
	moveBy(0, 1 * speedMult);
}

/** Animates the enemy.
 *
 * @param time The current time of the timer; used to determine animation.
 * @return Nothing.
 */
void SlowEnemy::animate(int time) {
	if(time % 10 == 0) {
		if(currentFrame == 0) {
			setPixmap(QPixmap("slow2.png"));
			currentFrame = 1;
		} else {
			setPixmap(QPixmap("slow1.png"));
			currentFrame = 0;
		}
	}
}

/** Returns if the enemy is dead or not.
 *
 * @return True if dead, false if not.
 */
bool SlowEnemy::isDead() { return (shotsToKill == 0); }

/** Decreases the shots to kill the enemy.
 *
 * @return Nothing.
 */
void SlowEnemy::decreaseShotsToKill() { shotsToKill--; }

/** Returns the number of points that this enemy is worth when hit.
 *
 * @return The increase in score that the player gets for hitting the enemy.
 */
int SlowEnemy::scoreHit() { return 100; }

/** Returns the number of points that this enemy is worth when killed.
 *
 * @return The increase in score that the player gets for killing the enemy.
 */
int SlowEnemy::scoreKilled() { return 0; }

/** Sets the X Velocity.
 *
 * @return Nothing.
 */
void SlowEnemy::setXV(double x) { xv = x; }

/** Sets the Y Velocity.
 *
 * @return Nothing.
 */
void SlowEnemy::setYV(double y) { yv = y; }
