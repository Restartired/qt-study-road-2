// #include "mainwindow.h"
#include "paintdemo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    PaintDemo pd;
    pd.show();

    return a.exec();
}
