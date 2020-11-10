#include "timethread.h"
#include <QDataStream>
#include <QDateTime>
#include <QDebug>
TimeThread::TimeThread(int socketDescriptor,QObject *parent)
    :QThread(parent),socketDescriptor(socketDescriptor)
{

}

void TimeThread::run()
{
    QTcpSocket tcpSoket;//创建套接字
    if(!tcpSoket.setSocketDescriptor(socketDescriptor))//判断是否出错
    {
        return ;
    }
    QByteArray block;   //QByteArry
    QDataStream out(&block,QIODevice::WriteOnly);//以流的方式写入
    out.setVersion(QDataStream::Qt_5_8);         //流的版本
    uint time2u=QDateTime::currentDateTime().toTime_t();   //获取日期
    qDebug()<<time2u;
    out<<time2u;//将日期写入流里面
    tcpSoket.write(block); //套接字向客户端发数据
    tcpSoket.disconnectFromHost();//套接子断开连接
    tcpSoket.waitForDisconnected();//tcpSoket.waitForConnected();//套接字等待返回
}
