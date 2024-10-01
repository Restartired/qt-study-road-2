#include "mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{}

MainWindow::~MainWindow() {}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    QLinearGradient linearGradient(60, 50, 200, 200);
    linearGradient.setColorAt(0.2, Qt::white);
    linearGradient.setColorAt(0.6, Qt::green);
    linearGradient.setColorAt(1.0, Qt::black);
    painter.setBrush(QBrush(linearGradient));
    painter.drawEllipse(50, 50, 200, 150);
}
