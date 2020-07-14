#include "timethread.h"

#include <QByteArray>
#include <QDataStream>
#include <QDateTime>

//TimeThread::TimeThread()
//{

//}
TimeThread::TimeThread(int socketDescriptor,QObject *parent):
    QThread(parent),socketDescriptor(socketDescriptor)
{

}

void TimeThread::run()
{
    //创建套接字
    QTcpSocket tcpSocket;
    //创建失败,发送出错信号
    if(!tcpSocket.setSocketDescriptor(socketDescriptor))
    {
        //emit error(tcpSocket.error());

        return;
    }

    QByteArray block;
    //以流的方式将数据写入QByteArry
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_8);
    uint time2u=QDateTime::currentDateTime().toTime_t();
    out<<time2u;
    tcpSocket.write(block);


    //断开连接
    tcpSocket.disconnectFromHost();
    //等待返回
    tcpSocket.waitForDisconnected();

}
