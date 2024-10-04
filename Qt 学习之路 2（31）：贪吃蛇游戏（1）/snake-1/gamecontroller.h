#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QAction>

class Snake;
class Food;
class Wall;

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(QGraphicsScene *scene, QObject *parent);
    ~GameController();

    void snakeAteFood(Food *food);
    void snakeHitWall(Snake *snake, Wall *wall);
    void snakeAteItself();
    QAction *getResmueAction(){ return resumeAction;}
    void setResumeAction(QAction* r){ resumeAction = r; }

public slots:
    void pause();
    void resume();
    void gameOver();

protected:
    bool eventFilter(QObject *object, QEvent *event);

private:
    void handleKeyPressed(QKeyEvent *event);
    void addNewFood();
    void setResume();
    QAction * resumeAction;
    QTimer timer;
    QGraphicsScene *scene;
    Snake *snake;
    bool isPause;
};

#endif // GAMECONTROLLER_H
