#include "enemybullet.h"

/** Default constructor.
 *
 * @return Nothing.
 */
EnemyBullet::EnemyBullet() {
	currentFrame = 0;
	shotsToKill = 1;
	xv = 0;
}

/** Moves the enemy.
 *
 * @param speedMult The speed multiplier; increases as the game progresses.
 * @return Nothing.
 */
void EnemyBullet::move(int speedMult) {
	moveBy(xv, 4.5 * speedMult);
}

/** Animates the enemy.
 *
 * @param time The current time of the timer; used to determine animation.
 * @return Nothing.
 */
void EnemyBullet::animate(int time) {
	time++; // Needed for compiler.
}

/** Returns if the enemy is dead or not.
 *
 * @return True if dead, false if not.
 */
bool EnemyBullet::isDead() { return (shotsToKill == 0); }

/** Decreases the shots to kill the enemy.
 *
 * @return Nothing.
 */
void EnemyBullet::decreaseShotsToKill() { shotsToKill--; }

/** Returns the number of points that this enemy is worth when hit.
 *
 * @return The increase in score that the player gets for hitting the enemy.
 */
int EnemyBullet::scoreHit() { return 0; }

/** Returns the number of points that this enemy is worth when killed.
 *
 * @return The increase in score that the player gets for killing the enemy.
 */
int EnemyBullet::scoreKilled() { return 25; }

/** Sets the X Velocity.
 *
 * @return Nothing.
 */
void EnemyBullet::setXV(double x) { xv = x; }

/** Sets the Y Velocity.
 *
 * @return Nothing.
 */
void EnemyBullet::setYV(double y) { yv = y; }
