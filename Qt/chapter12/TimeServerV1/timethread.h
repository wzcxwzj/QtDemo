#ifndef TIMETHREAD_H
#define TIMETHREAD_H

#include <QThread>
#include <QtNetwork>
#include <QTcpSocket>


class TimeThread : public QThread
{
public:
    TimeThread(int socketDescriptor,QObject *parent=0);
    void run();             //线程执行函数

private:
    int socketDescriptor;
};

#endif // TIMETHREAD_H
