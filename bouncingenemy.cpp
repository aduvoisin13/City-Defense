#include "bouncingenemy.h"

/** Default constructor.
 *
 * @return Nothing.
 */
BouncingEnemy::BouncingEnemy() {
	xv = -3;
	yv = 1.5;
	currentFrame = 0;
	shotsToKill = 1;
}

/** Moves the enemy.
 *
 * @param speedMult The speed multiplier; increases as the game progresses.
 * @return Nothing.
 */
void BouncingEnemy::move(int speedMult) {
	moveBy(xv * speedMult, yv * speedMult);
	if(x() < 0 || x() > 300 - pixmap().width()) {
		xv *= -1;
		if(x() > 300 - pixmap().width())
			setX(300 - pixmap().width());
	}
}

/** Animates the enemy. (Required Function)
 *
 * @param time The current time of the timer; used to determine animation.
 * @return Nothing.
 */
void BouncingEnemy::animate(int time) {
	time++; // Needed for compiler.
}

/** Returns if the enemy is dead or not.
 *
 * @return True if dead, false if not.
 */
bool BouncingEnemy::isDead() { return (shotsToKill == 0); }

/** Decreases the shots to kill the enemy.
 *
 * @return Nothing.
 */
void BouncingEnemy::decreaseShotsToKill() { shotsToKill--; }

/** Returns the number of points that this enemy is worth when hit.
 *
 * @return The increase in score that the player gets for hitting the enemy.
 */
int BouncingEnemy::scoreHit() { return 0; }

/** Returns the number of points that this enemy is worth when killed.
 *
 * @return The increase in score that the player gets for killing the enemy.
 */
int BouncingEnemy::scoreKilled() { return 500; }
