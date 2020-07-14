#include "mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    fileFun();
}

MainWindow::~MainWindow()
{

}

void MainWindow::fileFun()
{
   /*将二进制数据写到数据流*/
    QFile file("binary.dat");
    file.open(QIODevice::WriteOnly |QIODevice::Truncate);
    QDataStream out(&file);
    out<<QString(tr("周何骏: "));//将数据序列化
    out<<QDate::fromString("1996/09/25","yyyy/MM/dd");//将字符串序列化
    out<<(qint32)21;            //整数序列化
    file.close();

    /*从文件中读取数据*/
    file.setFileName("binary.dat");
    if(file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"error!";
        return ;
    }
    QDataStream in(&file);    //从文件中读取数据
    QString name;
    QDate birthday;
    qint32 age;
    qDebug()>>name>>birthday>>age;
    file.close();
}
