#include "mainwindow.h"

/** Default constructor. Initializes every value needed
 * for the program to run correctly. */
MainWindow::MainWindow() {
	keyLeft = false;
	keyRight = false;
	keySpace = false;
	prevKeySpace = false;
	paused = false;
	started = false;
	gameOver = false;
	
	numMoveTicks = 0;
	speedMult = 1;
	
	combo = 1;
	score = 0;
	lives = 3;
	level = 1;
	extraLife = 100000;

    scene = new GraphicsScene(this);
    view = new QGraphicsView();
    
    view->setScene(scene);
    scene->setSceneRect(0, 0, WINDOW_X, WINDOW_Y);
    view->setFixedSize(VIEW_X, WINDOW_Y + 2);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    
	background = new QGraphicsPixmapItem();
    background->setPixmap(QPixmap("background.png"));
    scene->addItem(background);
    background->setZValue(-1);
    
	city = new QGraphicsPixmapItem();
	city->setPixmap(QPixmap("city.png"));
	scene->addItem(city);
	city->setPos(0, WINDOW_Y - 114);
	city->setZValue(-1);
	
	menu = new QTextEdit(view);
	menu->setFontUnderline(true);
	menu->setFontWeight(QFont::Bold);
	menu->setText("Menu");
	menu->resize(100, 30);
	menu->move(WINDOW_X + 1, 1);
	menu->setAlignment(Qt::AlignCenter);
	menu->setReadOnly(true);
	menu->setFrameStyle(QFrame::NoFrame);
	
	startButton = new QPushButton("&Start", view);
	startButton->move(WINDOW_X + 8, 30);
    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));
    
    pauseButton = new QPushButton("&Pause", view);
	pauseButton->move(WINDOW_X + 8, 60);
    connect(pauseButton, SIGNAL(clicked()), this, SLOT(pause()));
    
  	quitButton = new QPushButton("&Quit", view);
	quitButton->move(WINDOW_X + 8, 90);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
    
    highScoreButton = new QPushButton("High Scores", view);
	highScoreButton->move(WINDOW_X + 2, 470);
    connect(highScoreButton, SIGNAL(clicked()), this, SLOT(toggleHighScores()));
    
    unPrompt = new QTextEdit(view);
    unPrompt->setTextColor(QColor(Qt::red));
    unPrompt->setText("To Start, Enter Name:");
    unPrompt->resize(100, 60);
    unPrompt->move(WINDOW_X + 1, 140);
    unPrompt->setAlignment(Qt::AlignCenter);
    unPrompt->setReadOnly(true);
    unPrompt->setFrameStyle(QFrame::NoFrame);
    
    userName = new QTextEdit(view);
    userName->resize(99, 61);
    userName->move(WINDOW_X + 1, 185);
    userName->setAlignment(Qt::AlignCenter);

	hudText = new QTextEdit(view);
	hudText->setFontUnderline(true);
	hudText->setFontWeight(QFont::Bold);
	hudText->setText("HUD");
	hudText->resize(100, 30);
	hudText->move(WINDOW_X + 1, 250);
	hudText->setAlignment(Qt::AlignCenter);
	hudText->setReadOnly(true);
	hudText->setFrameStyle(QFrame::NoFrame);
	
	comboText = new QTextEdit(view);
	comboText->setText("Combo: ");
	comboText->resize(100, 30);
	comboText->move(WINDOW_X + 1, 275);
	comboText->setAlignment(Qt::AlignCenter);
	comboText->setReadOnly(true);
	comboText->setFrameStyle(QFrame::NoFrame);
	
	scoreText = new QTextEdit(view);
	scoreText->setText("Score: ");
	scoreText->resize(100, 60);
	scoreText->move(WINDOW_X + 1, 300);
	scoreText->setAlignment(Qt::AlignCenter);
	scoreText->setReadOnly(true);
	scoreText->setFrameStyle(QFrame::NoFrame);
	
	livesText = new QTextEdit(view);
	livesText->setText("Lives: ");
	livesText->resize(100, 30);
	livesText->move(WINDOW_X + 1, 343);
	livesText->setAlignment(Qt::AlignCenter);
	livesText->setReadOnly(true);
	livesText->setFrameStyle(QFrame::NoFrame);
	
	levelText = new QTextEdit(view);
	levelText->setText("Level: ");
	levelText->resize(100, 30);
	levelText->move(WINDOW_X + 1, 368);
	levelText->setAlignment(Qt::AlignCenter);
	levelText->setReadOnly(true);
	levelText->setFrameStyle(QFrame::NoFrame);
	
	ifstream fin("highscores.txt");
	if(fin) {
		HighScore temp;
		fin >> temp.score;
		while(!fin.eof()) {
			fin.ignore(1, ' ');
			getline(fin, temp.name);
			highScores.push_back(temp);
			fin >> temp.score;
		}
	} else {
		HighScore temp;
		temp.name = "Computer Player";
		for(int i = 10; i > 0; i--) {
			temp.score = i * 10000;
			highScores.push_back(temp);
		}
	}
	
	highScoreText = new QTextEdit(view);
	highScoreText->setText("High Scores:");
	highScoreText->move(1, 1);
	highScoreText->resize(WINDOW_X, WINDOW_Y - 305);
	highScoreText->setAlignment(Qt::AlignCenter);
	highScoreText->setReadOnly(true);
	highScoreText->setFrameStyle(QFrame::NoFrame);
	QString hsText;
	for(int i = 0; i < 10; i++) {
		hsText.append(QString::fromStdString("#"));
		hsText.append(QString::number(i + 1));
		hsText.append(QString::fromStdString("    -    "));
		hsText.append(QString::number(highScores[i].score));
		hsText.append(QString::fromStdString("    -    "));
		hsText.append(QString::fromStdString(highScores[i].name));
		if(i != 9)
			hsText.append(QString::fromStdString("\n"));
	}
	highScoreText->append(hsText);
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
 * button is clicked. If the game has been started, then
 * the button resets the game.
 *
 * @return Nothing.
 */
