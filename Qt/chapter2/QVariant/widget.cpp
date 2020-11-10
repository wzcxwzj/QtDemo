#include "widget.h"
#include <QDebug>
#include <QMap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVariant v(709);
    qDebug()<<v.toInt();

    QVariant str("How Are You!!");
    qDebug()<<str.toString();
    QMap<QString,QVariant>map;
    map["int"]=709;
    map["double"]=709.709;
    map["QString"]="How are you!";
    map["color"]=QColor(255,0,0);

    qDebug()<<map["int"]<<map["int"].toInt();
    qDebug()<<map["double"]<<map["double"].toDouble();
    qDebug()<<map["QString"]<<map["QString"].toString();
    qDebug()<<map["color"]<<map["color"].value<QColor>();

    QStringList list;
    list<<"A"<<"B"<<"C"<<"D"<<"E"<<"F";
    QVariant slv(list);
    if(slv.type() == QVariant::StringList)
    {
        QStringList str=slv.toStringList();
        for(int i=0;i<str.size();i++)
            qDebug()<<str.at(i);
    }
}

Widget::~Widget()
{

}
