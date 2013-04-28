#include "graphicsscene.h"

GraphicsScene::GraphicsScene(MainWindow* mainWindow) {
	mw = mainWindow;
}

void GraphicsScene::keyPressEvent(QKeyEvent *e) {
	if(e->key() == Qt::Key_Left)
		mw->setKeyLeft(true);
	if(e->key() == Qt::Key_Right)
		mw->setKeyRight(true);
	if(e->key() == Qt::Key_Space)
		mw->setKeySpace(true);
}

void GraphicsScene::keyReleaseEvent(QKeyEvent *e) {
	if(e->key() == Qt::Key_Left)
		mw->setKeyLeft(false);
	if(e->key() == Qt::Key_Right)
		mw->setKeyRight(false);
	if(e->key() == Qt::Key_Space)
		mw->setKeySpace(false);
}