void MainWindow::start() {
	if(started) {
		background->setPixmap(QPixmap("background.png"));
		city->setPixmap(QPixmap("city.png"));
		
		keyLeft = false;
		keyRight = false;
		keySpace = false;
		prevKeySpace = false;
		paused = false;
		gameOver = false;

		numMoveTicks = 0;
		speedMult = 1;

		combo = 1;
		score = 0;
		lives = 3;
		level = 1;
		extraLife = 100000;
		
		while(!enemies.empty()) {
			delete enemies[0];
			enemies.erase(enemies.begin());
		}
		while(!bullets.empty()) {
			delete bullets[0];
			bullets.erase(bullets.begin());
		}
		
		player->setPos(WINDOW_X / 2 - (player->pixmap().width() / 2), WINDOW_Y - 145);
		
		QString temp = QString::number(combo - 1);
		comboText->setText("Combo: " + temp);
		comboText->setAlignment(Qt::AlignCenter);
		
		temp = QString::number(score);
		scoreText->setText("Score: " + temp);
		scoreText->setAlignment(Qt::AlignCenter);
		
		temp = QString::number(lives);
		livesText->setText("Lives: " + temp);
		livesText->setAlignment(Qt::AlignCenter);
		
		temp = QString::number(level);
		levelText->setText("Level: " + temp);
		levelText->setAlignment(Qt::AlignCenter);
		
		if(!moveTimer->isActive())
			moveTimer->start();
		moveTimer->setInterval(50);
		if(!createTimer->isActive())
			createTimer->start();
		createTimer->setInterval(2000);
		
		highScoreText->setVisible(false);
		
		view->setFocus();
	} else if(userName->toPlainText() != "") {
		started = true;
		startButton->setText("&Restart");
	
		unPrompt->setTextColor(QColor(Qt::black));
		unPrompt->setFontUnderline(true);
		unPrompt->setText("Name");
		unPrompt->setAlignment(Qt::AlignCenter);
	
		userName->setReadOnly(true);
		userName->setFrameStyle(QFrame::NoFrame);
		userName->move(WINDOW_X + 1, 163);
		
		QString temp = QString::number(combo - 1);
		comboText->setText("Combo: " + temp);
		comboText->setAlignment(Qt::AlignCenter);
		
		temp = QString::number(score);
		scoreText->setText("Score: " + temp);
		scoreText->setAlignment(Qt::AlignCenter);
		
		temp = QString::number(lives);
		livesText->setText("Lives: " + temp);
		livesText->setAlignment(Qt::AlignCenter);
		
		temp = QString::number(level);
		levelText->setText("Level: " + temp);
		levelText->setAlignment(Qt::AlignCenter);
		
		moveTimer = new QTimer(this);
		moveTimer->setInterval(50);
		connect(moveTimer, SIGNAL(timeout()), this, SLOT(handleMoveTimer()));
		moveTimer->start();
	
		createTimer = new QTimer(this);
		createTimer->setInterval(2000);
		connect(createTimer, SIGNAL(timeout()), this, SLOT(handleCreateTimer()));
		createTimer->start();
	
		player = new QGraphicsPixmapItem();
		player->setPixmap(QPixmap("shipidle.png"));
		scene->addItem(player);
		player->setPos(WINDOW_X / 2 - (player->pixmap().width() / 2), WINDOW_Y - 145);
		
		highScoreText->setVisible(false);
		
		view->setFocus();
	}
}

