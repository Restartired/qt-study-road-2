#include "mainwindow.h"
#include <QTimer>

const int TILE_SIZE = 20;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView(scene, this))
    // game(new GameController(*scene, this))
{
    setCentralWidget(view);
    resize(600, 600);

    initScene();
    initSceneBackground();

    // QTimer::singleShot(0, this, SLOT(adjustViewSize()));
}

MainWindow::~MainWindow() {}

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





