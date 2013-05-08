#include "blimp.h"

/** Default constructor.
 *
 * @return Nothing.
 */
Blimp::Blimp() {
	shotsToKill = 1;
}

/** Moves the blimp.
 *
 * @param speedMult The speed multiplier; increases as the game progresses.
 * @return Nothing.
 */
void Blimp::move(int speedMult) {
	moveBy(3 * speedMult, 0);
}

/** Animates the blimp. (Required Function)
 *
 * @param time The current time of the timer; used to determine animation.
 * @return Nothing.
 */
void Blimp::animate(int timer) {
	timer++; // Needed for compiler.
}

/** Returns if the blimp is dead or not.
 *
 * @return True if dead, false if not.
 */
bool Blimp::isDead() { return (shotsToKill == 0); }

/** Decreases the shots to kill the blimp.
 *
 * @return Nothing.
 */
void Blimp::decreaseShotsToKill() { shotsToKill--; }

/** Returns the number of points that this blimp is worth when hit.
 *
 * @return The increase in score that the player gets for hitting the blimp.
 */
int Blimp::scoreHit() { return 0; }

/** Returns the number of points that this blimp is worth when destroyed.
 *
 * @return The increase in score that the player gets for destroying the blimp.
 */
int Blimp::scoreKilled() { return 1000; }

/** Sets the X Velocity.
 *
 * @return Nothing.
 */
void Blimp::setXV(double x) { xv = x; }

/** Sets the Y Velocity.
 *
 * @return Nothing.
 */
void Blimp::setYV(double y) { yv = y; }
