#include <QCoreApplication>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QSemaphore> //信号量
#include <stdio.h>

const int DataSize =1000;
const int BufferSize=80;
int buffer[BufferSize];
QSemaphore freeBytes(BufferSize);
QSemaphore userBytes(0);

class Producer :public QThread
{
public:
    producer();
    void run();
};
Producer::producer()
{

}
void Producer::run()
{
    for(int i=0;i<DataSize;i++)
    {
        freeBytes.acquire();
        buffer[i%BufferSize]=(i%BufferSize);
        userBytes.release();
    }
}
class Consumer:public QThread
{
public:
    Consumer();
    void run();
};
Consumer::Consumer()
{

}
void Consumer::run()
{
    for(int i=0;i<DataSize;i++)
    {
        userBytes.acquire();
        fprintf(stderr,"%d",buffer[i%BufferSize]);
        if(i%6 == i!=0)
            fprintf(stderr,"\n");
        freeBytes.release();
    }
    fprintf(stderr,"\n");
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer producer;
    Consumer consumer;

    producer.start();
    consumer.start();


    producer.wait();
    consumer.wait();
    return a.exec();
}
