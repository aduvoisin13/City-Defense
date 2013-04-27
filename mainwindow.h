#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

#define WINDOW_X 299
#define WINDOW_Y 500

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
	void handleKey(QKeyEvent *e);
    
private:
	/** The scene for displaying the board. */
    GraphicsScene *scene;
    /** The view for displaying the board. */
    QGraphicsView *view;
    /** Buttons for starting, pausing, and quitting the game. */
    QPushButton *startButton, *pauseButton, *quitButton;
    /** Gameplay timer. */
    QTimer* timer;
    Player *player;
    City *city;

public slots:
	/** Starts the game based on the inputs. Called when the start button is pressed. */
	void start();
	/** Pauses the game. */
	void pause();
	/** Ends the game. Called when the end button is pressed. */
	void quit();
	void handleTimer();
};

#endif // MAINWINDOW_H
