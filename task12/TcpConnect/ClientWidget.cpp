#include "ClientWidget.h"
#include "ui_ClientWidget.h"
#include <QHostAddress>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
     setWindowTitle("Client");
    st2=NULL;
    //分配空间
    st2=new QTcpSocket(this);
    connect(st2,&QTcpSocket::connected,
           [=]()
    {
        ui->readedit->setText("connect scuess");
    }
            );
    connect(st2,&QTcpSocket::readyRead,
           [=]()
    {
        //获取对方发送的消息
        arr2 =st2->readAll();
        //放入编辑框
        ui->readedit->append(arr2);
    }
            );
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_connectbutton_clicked()
{
    //从lineedit中获取服务器端口和ip
    QString ip=ui->ipedit->text();
    qint16 port=ui->portedit->text().toInt();
    //主动和服务器建立连接
    st2->connectToHost(QHostAddress(ip),port);
}
void ClientWidget::on_closebutton_clicked()
{
    //主动和对方断开连接
     st2->disconnectFromHost();
     st2->close();
}

void ClientWidget::on_sendbutton_clicked()
{
    //获取编辑框内容
    QString str=ui->writeedit->toPlainText();
    //发送消息

    st2->write(str.toUtf8().data());//str.toUtf8().data()
    qDebug()<<"send"<<str.toUtf8().data();

}

void ClientWidget::on_pushButton_3_clicked()
{
        qDebug()<<QString(arr2);
}
