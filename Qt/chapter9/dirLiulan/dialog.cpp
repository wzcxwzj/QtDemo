#include "dialog.h"
#include <QVBoxLayout>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    line=new QLineEdit(tr("/"));

    listWidget=new QListWidget;

    QVBoxLayout *qvb=new QVBoxLayout(this);
    qvb->addWidget(line);
    qvb->addWidget(listWidget);

//    connect(line,SIGNAL(returnPressed()),this,SLOT(showDir(QDir)));
    connect(listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(sloShowDir(QListWidgetItem *)));

    QString root="/";
    QDir dir(root);
    QStringList string;
    string<<"*";
    QFileInfoList list=dir.entryInfoList(string);
    showFileInfoList(list);

}

Dialog::~Dialog()
{

}
void Dialog::showFileInfoList(QFileInfoList list)
{
    listWidget->clear();
    for(int i=0;i<list.size();i++)
    {
        QFileInfo info=list.at(i);
        if(info.isDir())
        {
           QIcon icon("F:/1.png");
           QString pName=info.fileName();
           QListWidgetItem *item=new QListWidgetItem(icon,pName);
           listWidget->addItem(item);
        }
        else
        {
            QIcon ico("F:/2.png");
            QString Name=info.fileName();
            QListWidgetItem *item1=new QListWidgetItem(ico,Name);
            listWidget->addItem(item1);
        }
    }

}
void Dialog::showDir(QDir dir)
{

    qDebug()<<"我是自定义信号触发的...";
    QStringList string;
    string<<"*";
    QFileInfoList list=dir.entryInfoList(string,QDir::AllEntries,QDir::DirsFirst);
    showFileInfoList(list);
}

void Dialog::sloShowDir(QListWidgetItem *item)
{
    QString str=item->text();
    QDir dir;
    dir.setPath(line->text());
    dir.cd(str);
    line->setText(dir.absolutePath());
    showDir(dir);
}





