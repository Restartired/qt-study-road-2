#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    WorkerThread(QObject *parent = 0)
        : QThread(parent)
    {
    }
protected:
    void run()
    {
        for (int i = 0; i < 1000000000; i++){};
        emit done();
    }
signals:
    void done();
};

#endif // WORKERTHREAD_H
