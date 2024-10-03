#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H


#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

class Snake;

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(QGraphicsScene *scene, QObject *parent);

signals:

public slots:
    void pause();
    void resume();

private:
    QTimer timer;
    QGraphicsScene &scene;
    Snake *snake;
};

#endif // GAMECONTROLLER_H
