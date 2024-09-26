#include "mainwindow.h"
// #include "custombutton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // CustomButton btn;
    // btn.setText("This is a Button!");
    // btn.show();

    return a.exec();
}
