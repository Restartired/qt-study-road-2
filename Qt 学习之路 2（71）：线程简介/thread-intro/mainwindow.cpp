#include "mainwindow.h"
#include "workerthread.h"

#include <QVBoxLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    widget->setLayout(layout);
    QLCDNumber *lcdNumber = new QLCDNumber(this);
    layout->addWidget(lcdNumber);
    QPushButton *button = new QPushButton(tr("Start"), this);
    layout->addWidget(button);
    setCentralWidget(widget);
    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, [=]() {
        static int sec = 0;
        lcdNumber->display(QString::number(sec++));
    });

    WorkerThread *thread = new WorkerThread(this);
    connect(thread, &WorkerThread::done, timer, &QTimer::stop);
    connect(thread, &WorkerThread::finished, thread, &WorkerThread::deleteLater);
    connect(button, &QPushButton::clicked, [=]() {
        timer->start(1);
        thread->start();
    });
}



MainWindow::~MainWindow() {}
