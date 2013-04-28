#ifndef THING_H
#define THING_H

#include <QGraphicsPixmapItem>

using namespace std;

class Thing : public QGraphicsPixmapItem {
	public:
	virtual void move() = 0;
	virtual void animate(int) = 0;
	virtual void setShotsToKill(int) = 0;
	virtual int getShotsToKill() = 0;
	protected:
	int shotsToKill;
	double xv, yv;
	int currentFrame;
};

#endif
