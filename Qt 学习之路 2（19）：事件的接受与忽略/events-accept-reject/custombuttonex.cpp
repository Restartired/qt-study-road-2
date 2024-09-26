#include "custombuttonex.h"
#include <QMouseEvent>
CustomButtonEx::CustomButtonEx(QWidget *parent) : CustomButton(parent){}

void CustomButtonEx::mousePressEvent(QMouseEvent *event){
    // event->accept();
    event->ignore();
    qDebug() << "CustomButtonEx";
}
