#include "workthread.h"
#include <QDebug>

WorkThread::WorkThread()
{

}

void WorkThread::run()      //线程处理函数
{
    while(true)
    {
        for(int n=0;n<10;n++)
        {
            qDebug()<<n<<n<<n<<n<<n<<n<<n<<n;
        }
    }
}
