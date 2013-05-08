#ifndef THING_H
#define THING_H

#include <QGraphicsPixmapItem>

using namespace std;

/** Abstract class that keeps track of many of
 * the 'things' in the game. (Keeps track of any 'thing'
 * that can be hit by a Bullet.) */
class Thing : public QGraphicsPixmapItem {
	public:
	/** Move the thing. */
	virtual void move(int) = 0;
	/** Animate the thing. */
	virtual void animate(int) = 0;
	/** Is the thing dead? */
	virtual bool isDead() = 0;
	/** Decreases the shots to kill the thing by 1. */
	virtual void decreaseShotsToKill() = 0;
	/** Increases the score when the thing is hit. */
	virtual int scoreHit() = 0;
	/** Increases the score when the thing is killed. */
	virtual int scoreKilled() = 0;
	/** Sets X Velocity. */
	virtual void setXV(double) = 0;
	/** Sets Y Velocity. */
	virtual void setYV(double) = 0;
	
	protected:
	/** Shots to kill the thing. */
	int shotsToKill;
	/** X velocity and Y velocity. */
	double xv, yv;
	/** Current frame that the thing's animation is in. */
	int currentFrame;
};

#endif
