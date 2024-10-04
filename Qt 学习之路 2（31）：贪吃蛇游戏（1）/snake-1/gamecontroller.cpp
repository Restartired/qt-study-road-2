#include <QEvent>
#include <QKeyEvent>
#include <QMessageBox>

#include "gamecontroller.h"
#include "food.h"
#include "snake.h"

GameController::GameController(QGraphicsScene *scene, QObject *parent) :
    QObject(parent),
    scene(scene),
    snake(new Snake(this)),
    isPause(false)
{
    timer.start(1000/33);

    Food *a1 = new Food(0, -50);
    scene->addItem(a1);
    scene->addItem(snake);
    scene->installEventFilter(this);
    // resume();
    // 神人把rusume()放在这里，导致了game和resumeAction的互相依赖。
    connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
}



GameController::~GameController()
{
}



void GameController::snakeAteFood(Food *food)
{
    scene->removeItem(food);
    // delete food;
    //吃到食物，释放会崩溃，猜测可能是removeItem自动释放了。

    addNewFood();
}



void GameController::snakeHitWall(Snake *snake, Wall *wall)
{
}



void GameController::snakeAteItself()
{
    QTimer::singleShot(0, this, SLOT(gameOver()));
}



void GameController::handleKeyPressed(QKeyEvent *event)
{
    if (!isPause){//我还疑惑两次空格怎么实现pause()和resume()操作的切换，其实这里是任意一个键让游戏恢复。
        switch (event->key()) {
            case Qt::Key_Left:
                snake->setMoveDirection(Snake::MoveLeft);
                break;
            case Qt::Key_Right:
                snake->setMoveDirection(Snake::MoveRight);
                break;
            case Qt::Key_Up:
                snake->setMoveDirection(Snake::MoveUp);
                break;
            case Qt::Key_Down:
                snake->setMoveDirection(Snake::MoveDown);
                break;
            case Qt::Key_Space:                
                pause();
                break;
        }
    }else{
        resume();
    }
}



void GameController::addNewFood()
{
    int x, y;

    do {
        x = (int)(rand() % 200) - 100;//(0到199) - 100
        y = (int)(rand() % 200) - 100;
        //qrand()弃用，QT官方推荐随机生成器，暂且用C++的rand()顶一下吧...希望后来的能用随机生成器。

        // x *= 10;
        // y *= 10;
    } while (snake->shape().contains(snake->mapFromScene(QPointF(x + 5, y + 5))));

    Food *food = new Food(x, y);
    scene->addItem(food);
}



void GameController::gameOver()
{
    disconnect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
    if (QMessageBox::Yes == QMessageBox::information(NULL,
                                                     tr("Game Over"), tr("Again?"),
                                                     QMessageBox::Yes | QMessageBox::No,
                                                     QMessageBox::Yes)) {
            connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
            scene->clear();

            snake = new Snake(this);
            scene->addItem(snake);
            addNewFood();
    } else {
        exit(0);
    }
}



void GameController::pause()
{
    disconnect(&timer, SIGNAL(timeout()),
               scene,  SLOT(advance()));
    isPause = true;
    setResume();
}



void GameController::resume()
{
    connect(&timer, SIGNAL(timeout()),
            scene,  SLOT(advance()));
    isPause = false;
    setResume();
}



void GameController :: setResume(){
    if(isPause == true){
        resumeAction->setEnabled(true);
    }else{
        resumeAction->setEnabled(false);
    }
}



bool GameController::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        handleKeyPressed((QKeyEvent *)event);
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}




