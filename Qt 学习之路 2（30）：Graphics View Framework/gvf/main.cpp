// #include "mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 300, 300);
    scene.addLine(0, 0, 150, 150);

    QGraphicsView view(&scene);
    view.setWindowTitle("Graphics View");
    // view.resize(500, 500);
    view.show();

    return a.exec();
}
