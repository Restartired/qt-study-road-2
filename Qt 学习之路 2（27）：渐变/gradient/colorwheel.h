#ifndef COLORWHEEL_H
#define COLORWHEEL_H
#include <QPaintEvent>
#include <QWidget>

class ColorWheel : public QWidget {
    Q_OBJECT
public:
    ColorWheel(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // COLORWHEEL_H
