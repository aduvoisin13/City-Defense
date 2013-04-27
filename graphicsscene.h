#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <iostream>
#include <iomanip>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "mainwindow.h"

using namespace std;

class MainWindow;

class GraphicsScene : public QGraphicsScene {
	public:
	GraphicsScene(MainWindow* mainWindow);
	void keyPressEvent(QKeyEvent *e);
	
	private:
	MainWindow* mw;
};

#endif
