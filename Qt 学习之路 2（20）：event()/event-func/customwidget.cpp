#include "customwidget.h"
#include <QEvent>
#include <QKeyEvent>

CustomWidget::CustomWidget(QWidget *parent)
    : QWidget{parent}
{}

bool CustomWidget::event(QEvent *e)
{
    // qDebug() << "Have a " << e->type();
    if (e->type() == QEvent::KeyPress) {
        // qDebug() << "You press Key";
        // QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
        QKeyEvent *keyEvent = dynamic_cast<QKeyEvent *>(e);
        qDebug() << "You press" << keyEvent->text();
        if (keyEvent->key() == Qt::Key_Tab) {
            qDebug() << "You press tab.";
            return true;//如果这里返回的话，那么就没有把按下Tab的信号转交给父组件
        }
    }
    return QWidget::event(e);//信号转交给父组件。
    // return false;//不转交这个信号，就是只处理按下Tab的信号。
}
