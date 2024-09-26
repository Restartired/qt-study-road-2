#include "customwidget.h"
#include <QMouseEvent>
CustomWidget::CustomWidget(QWidget *parent)
    : QWidget{parent}
{}

void CustomWidget::mousePressEvent(QMouseEvent *event)
{
    // QWidget::mousePressEvent(event);
    event->ignore();
    qDebug() << "CustomWidget";
}
