// #include "mainwindow.h"
#include "clipboarddemo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // MainWindow w;
    // w.show();

    ClipboardDemo cb;
    cb.show();

    return a.exec();
}
