#include "mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPainter *painter = new QPainter(this);

    QRadialGradient gradient(50, 50, 50, 50, 50);
    gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
    gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));

    QBrush brush(gradient);

    painter->setBrush(brush);
    painter->drawRect(10, 10, 100, 100);
}

MainWindow::~MainWindow() {}