/** Slot that pauses the game. Called when the Pause
 * button is clicked.
 *
 * @return Nothing.
 */
void MainWindow::pause() {
	if(!gameOver) {
		if(paused) {
			moveTimer->start();
			createTimer->start();
			paused = false;
		} else {
			moveTimer->stop();
			createTimer->stop();
			paused = true;
		}
	}
	view->setFocus();
}

/** Function that ends the game. Called when all
 * of the player's lives run out.
 *
 * @return Nothing.
 */
void MainWindow::endGame() {
	moveTimer->stop();
	createTimer->stop();
	while(!enemies.empty()) {
		delete enemies[0];
		enemies.erase(enemies.begin());
	}
	while(!bullets.empty()) {
		delete bullets[0];
		bullets.erase(bullets.begin());
	}
	player->setPos(-50, -50);
	gameOver = true;
	
	int hsIndex = 10;
	while(score > highScores[hsIndex - 1].score) {
		hsIndex--;
		if(hsIndex == 0) break;
	}
	if(hsIndex != 10) {
		for(int i = 9; i > hsIndex; i--) {
			highScores[i].score = highScores[i - 1].score;
			highScores[i].name = highScores[i - 1].name;
		}
		highScores[hsIndex].score = score;
		highScores[hsIndex].name = (userName->toPlainText()).toStdString();
	}
	ofstream fout("highscores.txt");
	for(int i = 0; i < 10; i++)
		fout << highScores[i].score << " " << highScores[i].name << endl;
	fout.close();
	
	highScoreText->setText("High Scores:");
	highScoreText->setAlignment(Qt::AlignCenter);
	QString hsText;
	for(int i = 0; i < 10; i++) {
		hsText.append(QString::fromStdString("#"));
		hsText.append(QString::number(i + 1));
		hsText.append(QString::fromStdString("    -    "));
		hsText.append(QString::number(highScores[i].score));
		hsText.append(QString::fromStdString("    -    "));
		hsText.append(QString::fromStdString(highScores[i].name));
		if(i != 9)
			hsText.append(QString::fromStdString("\n"));
	}
	highScoreText->append(hsText);
	highScoreText->setVisible(true);
}

/** Slot that quits the game. Called when the Quit
 * button is clicked.
 *
 * @return Nothing.
 */
void MainWindow::quit() {
	exit(0);
}

/** Slot that toggles high scores display. Called when the Toggle
 * High Scores button is clicked.
 *
 * @return Nothing.
 */
void MainWindow::toggleHighScores() {
	if(highScoreText->isVisible())
		highScoreText->setVisible(false);
	else
		highScoreText->setVisible(true);
	view->setFocus();
}

/** Sets the value of the left key. True = pressed, 
 * false = not pressed.
 *
 * @param kl The value of the left key.
 * @return Nothing.
 */
void MainWindow::setKeyLeft(bool kl) { keyLeft = kl; }

/** Sets the value of the right key. True = pressed, 
 * false = not pressed.
 *
 * @param kr The value of the right key.
 * @return Nothing.
 */
void MainWindow::setKeyRight(bool kr) { keyRight = kr; }

/** Sets the value of the space key. True = pressed, 
 * false = not pressed.
 *
 * @param ks The value of the space key.
 * @return Nothing.
 */
void MainWindow::setKeySpace(bool ks) { keySpace = ks; }

/** Slot function that handles the main movements
 * and updates of the game.
 *
 * @return Nothing.
 */
