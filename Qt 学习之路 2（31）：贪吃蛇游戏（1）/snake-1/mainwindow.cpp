#include <QGraphicsView>
#include <QTimer>
#include <QApplication>
#include <QMessageBox>
#include <QMenuBar>
#include <QIcon>

#include "mainwindow.h"
#include "constants.h"
#include "gamecontroller.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView(scene, this)),
    game(new GameController(scene, this))
    // 罪魁祸首是resume()，调用setResume()非法访问resumeAction导致崩溃。
{
    setCentralWidget(view);
    // resize(600, 600);
    setFixedSize(600, 600);
    setWindowIcon(QIcon(":/images/snake_ico"));

    createActions();//此时，resumeAction才初始化。
    createMenus();

    initScene();
    initSceneBackground();

    QTimer::singleShot(0, this, SLOT(adjustViewSize()));
    //分辨率还是有问题，有一圈是看不到的，而且食物可以生成在看不见的区域。
}



MainWindow::~MainWindow() {}



void MainWindow::adjustViewSize()
{
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}



void MainWindow::createActions()
{
    newGameAction = new QAction(tr("&New Game"), this);
    newGameAction->setShortcuts(QKeySequence::New);
    newGameAction->setStatusTip(tr("Start a new game"));
    connect(newGameAction, &QAction::triggered, this, &MainWindow::newGame);

    exitAction = new QAction(tr("&Exit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the game"));
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);

    pauseAction = new QAction(tr("&Pause"), this);
    pauseAction->setStatusTip(tr("Pause..."));
    connect(pauseAction, &QAction::triggered, game, &GameController::pause);

    resumeAction = new QAction(tr("&Resume"), this);
    resumeAction->setStatusTip(tr("Resume..."));
    resumeAction->setEnabled(false);
    game->setResumeAction(resumeAction);
    // 原来是两个不同的Action，游戏状态通过gamecontroller的resumeAction控制主界面的resumeAction显示状态。
    connect(resumeAction, &QAction::triggered, game, &GameController::resume);

    gameHelpAction = new QAction(tr("Game &Help"), this);
    gameHelpAction->setShortcut(tr("Ctrl+H"));
    gameHelpAction->setStatusTip(tr("Help on this game"));
    connect(gameHelpAction, &QAction::triggered, this, &MainWindow::gameHelp);

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("Show the application's about box"));
    connect(aboutAction, &QAction::triggered, this, &MainWindow::about);

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction, &QAction::triggered, qApp, QApplication::aboutQt);
}



void MainWindow::createMenus()
{
    QMenu *options = menuBar()->addMenu(tr("&Options"));
    options->addAction(newGameAction);
    options->addSeparator();
    options->addAction(pauseAction);
    options->addAction(resumeAction);
    options->addSeparator();
    options->addAction(exitAction);

    QMenu *help = menuBar()->addMenu(tr("&Help"));
    help->addAction(gameHelpAction);
    help->addAction(aboutAction);
    help->addAction(aboutQtAction);
}



void MainWindow::initScene()
{
    scene->setSceneRect(-100, -100, 200, 200);
}



void MainWindow::initSceneBackground()
{
    QPixmap bg(TILE_SIZE, TILE_SIZE);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);

    view->setBackgroundBrush(QBrush(bg));
}



void MainWindow::newGame()
{
    QTimer::singleShot(0, game, SLOT(gameOver()));
}



void MainWindow::about()
{
    QMessageBox::about(this, tr("About this Game"), tr("<h2>Snake Game</h2>"
                                                       "<p>Copyright &copy; XXX."
                                                       "<p>This game is a small Qt application. It is based on the demo in the GitHub written by Devbean."));
}



void MainWindow::gameHelp()
{
    QMessageBox::about(this, tr("Game Help"), tr("Using direction keys to control the snake to eat the food"
                                                 "<p>Space - pause & resume"));
}
