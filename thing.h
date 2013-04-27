#ifndef THING_H
#define THING_H

#include <QGraphicsPixmapItem>

using namespace std;

class Thing : public QGraphicsPixmapItem {
	public:
	virtual void move() = 0;
	protected:
	int shotsToKill;
};

#endif
