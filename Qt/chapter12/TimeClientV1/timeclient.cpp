#include "timeclient.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QDateTime>
#include <QMessageBox>

TimeClient::TimeClient(QWidget *parent)
    : QDialog(parent)
{
    lab1=new QLabel(tr("服务器名:"));
    line1=new QLineEdit;

    lab2=new QLabel(tr("端口:"));
    line2=new QLineEdit;

    dataEdit=new QDateTimeEdit();
    QHBoxLayout *qhb=new QHBoxLayout;
    qhb->addWidget(dataEdit);


    lab3=new QLabel(tr("请先运行时间服务器!"));
    QHBoxLayout *qhb1=new QHBoxLayout;
    qhb1->addWidget(lab3);


    QGridLayout *grid=new QGridLayout();
    grid->addWidget(lab1,0,0);
    grid->addWidget(line1,0,1);
    grid->addWidget(lab2,1,0);
    grid->addWidget(line2,1,1);

    btn1=new QPushButton(tr("获取时间"));
    btn2=new QPushButton(tr("退出"));
    QHBoxLayout *qhb2=new QHBoxLayout;
    qhb2->addStretch();
    qhb2->addWidget(btn1);
    qhb2->addWidget(btn2);

    QVBoxLayout *qvb=new QVBoxLayout(this);
    qvb->addLayout(grid);
    qvb->addLayout(qhb);
    qvb->addLayout(qhb1);
    qvb->addLayout(qhb2);

    connect(line1,SIGNAL(textChanged(QString)),this,SLOT(enableGetbtn()));
    connect(line2,SIGNAL(textChanged(QString)),this,SLOT(enableGetbtn()));


    connect(btn1,SIGNAL(clicked(bool)),this,SLOT(getTime()));
    connect(btn2,SIGNAL(clicked(bool)),this,SLOT(close()));


    tcpScoket=new QTcpSocket(this);

    connect(tcpScoket,SIGNAL(readyRead()),this,SLOT(readTime()));
    connect(tcpScoket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(showError(QAbstractSocket::SocketError)),
            Qt::DirectConnection);
    line2->setFocus();
}

TimeClient::~TimeClient()
{

}
void TimeClient::enableGetbtn()
{
    btn1->setEnabled((!line1->text().isEmpty())&&!(line2->text().isEmpty()));
}
void TimeClient::getTime()
{
    btn1->setEnabled(false);
    time2u=0;
    tcpScoket->abort();
    tcpScoket->connectToHost(line1->text(),line2->text().toInt());

}
void TimeClient::readTime()
{
    QDataStream in(tcpScoket);
    in.setVersion(QDataStream::Qt_5_8);
    if(time2u==0)
    {
        if(tcpScoket->bytesAvailable()<(int)sizeof(uint))
            return;
        in>>time2u;
    }
   dataEdit->setDateTime(QDateTime::fromTime_t(time2u));
   btn1->setEnabled(true);
}
void TimeClient::showError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:

        break;
    case QAbstractSocket::HostNotFoundError:QMessageBox::information(this,
                                                                     tr("时间服务客户端"),
                                                                     tr("主机不可达!"));

    case QAbstractSocket::ConnectionRefusedError:QMessageBox::information(this,
                                                                          tr("时间服务客户端"),
                                                                          tr("连接被拒绝!"));
    default:
        QMessageBox::information(this,tr("时间服务客户端"),
                                 tr("产生如下错误:!.").arg(tcpScoket->errorString()));
        break;
    }
    btn1->setEnabled(true);
}
