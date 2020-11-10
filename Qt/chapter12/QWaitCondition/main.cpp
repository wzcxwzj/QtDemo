#include <QCoreApplication>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include <stdio.h>

const int DataSize= 1000;
const int BufferSize=80;
int buffer[BufferSize];
QWaitCondition bufferEmpty;
QWaitCondition bufferFull;
QMutex mutex;
int numbytes=0;     //缓冲区可用字节数
int rIndex=0;

class Producer:public QThread
{
public:
    Producer() {}
    void run();
};
void Producer::run()
{
    for(int i=0;i<DataSize;i++)
    {
        mutex.lock();
        if(numbytes==BufferSize)        //检查缓冲区是否填满
                  bufferEmpty.wait(&mutex);     //填满的话，就等空位
        buffer[i%BufferSize]=numbytes;
        ++numbytes;
        bufferFull.wakeAll();
        mutex.unlock();
    }
}

class Sumducer:public QThread
{
public:
    Sumducer() {}
    void run();
};
void Sumducer::run()
{
    forever
    {
        mutex.lock();
        if(numbytes==0)
            bufferFull.wait(&mutex);

        printf("%ul::[%d]=%d\n",currentThreadId(),rIndex,buffer[rIndex]);
        rIndex=(++rIndex)%BufferSize;

        --numbytes;
        bufferEmpty.wakeAll();
        mutex.unlock();
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Producer produ;
    Sumducer sumduA;
    Sumducer sumduB;

    produ.start();
    sumduA.start();
    sumduB.start();

    produ.wait();
    sumduA.wait();
    sumduB.wait();
    return a.exec();
}
