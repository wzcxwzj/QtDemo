#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QTcpServer>

#include "timethread.h"
class Dialog;
class TimeServer : public QTcpServer
{
public:
    TimeServer(QObject *parent=0);

    void incomingConnection(int socketDescriptor);

private:
    Dialog *dlg;
};

#endif // TIMESERVER_H
