#include "colorwheel.h"
#include <QPainter>

ColorWheel::ColorWheel(QWidget *parent){
    setFixedSize(300, 300); // 设置小部件的固定大小
}

void ColorWheel::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    const int r = 150;
    QConicalGradient conicalGradient(0, 0, 0);
    conicalGradient.setColorAt(0.0, Qt::red);
    conicalGradient.setColorAt(60.0/360.0, Qt::yellow);
    conicalGradient.setColorAt(120.0/360.0, Qt::green);
    conicalGradient.setColorAt(180.0/360.0, Qt::cyan);
    conicalGradient.setColorAt(240.0/360.0, Qt::blue);
    conicalGradient.setColorAt(300.0/360.0, Qt::magenta);
    conicalGradient.setColorAt(1.0, Qt::red);
    painter.translate(r, r);
    QBrush brush(conicalGradient);
    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawEllipse(QPoint(0, 0), r, r);
}
