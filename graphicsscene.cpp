#include "graphicsscene.h"

/** Constructor to gain a reference to the MainWindow.
 *
 * @param mainWindow The game's instance of MainWindow.
 * @return Nothing.
 */
GraphicsScene::GraphicsScene(MainWindow* mainWindow) {
	mw = mainWindow;
}

/** The event that triggers when a key is pressed.
 *
 * @param e The key event that tells which key has been pressed.
 * @return Nothing.
 */
void GraphicsScene::keyPressEvent(QKeyEvent *e) {
	if(e->key() == Qt::Key_Left)
		mw->setKeyLeft(true);
	if(e->key() == Qt::Key_Right)
		mw->setKeyRight(true);
	if(e->key() == Qt::Key_Space)
		mw->setKeySpace(true);
}

/** The event that triggers when a key is released.
 *
 * @param e The key event that tells which key has been pressed.
 * @return Nothing.
 */
void GraphicsScene::keyReleaseEvent(QKeyEvent *e) {
	if(e->key() == Qt::Key_Left)
		mw->setKeyLeft(false);
	if(e->key() == Qt::Key_Right)
		mw->setKeyRight(false);
	if(e->key() == Qt::Key_Space)
		mw->setKeySpace(false);
}
