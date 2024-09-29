#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include <QWidget>

class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintedWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);

signals:
};

#endif // PAINTEDWIDGET_H
