#ifndef LABEL_H
#define LABEL_H

#include <QWidget>

class Label : public QWidget
{
    Q_OBJECT
public:
    explicit Label(QWidget *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event);

protected:
    void mousePressEvent(QMouseEvent *);
    bool event(QEvent *e);

signals:
};

#endif // LABEL_H
