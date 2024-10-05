// #include "mainwindow.h"
#include "mylistview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // MainWindow w;
    // w.show();

    MyListView mlv;
    mlv.show();

    return a.exec();
}
