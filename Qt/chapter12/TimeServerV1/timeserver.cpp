#include "timeserver.h"
#include "dialog.h"

TimeServer::TimeServer(QObject *parent):QTcpServer(parent)
{
    //首先启动线程
    //
    dlg=(Dialog *)parent;
}

void TimeServer::incomingConnection(int socketDescriptor)
{
    TimeThread *timeThread=new TimeThread(socketDescriptor,0);
    connect(timeThread,SIGNAL(finished()),dlg,SLOT(slotShow()));
    connect(timeThread,SIGNAL(finished()),timeThread,SLOT(deleteLater()),Qt::DirectConnection);
    timeThread->start();
}

