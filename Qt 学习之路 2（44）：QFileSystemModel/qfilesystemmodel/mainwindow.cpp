#include "mainwindow.h"
#include "filesystemwidget.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget(this);
    this->setCentralWidget(widget);
    this->setWindowTitle(tr("File System Model"));

    FileSystemWidget *fsw = new FileSystemWidget(widget);
    fsw->show();

    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->addWidget(fsw);
}

MainWindow::~MainWindow() {}
