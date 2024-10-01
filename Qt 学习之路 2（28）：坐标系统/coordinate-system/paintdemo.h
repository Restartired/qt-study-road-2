#ifndef PAINTDEMO_H
#define PAINTDEMO_H

#include <QWidget>

class PaintDemo : public QWidget
{
    Q_OBJECT
public:
    explicit PaintDemo(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);

signals:
};

#endif // PAINTDEMO_H
