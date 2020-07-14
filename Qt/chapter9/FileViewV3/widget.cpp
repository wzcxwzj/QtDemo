#include "widget.h"
#include <QVBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    line =new QLineEdit(tr("/"));
    listWidget =new QListWidget;
    QVBoxLayout *qvb=new QVBoxLayout(this);
    qvb->addWidget(line);
    qvb->addWidget(listWidget);

    connect(line,SIGNAL(returnPressed()),this,SLOT(showSlotDir(QDir)));
    connect(listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),SLOT(slotDirShow(QListWidgetItem *)));
    connect(line,SIGNAL(returnPressed()),this,SLOT(showir()));
    QString root="/";
    QDir dir(root);
    QStringList string;
    string<<"*";
    QFileInfoList list=dir.entryInfoList(string);

    showFileinfoList(list);
}

Widget::~Widget()
{

}
void Widget::showSlotDir(QDir dir)
{qDebug()<<"sddwd";
    QStringList string;
    string<<"*";
    QFileInfoList list=dir.entryInfoList(string,QDir::AllEntries,QDir::DirsFirst);

    showFileinfoList(list);
}
void Widget::showFileinfoList(QFileInfoList list)
{
    listWidget->clear();
    for(unsigned int i=0;i<list.count();i++)
    {
        QFileInfo tmpFiles=list.at(i);
        if(tmpFiles.isDir())
        {
            QIcon icon("F:/1.png");
            QString strName=tmpFiles.fileName();
            QListWidgetItem *tmp=new QListWidgetItem(icon,strName);
            listWidget->insertItem(i,tmp);
        }
        else if(tmpFiles.isFile())
        {
            QIcon icon1("F:/2.png");
            QString fileName=tmpFiles.fileName();
            QListWidgetItem *tmp1=new QListWidgetItem(icon1,fileName);
            listWidget->insertItem(i,tmp1);
        }
    }
}
void Widget::slotDirShow(QListWidgetItem *item)
{
    QString str= item->text();
    QDir dir;
    dir.setPath(line->text());
    dir.cd(str);
    line->setText(dir.absolutePath());
    showSlotDir(dir);
}
void Widget::showir()
{
    qDebug()<<"sssss";
}
