#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QObject>

class EventFilter : public QObject
{
    Q_OBJECT
public:
    explicit EventFilter( QObject *watchedm, QObject *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event);

signals:

private:
    QObject *m_watched;
};

#endif // EVENTFILTER_H
