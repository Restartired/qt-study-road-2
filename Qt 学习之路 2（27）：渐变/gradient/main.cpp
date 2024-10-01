// #include "mainwindow.h"
#include "colorwheel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    ColorWheel cw;
    cw.show();

    return a.exec();
}
