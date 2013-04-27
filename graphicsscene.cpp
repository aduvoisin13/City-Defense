#include "graphicsscene.h"

GraphicsScene::GraphicsScene(MainWindow* mainWindow) {
	mw = mainWindow;
}

void GraphicsScene::keyPressEvent(QKeyEvent *e) {
	mw->handleKey(e);
}
