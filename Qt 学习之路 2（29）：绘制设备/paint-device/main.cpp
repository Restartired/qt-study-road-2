#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // w.resize(150, 150);// 设置窗口大小
    w.show();
    return a.exec();
}
