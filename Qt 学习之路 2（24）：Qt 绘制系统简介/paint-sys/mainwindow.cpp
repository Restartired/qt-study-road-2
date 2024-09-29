#include "mainwindow.h"
#include "paintedwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    PaintedWidget *pw = new PaintedWidget(this);
    pw->show();
}

MainWindow::~MainWindow() {}