void MainWindow::handleMoveTimer() {
	if(keyLeft && !keyRight) {
		if(player->x() > 0)
			player->moveBy(-7.5, 0);
		if(player->x() < 0)
			player->setX(0);
		player->setPixmap(QPixmap("shipleft.png"));
	} else if(keyRight && !keyLeft) {
		if((player->x() + player->pixmap().width()) < WINDOW_X)
			player->moveBy(7.5, 0);
		if(player->x() + player->pixmap().width() > WINDOW_X)
			player->setX(WINDOW_X - player->pixmap().width());
		player->setPixmap(QPixmap("shipright.png"));
	} else if((keyRight && keyLeft) || !(keyRight && keyLeft))
		player->setPixmap(QPixmap("shipidle.png"));
	
	if(keySpace && !prevKeySpace) {
		QGraphicsPixmapItem* bullet = new QGraphicsPixmapItem();
		bullet->setPixmap(QPixmap("bullet.png"));
		scene->addItem(bullet);
		bullet->setPos(player->x() + (player->pixmap().width() / 2) - 3, player->y());
		bullets.push_back(bullet);
	}
	
	prevKeySpace = keySpace;
	
	for(unsigned int i = 0; i < enemies.size(); i++)
		enemies[i]->animate(numMoveTicks);
	
	for(unsigned int i = 0; i < enemies.size(); i++) {
		enemies[i]->move(speedMult);
		if(enemies[i]->x() + enemies[i]->pixmap().width() > WINDOW_X) {
			delete enemies[i];
			enemies.erase(enemies.begin() + i);
			i--;
		} else if((enemies[i]->y() > WINDOW_Y - city->pixmap().height() / 2) || (enemies[i]->y() > WINDOW_Y - enemies[i]->pixmap().height() - 10)) {
			lives--;
			if(lives == 0) {
				endGame();
				break;
			}
			combo = 1;
			delete enemies[i];
			enemies.erase(enemies.begin() + i);
			i--;
		}
	}
	for(unsigned int i = 0; i < bullets.size(); i++) {
		bullets[i]->moveBy(0, -20);
		if((bullets[i]->y() + bullets[i]->pixmap().height()) < 0) {
			combo = 1;
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
			i--;
		}
	}
	
	for(unsigned int i = 0; i < enemies.size(); i++)
		for(unsigned int j = 0; j < bullets.size(); j++) {
			if(enemies[i]->x() < (bullets[j]->x() + bullets[j]->pixmap().width()) && (enemies[i]->x() + enemies[i]->pixmap().width()) > bullets[j]->x()) {
				if(enemies[i]->y() < (bullets[j]->y() + bullets[j]->pixmap().height()) && (enemies[i]->y() + enemies[i]->pixmap().height()) > bullets[j]->y()) {
					enemies[i]->decreaseShotsToKill();
					score += enemies[i]->scoreHit() * combo;
					if(enemies[i]->isDead()) {
						score += enemies[i]->scoreKilled() * combo;
						delete enemies[i];
						enemies.erase(enemies.begin() + i);
						i--;
					}
					delete bullets[j];
					bullets.erase(bullets.begin() + j);
					j = 0;
					combo++;
					break;
				}
			}
		}
	
	numMoveTicks++;
	
	if(numMoveTicks == 750) {
		speedMult += (1.0 / level);
		createTimer->setInterval(createTimer->interval() * .6);
		if(createTimer->interval() < 1)
			createTimer->setInterval(1);
		numMoveTicks = 0;
		level++;
		if(level == 2) {
			background->setPixmap(QPixmap("background2.png"));
			city->setPixmap(QPixmap("city2.png"));
		}
		if(level == 3) {
			background->setPixmap(QPixmap("background3.png"));
			city->setPixmap(QPixmap("city3.png"));
		}
	}
	
	if(score > extraLife) {
		lives++;
		extraLife *= 2;
	}
	
	QString temp = QString::number(combo - 1);
	comboText->setText("Combo: " + temp);
	comboText->setAlignment(Qt::AlignCenter);
	
	temp = QString::number(score);
	scoreText->setText("Score: " + temp);
	scoreText->setAlignment(Qt::AlignCenter);
	
	if(lives > 0) {
		temp = QString::number(lives);
		livesText->setText("Lives: " + temp);
		livesText->setAlignment(Qt::AlignCenter);
	} else {
		livesText->setText("Game Over!");
		livesText->setAlignment(Qt::AlignCenter);
	}
	
	temp = QString::number(level);
	levelText->setText("Level: " + temp);
	levelText->setAlignment(Qt::AlignCenter);
}

/** Slot functon that handles the creation of enemies.
 *
 * @return Nothing.
 */
void MainWindow::handleCreateTimer() {
	Thing* enemy;
	switch(rand() % 10) {
		case 0:
		case 1:
		case 2:
			enemy = new FastEnemy();
			enemy->setPixmap(QPixmap("fast1.png"));
			enemy->setPos(rand() % (WINDOW_X - enemy->pixmap().width()), enemy->pixmap().height() * -1);
			break;
		case 3:
		case 4:
		case 5:
			enemy = new BouncingEnemy();
			enemy->setPixmap(QPixmap("bounce.png"));
			enemy->setPos(rand() % (WINDOW_X - enemy->pixmap().width()), enemy->pixmap().height() * -1);
			break;
		case 6:
		case 7:
		case 8:
			enemy = new SlowEnemy();
			enemy->setPixmap(QPixmap("slow1.png"));
			enemy->setPos(rand() % (WINDOW_X - enemy->pixmap().width()), enemy->pixmap().height() * -1);
			break;
		case 9:
			enemy = new Blimp();
			enemy->setPixmap(QPixmap("blimp.png"));
			enemy->setPos(enemy->pixmap().width() * -1, 50);
			break;
	};
	scene->addItem(enemy);
	enemies.push_back(enemy);
}
