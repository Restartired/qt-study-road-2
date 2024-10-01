#include "paintdemo.h"
#include <QPainter>

PaintDemo::PaintDemo(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(400, 400); // 设置小部件的固定大小
}

void PaintDemo::paintEvent(QPaintEvent *)
{
    // QPainter painter(this);
    // painter.fillRect(10, 10, 50, 100, Qt::red);
    // painter.save();
    // painter.translate(100, 0); // 向右平移 100px
    // painter.fillRect(10, 10, 50, 100, Qt::yellow);
    // painter.restore();
    // painter.save();
    // painter.translate(300, 0); // 向右平移 300px
    // painter.rotate(30); // 顺时针旋转 30 度
    // painter.fillRect(10, 10, 50, 100, Qt::green);
    // painter.restore();
    // painter.save();
    // painter.translate(400, 0); // 向右平移 400px
    // painter.scale(2, 3); // 横坐标单位放大 2 倍，纵坐标放大 3 倍
    // painter.fillRect(10, 10, 50, 100, Qt::blue);
    // painter.restore();
    // painter.save();
    // painter.translate(600, 0); // 向右平移 600px
    // painter.shear(0, 1); // 横向不变，纵向扭曲 1 倍
    // painter.fillRect(10, 10, 50, 100, Qt::cyan);
    // painter.restore();

    QPainter painter(this);
    // painter.setWindow(0, 0, 200, 200);

    // painter.translate(200, 200);
    // painter.setWindow(-160, -320, 320, 640);

    painter.setViewport(0, 0, 200, 200);

    painter.fillRect(0, 0, 200, 200, Qt::red);

}
