#include "widget.h"
#include <QDebug>
#include <QMap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{/*
    QList<int>list;
    list<<1<<2<<3<<4<<5<<6<<7<<8<<9<<10;

    QMutableListIterator<int>i(list);
    for(i.toFront();i.hasNext();)
        qDebug()<<i.next();

    for(i.toBack();i.hasPrevious();)
    {
        if(i.previous()%2==0)
            i.remove();
        else
        {
            i.setValue(i.peekNext()*10);
        }
    }
    for(i.toFront();i.hasNext();)
        qDebug()<<i.next();*/

//    QMap<QString,QString>map;
//    map.insert("beijing","111");
//    map.insert("shanghai","222");
//    map.insert("henan","333");
//    QMapIterator<QString,QString>q(map);
//    for(;q.hasNext();)
//        qDebug()<<q.key()<<""<<q.next().value();


//    QMutableMapIterator<QString,QString>ci(map);

//    if(ci.findNext("333"))
//        ci.setValue("999");

//    QMapIterator<QString,QString>p(map);
//    qDebug()<<"";
//    for(p.toFront();p.hasNext();)
//        qDebug()<<p.key()<<""<<p.next().value();

    QVariant v(709);
    qDebug()<<v.toInt();
    QVariant w("How Are You!");
    qDebug()<<w.toString();

    QMap<QString,QVariant>map;
    map["int"]=709;
    map["double"]=709.709;
    map["string"]="How Are You!";
    map["color"]=QColor(255,0,0);
    //调用相应的转换函数并输出
    qDebug()<<map["int"]<<map["int"].toInt();
    qDebug()<<map["double"]<<map["double"].toDouble();
    qDebug()<<map["string"]<<map["string"].toString();
    qDebug()<<map["color"]<<map["color"].value<QColor>();

    //创建一个字符串列表
    QStringList strList;
    strList<<"A"<<"B"<<"C"<<"D"<<"E"<<"F"<<"G"<<"H"<<"I"<<"J"<<"K"<<"L";

    QVariant slv(strList);
    if(slv.type() == QVariant::StringList)
    {

        QStringList stringList=slv.toStringList();
        for(int i=0;i<stringList.size();i++)
            qDebug()<<stringList.at(i);
    }


}

Widget::~Widget()
{

}
