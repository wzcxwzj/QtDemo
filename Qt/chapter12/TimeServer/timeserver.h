#ifndef TIMESERVER_H
#define TIMESERVER_H


#include <QTcpServer>

class Dialog;
class TimeServer : public QTcpServer
{

public:
    TimeServer(QObject *parent=0);

protected:
    void incomingConnection(int socketDescriptor);   //服务端有连接到来时，执行这个函数

private:
    Dialog *dlg;


};

#endif // TIMESERVER_H
