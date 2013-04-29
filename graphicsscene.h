#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <iostream>
#include <iomanip>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "mainwindow.h"

using namespace std;

class MainWindow;

/** Class for the scene that the game takes place in.
 * Used primarily for the keyPress and keyRelease Events
 * that are consumed by the scene before they reach
 * the MainWindow. */
class GraphicsScene : public QGraphicsScene {
	public:
	/** Constructor to gain reference to the MainWindow. */
	GraphicsScene(MainWindow* mainWindow);
	/** Event when a key is pressed. */
	void keyPressEvent(QKeyEvent *e);
	/** Event when a key is released. */
	void keyReleaseEvent(QKeyEvent *e);
	
	private:
	/** Reference to the MainWindow. */
	MainWindow* mw;
};

#endif
