#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QTextEdit>
#include <QString>
#include <QRadioButton>
#include <QListView>
#include <QStandardItemModel>
#include <QPixmap>
#include <QKeyEvent>
#include <QMainWindow>
#include <QGraphicsSceneMouseEvent>
#include <QLabel>
#include <QVBoxLayout>

#include "thing.h"
#include "fastenemy.h"
#include "slowenemy.h"
#include "bouncingenemy.h"
#include "player.h"
#include "blimp.h"
#include "city.h"
#include "graphicsscene.h"
#include "bullet.h"

#define WINDOW_X 300
#define WINDOW_Y 500
#define VIEW_X 400

class GraphicsScene;

/** MainWindow handles all of the gameplay with Qt and
 * all other GUI-based entities in the program. */
class MainWindow : public QWidget {
    Q_OBJECT
    
public:
	/** Default constructor. */
    explicit MainWindow();
    /** Default destructor. */
    ~MainWindow();
    /** Displays the view. */
	void show();
	/** Sets the value of the left key (called when key is pressed or released). */
	void setKeyLeft(bool kl);
	/** Sets the value of the right key (called when key is pressed or released). */
	void setKeyRight(bool kr);
	/** Sets the value of the space key (called when key is pressed or released). */
	void setKeySpace(bool ks);
	/** Ends the game. */
	void endGame();
    
private:
	/** The scene for displaying the board. */
    GraphicsScene *scene;
    /** The view for displaying the board. */
    QGraphicsView *view;
    /** Buttons for starting, pausing, and quitting the game. */
    QPushButton *startButton, *pauseButton, *quitButton;
    /** Gameplay timer. */
    QTimer *moveTimer, *createTimer;
    /** The city. */
    City *city;
    /** The player. */
    Player *player;
    /** Vector of all enemies. */
    vector<Thing*> enemies;
    /** Vector of all bullets. */
    vector<Bullet*> bullets;
    /** Keeps track of whether a key is being pressed or not. */
    bool keyLeft, keyRight, keySpace, prevKeySpace;
    /** The background. */
    QGraphicsPixmapItem *background;
    /** The number of times moveTimer's slot function has been called. */
    int numMoveTicks;
    /** The speed multiplier, for enemy movement speed. */
    double speedMult;
    /** Boolean values for whether the game has been started/paused or not. */
    bool started, paused;
    /** Textboxes needed for the menu and getting the username. */
    QTextEdit *menu, *unPrompt, *userName;
    /** Textboxes needed for the HUD. */
    QTextEdit *hudText, *comboText, *scoreText, *livesText, *levelText;
    /** The values of various elements that control the game. Displayed in the HUD. */
    int combo, lives, level;
    /** Elements to control the score. Displayed in the HUD. */
    unsigned long score, extraLife;

public slots:
	/** Starts the game based on the inputs. Called when the start button is pressed. */
	void start();
	/** Pauses the game. */
	void pause();
	/** Ends the game. Called when the end button is pressed. */
	void quit();
	/** Handles most of the movement and updating of the game. */
	void handleMoveTimer();
	/** Creates enemies. */
	void handleCreateTimer();
};

#endif // MAINWINDOW_H
