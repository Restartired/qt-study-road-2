// #include "mainwindow.h"

#include <QApplication>
#include <QtGui>

#include "projectdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // MainWindow w;
    // w.show();

    ProjectDialog dialog;
    dialog.show();

    return a.exec();
}
