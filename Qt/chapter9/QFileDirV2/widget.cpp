#include "widget.h"
#include <QApplication>


#include <QDebug>

#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    sizeFileDir();
    fileShow();
}

Widget::~Widget()
{

}
//14:29   14:40
//14:45   15:00

void Widget::sizeFileDir()
{
    QStringList arg=qApp->arguments();
    QString path;
    if(arg.count()>1)
    {
        path=arg[1];
    }
    else
    {
        path =QDir::currentPath();
    }

    qDebug()<<path;
    du(path);
}

quint64 Widget::du(const QString path)
{
    QDir dir(path);
    quint64 size =0;
    foreach (QFileInfo fileInfo,dir.entryInfoList(QDir::Files))
    {
        size+=fileInfo.size();
    }
    foreach (QString subDir, dir.entryList(QDir::Dirs |QDir::NoDotAndDotDot))
    {
        size+=du(path + QDir::separator()+subDir);
    }

    char unit='B';
    quint64 curSize=size;
    if(curSize>1024)
    {
        curSize/=1024;
        unit='K';
        if(curSize>1024)
        {
            curSize/=1024;
            unit='M';
            if(curSize>1024)
               {
                    curSize/=1024;
                    unit='G';
                }
        }
    }
    qDebug()<<curSize<<unit;
    return size;
}


void Widget::fileShow()
{
   line=new QLineEdit(tr("/"));
   listWidget=new QListWidget;

   QVBoxLayout *qvb=new QVBoxLayout(this);
   qvb->addWidget(line);
   qvb->addWidget(listWidget);
   connect(line,SIGNAL(returnPressed()),this,SLOT(showDir(QDir)));
   connect(listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(slotDirShow(QListWidgetItem *)));

   QString root="/";
   QDir dir(root);
   QStringList string;
   string<<"*";
   QFileInfoList list=dir.entryInfoList(string);
    showFileInfoList(list);
}


void Widget::showDir(QDir dir)
{
    QStringList string;
    string<<"*";
    QFileInfoList list = dir.entryInfoList(string,QDir::AllEntries,QDir::DirsFirst);

    showFileInfoList(list);
}
void Widget::slotDirShow(QListWidgetItem *item)
{
    QString str=item->text();
    QDir dir;
    dir.setPath(line->text());
    dir.cd(str);
    line->setText(dir.absolutePath());
    showDir(dir);
}
void Widget::showFileInfoList(QFileInfoList list)
{
    listWidget->clear();
    for(unsigned int i=0;i<list.count();i++)
    {
        QFileInfo tmpInfo=list.at(i);
        if(tmpInfo.isDir())
        {
            QIcon icon("F:/1.png");
            QString dirName=tmpInfo.fileName();
            QListWidgetItem *tmp=new QListWidgetItem(icon,dirName);
            listWidget->addItem(tmp);
        }
        else if (tmpInfo.isFile())
        {
            QIcon icon1("F:/2.png");
            QString fileSName=tmpInfo.fileName();
            QListWidgetItem *tmp2=new QListWidgetItem(icon1,fileSName);
            listWidget->addItem(tmp2);
        }

    }
}


