#include "threaddlg.h"
#include <QHBoxLayout>

ThreadDlg::ThreadDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("线程");
    btn1=new  QPushButton(tr("开始"));
    btn2=new  QPushButton(tr("停止"));
    btn3=new  QPushButton(tr("退出"));

    QHBoxLayout *qhb=new QHBoxLayout(this);
    qhb->addWidget(btn1);
    qhb->addWidget(btn2);
    qhb->addWidget(btn3);

    connect(btn1,SIGNAL(clicked(bool)),this,SLOT(slotStart()));
    connect(btn2,SIGNAL(clicked(bool)),this,SLOT(slotStop()));
    connect(btn3,SIGNAL(clicked(bool)),this,SLOT(close()));

}

ThreadDlg::~ThreadDlg()
{

}

void ThreadDlg::slotStart()
{
    for(int i=0;i<MaxSize;i++)
    {
        workThread[i]=new WorkThread;
    }
    for(int j=0;j<MaxSize;j++)
    {
        workThread[j]->start();
    }
    btn1->setEnabled(false);
    btn2->setEnabled(true);
}

void ThreadDlg::slotStop()
{
    for(int i=0;i<MaxSize;i++)
    {
        workThread[i]->terminate();
        workThread[i]->wait();
    }
    btn2->setEnabled(false);
    btn1->setEnabled(true);
}
