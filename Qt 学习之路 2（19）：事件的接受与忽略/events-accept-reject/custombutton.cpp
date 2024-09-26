#include "custombutton.h"
#include <QMouseEvent>

CustomButton::CustomButton(QWidget *parent) :
    QPushButton(parent)
{
    connect(this, &CustomButton::clicked,
            this, &CustomButton::onButtonCliecked);
}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
    // if (event->button() == Qt::LeftButton) {
    //     qDebug() << "left";
    // } else {
    //     QPushButton::mousePressEvent(event);
    // }

    qDebug() << "CustomButton";

}

void CustomButton::onButtonCliecked()
{
    //因为CustomButton覆盖了mousePressEvent()，所以clicked()信号被覆盖不见了。故这个slot是不会被激活的
    qDebug() << "You clicked this!";
}
