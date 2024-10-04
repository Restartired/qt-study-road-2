#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "food.h"

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

class Snake;

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(QGraphicsScene *scene, QObject *parent);

    void snakeAteFood(Food *food);
    void snakeAteItself();

signals:

public slots:
    void pause();
    void resume();

private:
    void addNewFood();


    QTimer timer;
    QGraphicsScene &scene;
    Snake *snake;
};

#endif // GAMECONTROLLER_H
