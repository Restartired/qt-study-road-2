#include "mainwindow.h"
#include "sortview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    SortView *sv = new SortView(this);
    sv->show();
    this->setCentralWidget(sv);
}

MainWindow::~MainWindow() {}
