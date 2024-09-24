#ifndef READER_H
#define READER_H

#include <QObject>
#include <QDebug>

class Reader : public QObject
{
    Q_OBJECT
public:
    explicit Reader(QObject *parent = nullptr);

    void receiveNewspaper(const QString & name){
        qDebug() << "Receives Newspaper: " << name;
    }

signals:
};

#endif // READER_H
