#include <QCoreApplication>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QSemaphore> //信号量
#include <QWaitCondition>   //允许线程在一定条件下唤醒其他线程
#include <stdio.h>

const int DataSize =1000;
const int BufferSize=80;
int buffer[BufferSize];
QSemaphore freeBytes(BufferSize);
QSemaphore userBytes(0);

QWaitCondition bufferEmpty;
QWaitCondition bufferFull;
QMutex mutex;
int numUsedBytes=0;
int rIndex=0;
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
        mutex.lock();
        if(numUsedBytes == BufferSize)
            bufferEmpty.wait(&mutex);

        buffer[i%BufferSize]=(i%BufferSize);
        bufferFull.wakeAll();
        mutex.unlock();
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
    forever
    {
        mutex.lock();

        if(numUsedBytes == 0)
            bufferFull.wait(&mutex);

        printf("%ul::[%d]=%d\n",currentThreadId(),rIndex,buffer[rIndex]);

        rIndex=(++rIndex)%BufferSize;
        --numUsedBytes;
        bufferEmpty.wakeAll();
        mutex.unlock();
    }
    printf("\n");
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer producer;
    Consumer consumerA;
    Consumer consumerB;

    producer.start();
    consumerA.start();
    consumerB.start();


    producer.wait();
    consumerA.wait();
    consumerB.wait();
    return a.exec();
}
