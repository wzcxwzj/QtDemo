#include "timeclient.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDateTime>
#include <QDataStream>
#include <QMessageBox>

TimeClient::TimeClient(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("多线程时间客户端"));
    serverName=new  QLabel(tr("服务器名:"));
    serverNameLine=new QLineEdit;

    serverportName=new QLabel(tr("端口:"));
    serverportNameLine=new QLineEdit;

    QGridLayout *grid=new QGridLayout();
    grid->addWidget(serverName,0,0);
    grid->addWidget(serverNameLine,0,1);
    grid->addWidget(serverportName,1,0);
    grid->addWidget(serverportNameLine,1,1);

    dateLineEdit=new QDateTimeEdit;

    stateLabel=new QLabel(tr("请首先运行时间服务器!"));

    getBtn=new QPushButton(tr("获取时间"));
    quitBtn=new QPushButton(tr("退出"));
    QHBoxLayout *qhb2=new QHBoxLayout();
    qhb2->addStretch();
    qhb2->addWidget(getBtn);
    qhb2->addWidget(quitBtn);

    QVBoxLayout *qvb=new  QVBoxLayout(this);
    qvb->addLayout(grid);
    qvb->addWidget(dateLineEdit);
    qvb->addWidget(stateLabel);
    qvb->addLayout(qhb2);

    connect(serverNameLine,SIGNAL(textChanged(QString)),this,SLOT(enableGetbtn()));
    connect(serverportNameLine,SIGNAL(textChanged(QString)),this,SLOT(enableGetbtn()));

    connect(getBtn,SIGNAL(clicked(bool)),this,SLOT(getTime()));
    connect(quitBtn,SIGNAL(clicked(bool)),this,SLOT(close()));


    tcpSocket=new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readTime()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,
            SLOT(showError(QAbstractSocket::SocketError)));
    serverportNameLine->setFocus();
}

TimeClient::~TimeClient()
{

}

void TimeClient::enableGetbtn()
{
    getBtn->setEnabled(!serverNameLine->text().isEmpty()&&!serverportNameLine->text().isEmpty());
}

void TimeClient::getTime()
{
    getBtn->setEnabled(false);
    time2u=0;
    tcpSocket->abort();
    tcpSocket->connectToHost(serverNameLine->text(),serverportNameLine->text().toInt());

}

void TimeClient::readTime()
{
   QDataStream in(tcpSocket);
   in.setVersion(QDataStream::Qt_5_8);
   if(time2u==0)
   {
           if(tcpSocket->bytesAvailable()<(int)sizeof(uint))
               return;
          in>>time2u;
    }
   dateLineEdit->setDateTime(QDateTime::fromTime_t(time2u));
   getBtn->setEnabled(true);
}

void TimeClient::showError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:QMessageBox::information(this,tr("时间服务客户端"),
                                                                     tr("主机不可达！"));
        break;
    case QAbstractSocket::ConnectionRefusedError:QMessageBox::information(this,tr("时间服务客户端"),
                                                                          tr("连接被拒绝！"));
        break;
    default:
        QMessageBox::information(this,tr("时间服务客户端"),
                            tr("产生如下错误: !.").arg(tcpSocket->errorString()));
        break;
    }
    getBtn->setEnabled(true);
}
