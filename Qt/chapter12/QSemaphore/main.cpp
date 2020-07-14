#include <QCoreApplication>
#include <QSemaphore>
#include <QThread>
#include "stdio.h"

const int DataSize= 1000;
const int BufferSize=80;
int buffer[BufferSize];
QSemaphore freeBytes(BufferSize);
QSemaphore usedBytes(0);

class producer:public QThread
{
public:
    producer() {}
protected:
    void run();
};
void producer::run()
{
    for(int i=0;i<DataSize;i++)
    {
        freeBytes.acquire();        //生产者获取空闲资源
        buffer[i%BufferSize]= (i%BufferSize);
        usedBytes.release();
    }
}
class sumducer:public QThread
{
public:
    sumducer() {}
protected:
    void run();
};

void sumducer::run()
{
    for(int i=0;i<DataSize;i++)
    {
           usedBytes.acquire();
           fprintf(stderr,"%d",buffer[i%BufferSize]);
           if(i%16==0&&i!=0)
               fprintf(stderr,"\n");
           freeBytes.release();
    }
    fprintf(stderr,"\n");
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    producer produ;
    sumducer sumdu;
    produ.start();
    sumdu.start();


    produ.wait();
    sumdu.wait();

    return a.exec();
}
