// #include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QMouseEvent>

class EventLabel : public QLabel
{
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};
void EventLabel::mouseMoveEvent(QMouseEvent *event)
{
    this->setText(QString("<center><h1>Move: (%1, %2)</h1></center>")
                      .arg(QString::number(event->position().x()), QString::number(event->position().y())));
    //main.cpp:17:51: 'x' is deprecated: Use position()
}
void EventLabel::mousePressEvent(QMouseEvent *event)
{
    this->setText(QString("<center><h1>Press: (%1, %2)</h1></center>")
                      .arg(QString::number(event->position().x()), QString::number(event->position().y())));
}
void EventLabel::mouseReleaseEvent(QMouseEvent *event)
{
    // QString msg;
    // msg.asprintf("<center><h1>Release: (%d, %d)</h1></center>",
    //             event->position().x(), event->position().y());
    // this->setText(msg);
    //main.cpp:28:9: No member named 'sprintf' in 'QString'
    // QString::asprintf，没有正确给msg赋值，显示空白。于是还是用前两种一样的方法。
    this->setText(QString("<center><h1>Release: (%1, %2)</h1></center>")
                      .arg(QString::number(event->position().x()), QString::number(event->position().y())));

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    EventLabel *label = new EventLabel;
    label->setWindowTitle("MouseEvent Demo");
    label->resize(300, 200);
    label->setMouseTracking(true);
    label->show();

    return a.exec();
}
