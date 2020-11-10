#include "dialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("多线程的时间服务器");
    lab1=new QLabel(tr("服务器连接次数:"));
    lab2=new QLabel;
    btn=new QPushButton(tr("退出"));

    QHBoxLayout *qhb=new QHBoxLayout;
    qhb->addStretch(1);
    qhb->addWidget(btn);
    qhb->addStretch(1);

    QVBoxLayout *qvb=new QVBoxLayout(this);
    qvb->addWidget(lab1);
    qvb->addWidget(lab2);
    qvb->addLayout(qhb);
    connect(btn,SIGNAL(clicked(bool)),this,SLOT(close()));

    count=0;
    timeServer=new TimeServer(this);
    if(!timeServer->listen())
    {
        QMessageBox::critical(this,tr("多线程的时间服务器..."),
                              tr("无法启动服务器:%1.").arg(timeServer->errorString()));
                close();
                return;
    }
    lab1->setText(tr("服务器端口: %1.").arg(timeServer->serverPort()));
}

Dialog::~Dialog()
{

}

void Dialog::slotShow()
{
    lab2->setText(tr("第%1次请求完毕...").arg(++count));
}
