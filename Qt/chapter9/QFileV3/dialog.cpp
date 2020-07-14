#include "dialog.h"
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    //将2进制数据写入文件
    QFile file("bina.dat");
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);
    QDataStream out(&file);
    out<<QString(tr("周无极"));
    out<<QDate::fromString("1996/09/23","yyyy/MM/dd");
    out<<(qint32)23;
    file.close();

    file.setFileName("bina.dat");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"ERROR!!!";
    }

    QDataStream in(&file);
    QString str;
    QDate data;
    quint32 a;
    in>>str>>data>>a;
    qDebug()<<str<<data<<a;

    file.close();
}

Dialog::~Dialog()
{

}
