#include "gamecontroller.h"
#include "food.h"
#include "snake.h"


GameController::GameController(QGraphicsScene *scene, QObject *parent) :
    QObject(parent),
    scene(*scene),
    snake(new Snake(*this))
{
    timer.start(1000/33);

    Food *a1 = new Food(0, -60);
    scene->addItem(a1);

    // scene->addItem(snake);

    scene->installEventFilter(this);

    resume();
}

void GameController::pause()
{
    disconnect(&timer, SIGNAL(timeout()),
               &scene,  SLOT(advance()));
}

void GameController::resume()
{
    connect(&timer, SIGNAL(timeout()),
            &scene,  SLOT(advance()));
}

void GameController::snakeAteFood(Food *food)
{
    scene.removeItem(food);

    addNewFood();
}

void GameController::snakeAteItself()
{
    QTimer::singleShot(0, this, SLOT(gameOver()));
}

void GameController::addNewFood()
{
    int x, y;

    do {
        x = (int)(rand() % 200) / 10 - 10;
        y = (int)(rand() % 200) / 10 - 10;
        //qrand()弃用

        x *= 10;
        y *= 10;
    } while (snake->shape().contains(snake->mapFromScene(QPointF(x + 5, y + 5))));

    Food *food = new Food(x, y);
    scene.addItem(food);
}

