// #include "mainwindow.h"
#include "label.h"
#include "eventfilter.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Label label;
    app.installEventFilter(new EventFilter(&label, &label));
    label.show();
    return app.exec();
}
