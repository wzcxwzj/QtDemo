#include "widget.h"
#include <QApplication>
#include <QDir>
#include <QVBoxLayout>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QStringList strList=qApp->arguments();
    QString path;
    if(strList.count()>1)
    {
        path=strList[1];
    }
    else
    {
        path=QDir::currentPath();
    }

    lab1=new QLabel();
    lab1->setText(tr("监视的目录是:")+path);
    QVBoxLayout *qvb=new QVBoxLayout(this);
    qvb->addWidget(lab1);

    fsWatcher.addPath(path);

    connect(&fsWatcher,SIGNAL(directoryChanged(QString)),this,SLOT(changeDirectory(QString)));
}

Widget::~Widget()
{

}
void Widget::changeDirectory(QString path)
{
    QMessageBox::information(NULL,tr("监视目录"),path);
}
