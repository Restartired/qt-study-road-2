#include "testwidget.h"
#include <QPainter>

TestWidget::TestWidget(QWidget *parent)
    : QWidget{parent}
{}

void TestWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);

    QRadialGradient gradient(50, 50, 50, 50, 50);
    gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
    gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));

    QBrush brush(gradient);

    // QPen pen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    // painter.setPen(pen);
    QPen pen;  // creates a default pen
    pen.setStyle(Qt::DashDotLine);
    pen.setWidth(3);
    pen.setBrush(Qt::green);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);

    QVector<qreal> dashes;
    qreal space = 4;
    dashes << 1 << space << 3 << space << 9 << space
           << 27 << space << 9 << space;
    pen.setDashPattern(dashes);

    painter.setBrush(brush);
    painter.drawRect(10, 10, 100, 100);
}
