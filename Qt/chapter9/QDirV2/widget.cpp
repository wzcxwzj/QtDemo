#include "widget.h"
#include <QApplication>
#include <QDir>
#include <QDebug>

//文件大小及路径获取实例
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QStringList arg =qApp->arguments();
    QString path;
    if(arg.count()>1)
    {
        path=arg[1];
    }
    else
    {
        path=QDir::currentPath();
    }

    qDebug()<<path<<endl;

    du(path);

}

Widget::~Widget()
{

}
qint64 Widget::du(const QString &path)
{
    QDir dir(path);
    quint64 size=0;
    foreach(QFileInfo fileInfo,dir.entryInfoList(QDir::Files))
    {
        size+=fileInfo.size();
    }
    foreach (QString subDir,dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        size += du(path +QDir::separator()+subDir);
    }

    char unit='B';
    quint64 curSize=size;
    if(curSize >1024)
    {
        curSize/=1024;
        unit='K';
        if (curSize >1024)
        {
            curSize/=1024;
            unit='M';
            if (curSize >1024)
            {
               curSize/=1024;
                unit='G';

            }
        }

     }
    qDebug()<<curSize<<unit;
    qDebug()<<"path:"<<path<<endl;

    return size;
}




