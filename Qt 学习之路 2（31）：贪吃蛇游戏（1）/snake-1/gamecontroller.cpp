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
