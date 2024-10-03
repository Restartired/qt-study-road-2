#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gamecontroller.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>


// class QGraphicsScene;
// class QGraphicsView;
// class GameController;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // void adjustViewSize();

private:
    void initScene();
    void initSceneBackground();

    QGraphicsScene *scene;
    QGraphicsView *view;

    GameController *game;

    // GameController *game;
};
#endif // MAINWINDOW_H
