// #include "mainwindow.h"
#include "testwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TestWidget widget;
    widget.resize(120, 120);
    widget.show();

    return a.exec();
}
