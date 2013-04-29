#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>

/** Class that handles the creation and movement
 * of each Bullet. */
class Bullet : public QGraphicsPixmapItem {
	public:
	/** Moves the bullet. */
	void move();
};

#endif
