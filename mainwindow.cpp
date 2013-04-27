#include "mainwindow.h"

/** Default constructor. Initializes every value needed
 * for the program to run correctly. */
MainWindow::MainWindow() {
    scene = new GraphicsScene(this);
    view = new QGraphicsView();
    view->setScene(scene);
    //setCentralWidget(view);
    scene->setSceneRect(0, 0, WINDOW_X, WINDOW_Y);
    
    view->setFixedSize(WINDOW_X + 2, WINDOW_Y + 2);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    
	/*
	startButton = new QPushButton("Start Game", view);
	startButton->move(350, TEXTBOX_HEIGHT - TEXTBOX_HEIGHT / 2);
    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));
    
  	quitButton = new QPushButton("Quit", view);
	quitButton->move(355, TEXTBOX_HEIGHT + TEXTBOX_HEIGHT / 2);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
    */
	timer = new QTimer(this);
	timer->setInterval(50);
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	
	player = new Player();
	player->setPixmap(QPixmap("shipidle.png"));
	scene->addItem(player);
	player->setPos(WINDOW_X / 2, WINDOW_Y - 114 - 30);
	
	city = new City();
	city->setPixmap(QPixmap("city.png"));
	scene->addItem(city);
	city->setPos(0, WINDOW_Y - 114);
}

/** Default destructor. */
MainWindow::~MainWindow() {
	
}

/** Displays the view.
 *
 * @return Nothing.
 */
void MainWindow::show() {
    view->show();
}

/** Slot that starts the game, creating the necessary
 * items based on user inputs. Called when the Start Game
 * button is clicked.
 *
 * @return Nothing.
 */
void MainWindow::start() {
	
}

void MainWindow::pause() {
	
}

/** Slot that quits the game. Called when the Quit
 * button is clicked.
 *
 * @return Nothing.
 */
void MainWindow::quit() {
	exit(0);
}

void MainWindow::handleKey(QKeyEvent* e) {
    if(e->key() == Qt::Key_Left)
    	player->moveBy(-5, 0);
    if(e->key() == Qt::Key_Right)
    	player->moveBy(5, 0);
}

void MainWindow::handleTimer() {
}
