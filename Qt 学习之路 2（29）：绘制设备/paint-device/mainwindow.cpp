#include "mainwindow.h"
#include <QPainter>
#include <QPicture>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{}

MainWindow::~MainWindow() {}

void MainWindow::paintEvent(QPaintEvent *)
{
    // QPainter painter(this);
    // QPixmap pixmap(":/logo/qt-development-black");
    // QBitmap bitmap(":/logo/qt-development-black");
    // painter.drawPixmap(10, 10, 250, 125, pixmap);
    // painter.drawPixmap(270, 10, 250, 125, bitmap);
    // QPixmap whitePixmap(":/logo/qt-development-neon-transparent");
    // QBitmap whiteBitmap(":/logo/qt-development-neon-transparent");
    // painter.drawPixmap(10, 140, 250, 125, whitePixmap);
    // painter.drawPixmap(270, 140, 250, 125, whiteBitmap);
    // //貌似改了耶，6.72位图不会把透明转换成黑色了。





    // QImage image(3,3,QImage::Format_RGB32);
    // QRgb value;

    // value = qRgb(189, 149, 39); // 0xffbd9527
    // image.setPixel(1, 1, value);

    // value = qRgb(122, 163, 39); // 0xff7aa327
    // image.setPixel(0, 1, value);
    // image.setPixel(1, 0, value);

    // value = qRgb(237, 187, 57); // 0xffedba31
    // image.setPixel(2, 1, value);

    // QPainter painter(this);
    // // painter.drawImage(0, 0, image);

    // // 计算放大倍数
    // int scale = 50; // 50 像素放大一倍
    // QRect targetRect(0, 0, image.width() * scale, image.height() * scale);
    // painter.drawImage(targetRect, image);




    // QPicture picture;
    // QPainter painter;
    // painter.begin(&picture);             // 在 picture 进行绘制
    // painter.drawEllipse(10, 20, 80, 70); // 绘制一个椭圆
    // painter.end();                       // 绘制完成
    // picture.save("drawing.pic");         // 保存 picture
    //找半天...原来创在build里面了...看来没注意到这里的相对路径是在build里面的debug里面（因为我的运行模式是debug)
    //picture.save("../../drawing.pic"); // 当前目录

    QPicture picture;
    picture.load("drawing.pic");           // 加载 picture
    // QPainter painter;
    // painter.begin(this);               // 在 myImage 上开始绘制
    // painter.drawPicture(0, 0, picture);    // 在 (0, 0) 点开始绘制 picture
    // painter.end();

    QPainter painter(this);
    picture.play(&painter);
}
