#ifndef SNAKE_H
#define SNAKE_H

#include "gamecontroller.h"

#include <QGraphicsItem>

class Snake : public QGraphicsItem
{
public:
    enum Direction {
        NoMove,
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown
    };

    Snake(GameController &controller);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

private:
    QPoint head;
    int growing;
    int speed;
    QList<QPointF> tail;

    Direction moveDirection;
    GameController &controller;
};

#endif // SNAKE_H
