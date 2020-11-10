#include "dialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include "timeserver.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    lab1=new QLabel(tr("服务器端口:"));
    lab2=new QLabel();           //显示连接次数

    quitBtn=new QPushButton(tr("退出"));
    QHBoxLayout *qhb=new QHBoxLayout;
    qhb->addStretch(1);
    qhb->addWidget(quitBtn);
    qhb->addStretch(1);

    QVBoxLayout *qvb=new QVBoxLayout(this);
    qvb->addWidget(lab1);
    qvb->addWidget(lab2);
    qvb->addLayout(qhb);

    connect(quitBtn,SIGNAL(clicked(bool)),this,SLOT(close()));
    count=0;
    timeSever=new TimeServer(this);
    if(!timeSever->listen())
    {
        QMessageBox::critical(this,tr("多线程时间服务器"),
                              tr("无法启动服务器 %1.").arg(timeSever->errorString()));

        close();
        return;
    }

    lab1->setText(tr("服务器端口: %1.").arg(timeSever->serverPort()));

}

Dialog::~Dialog()
{

}

void Dialog::slotShow()
{
    lab2->setText(tr("第%1次请求完毕。").arg(++count));
}
