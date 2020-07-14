#include "widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVariant v(709);
    qDebug()<<v.toInt();
    QVariant str("hollow");
    qDebug()<<str.toString();

    QMap<QString,QVariant>map;
    map["int"]=709;
    map["double"]=709.709;
    map["QString"]="Hello Qt";
    map["QColor"]=QColor(255,0,0);
    qDebug()<<map["int"]<<map["int"].toInt();
    qDebug()<<map["double"]<<map["double"].toDouble();
    qDebug()<<map["QString"]<<map["QString"].toString();
    qDebug()<<map["QColor"]<<map["QColor"].value<QColor>();

    QStringList list;
    list<<"A"<<"B"<<"C"<<"D"<<"E"<<"F"<<"G"<<"H"<<"I"<<"J"<<"K";
    QVariant slv(list);
    if(slv.type()==QVariant::StringList)
    {

        QStringList strList=slv.toStringList();
        for(int i=0;i<strList.size();i++)
            qDebug()<<strList.at(i);
    }

}

Widget::~Widget()
{

}
