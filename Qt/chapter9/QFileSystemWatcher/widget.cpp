#include "widget.h"
#include <QApplication>
#include <QDir>
#include <QVBoxLayout>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QStringList args=qApp->arguments();

    QString path;

    if(args.count()>1)
    {
        path=args[1];
    }
    else
    {
        path =QDir::currentPath();
    }
    pathLabel=new QLabel;
    pathLabel->setText(tr("监视的目录: ")+path);

    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(pathLabel);
    fsWatcher.addPath(path);    //设置监视目录
    connect(&fsWatcher,SIGNAL(directoryChanged(QString)),this,SLOT(dealWithWatcher(QString)));

}

Widget::~Widget()
{

}

void Widget::dealWithWatcher(QString)
{
    QMessageBox::information(this,"文件监视","你的目录已改变");
}
