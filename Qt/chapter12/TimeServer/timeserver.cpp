#include "timeserver.h"
#include "dialog.h"
#include "timethread.h"

TimeServer::TimeServer(QObject *parent):QTcpServer(parent)
{
    dlg=(Dialog *)parent;
}

void TimeServer::incomingConnection(int socketDescriptor)
{
    //创建线程
    TimeThread *timeThread=new TimeThread(socketDescriptor,0);
    connect(timeThread,SIGNAL(finished()),dlg,SLOT(slotShow()));
    connect(timeThread,SIGNAL(finished()),timeThread,SLOT(deleteLater()),Qt::DirectConnection);
    timeThread->start();
}
