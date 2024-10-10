// #include "mainwindow.h"
#include "booleanwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // MainWindow w;
    // w.show();

    BooleanWindow window;
    window.show();

    return a.exec();
}
