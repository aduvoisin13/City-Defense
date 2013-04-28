#include "mainwindow.h"

/** Default constructor. Initializes every value needed
 * for the program to run correctly. */
MainWindow::MainWindow() {
	keyLeft = false;
	keyRight = false;
	keySpace = false;
	prevKeySpace = false;
	
	numMoveTicks = 0;

    scene = new GraphicsScene(this);
    view = new QGraphicsView();
    
    view->setScene(scene);
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
    background = new QGraphicsPixmapItem();
    background->setPixmap(QPixmap("background.png"));
    scene->addItem(background);
    
	moveTimer = new QTimer(this);
	moveTimer->setInterval(50);
	connect(moveTimer, SIGNAL(timeout()), this, SLOT(handleMoveTimer()));
	moveTimer->start();
	
	createTimer = new QTimer(this);
	createTimer->setInterval(2000);
	connect(createTimer, SIGNAL(timeout()), this, SLOT(handleCreateTimer()));
	createTimer->start();
	
	player = new Player();
	player->setPixmap(QPixmap("shipidle.png"));
	scene->addItem(player);
	player->setPos(WINDOW_X / 2 - 10, WINDOW_Y - 145);
	
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

void MainWindow::setKeyLeft(bool kl) { keyLeft = kl; }
void MainWindow::setKeyRight(bool kr) { keyRight = kr; }
void MainWindow::setKeySpace(bool ks) { keySpace = ks; }

void MainWindow::handleMoveTimer() {
	if(keyLeft && !keyRight) {
		if(player->x() > 0)
			player->moveBy(-5, 0);
		player->setPixmap(QPixmap("shipleft.png"));
	} else if(keyRight && !keyLeft) {
		if((player->x() + player->pixmap().width()) < WINDOW_X)
			player->moveBy(5, 0);
		player->setPixmap(QPixmap("shipright.png"));
	} else if((keyRight && keyLeft) || !(keyRight && keyLeft))
		player->setPixmap(QPixmap("shipidle.png"));
	
	if(keySpace && !prevKeySpace) {
		Bullet* bullet = new Bullet();
		bullet->setPixmap(QPixmap("bullet.png"));
		scene->addItem(bullet);
		bullet->setPos(player->x() + (player->pixmap().width() / 2) - 3, player->y());
		bullets.push_back(bullet);
	}
	
	prevKeySpace = keySpace;
	
	for(unsigned int i = 0; i < enemies.size(); i++)
		enemies[i]->animate(numMoveTicks);
	
	for(unsigned int i = 0; i < enemies.size(); i++)
		enemies[i]->move();
	for(unsigned int i = 0; i < bullets.size(); i++) {
		bullets[i]->move();
		if(bullets[i]->x() < 0) {
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
			i--;
		}
	}
	
	for(unsigned int i = 0; i < enemies.size(); i++)
		for(unsigned int j = 0; j < bullets.size(); j++) {
			if(enemies[i]->x() < (bullets[j]->x() + bullets[j]->pixmap().width()) && (enemies[i]->x() + enemies[i]->pixmap().width()) > bullets[j]->x()) {
				if(enemies[i]->y() < (bullets[j]->y() + bullets[j]->pixmap().height()) && (enemies[i]->y() + enemies[i]->pixmap().height()) > bullets[j]->y()) {
					enemies[i]->setShotsToKill(enemies[i]->getShotsToKill() - 1);
					if(enemies[i]->getShotsToKill() == 0) {
						delete enemies[i];
						enemies.erase(enemies.begin() + i);
						i--;
					}
					delete bullets[j];
					bullets.erase(bullets.begin() + j);
					j = 0;
					break;
				}
			}
		}
	
	numMoveTicks++;
	
	if(numMoveTicks == 100) {
		moveTimer->setInterval(moveTimer->interval() - 1);
		createTimer->setInterval(createTimer->interval() - 100);
		numMoveTicks = 0;
	}
}

void MainWindow::handleCreateTimer() {
	Thing* enemy;
	switch(rand() % 3) {
		case 0:
			enemy = new FastEnemy();
			enemy->setPixmap(QPixmap("fast1.png"));
			break;
		case 1:
			enemy = new BouncingEnemy();
			enemy->setPixmap(QPixmap("bounce.png"));
			break;
		case 2:
			enemy = new SlowEnemy();
			enemy->setPixmap(QPixmap("slow1.png"));
			break;
	};
	scene->addItem(enemy);
	enemy->setPos(rand() % (WINDOW_X - enemy->pixmap().width()), enemy->pixmap().height() * -1);
	enemies.push_back(enemy);
}
