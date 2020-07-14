#include "dialog.h"
#include <QVBoxLayout>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    line=new QLineEdit(tr("/"));
    connect(line,SIGNAL(returnPressed()),this,SLOT(slotShow(QDir)));

    listWidget=new QListWidget();
    connect(listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(slotDirShow(QListWidgetItem *)));

    QVBoxLayout *qvb=new QVBoxLayout(this);
    qvb->addWidget(line);
    qvb->addWidget(listWidget);

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

void Dialog::slotShow(QDir dir)
{
    QStringList string;
    string<<"*";

    QFileInfoList list=dir.entryInfoList(string,QDir::AllEntries,QDir::DirsFirst);
    showFileInfoList(list);
}

void Dialog::showFileInfoList(QFileInfoList list)
{
    listWidget->clear();        //首先先清空列表控件
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
        else if(info.isFile())
        {
            QIcon icon("F:/2.png");
            QString pName=info.fileName();
            QListWidgetItem *item0=new QListWidgetItem(icon,pName);
            listWidget->addItem(item0);
        }
    }
}

void Dialog::slotDirShow(QListWidgetItem *item)
{
    QString str=item->text();
    qDebug()<<str;
    QDir dir;
    dir.setPath(line->text());        //设置QDir对象的路径为当前目录路径
    dir.cd(str);                      //根据下一级目录名重新设置QDir对象的路径
    line->setText(dir.absolutePath());//刷新当前的目录路径
    slotShow(dir);          //显示当前路径下的所有文件
}
