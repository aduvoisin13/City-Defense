#include "fastenemy.h"

/** Default constructor.
 *
 * @return Nothing.
 */
FastEnemy::FastEnemy() {
	currentFrame = 0;
	shotsToKill = 1;
}

/** Moves the enemy.
 *
 * @param speedMult The speed multiplier; increases as the game progresses.
 * @return Nothing.
 */
void FastEnemy::move(int speedMult) {
	moveBy(0, 4 * speedMult);
}

/** Animates the enemy.
 *
 * @param time The current time of the timer; used to determine animation.
 * @return Nothing.
 */
void FastEnemy::animate(int time) {
	if(time % 2 == 0) {
		if(currentFrame == 0) {
			setPixmap(QPixmap("fast2.png"));
			currentFrame = 1;
		} else {
			setPixmap(QPixmap("fast1.png"));
			currentFrame = 0;
		}
	}
}

/** Returns if the enemy is dead or not.
 *
 * @return True if dead, false if not.
 */
bool FastEnemy::isDead() { return (shotsToKill == 0); }

/** Decreases the shots to kill the enemy.
 *
 * @return Nothing.
 */
void FastEnemy::decreaseShotsToKill() { shotsToKill--; }

/** Returns the number of points that this enemy is worth when hit.
 *
 * @return The increase in score that the player gets for hitting the enemy.
 */
int FastEnemy::scoreHit() { return 0; }

/** Returns the number of points that this enemy is worth when killed.
 *
 * @return The increase in score that the player gets for killing the enemy.
 */
int FastEnemy::scoreKilled() { return 500; }

/** Sets the X Velocity.
 *
 * @return Nothing.
 */
void FastEnemy::setXV(double x) { xv = x; }

/** Sets the Y Velocity.
 *
 * @return Nothing.
 */
void FastEnemy::setYV(double y) { yv = y; }
