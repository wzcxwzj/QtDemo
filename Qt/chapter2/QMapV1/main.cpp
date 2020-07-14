#include <QCoreApplication>
#include <QMap>
#include <QDebug>


void JavaMap()
{
    QMap<QString,QString>map;
    map.insert("beijing","111");
    map.insert("guangzhou","222");
    map.insert("shanghai","333");

    QMapIterator<QString,QString>i(map);    //只读迭代器
    for(;i.hasNext();)
        qDebug()<<""<<i.key()<<""<<i.next().value();


    QMutableMapIterator<QString,QString>ci(map);     //读写迭代器
    if(ci.findNext("222"))
        ci.setValue("9999");

    for(ci.toFront();ci.hasNext();)
        qDebug()<<""<<ci.key()<<""<<ci.next().value();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString,QString>map;
    map.insert("beijing","111");
    map.insert("guangzhou","222");
    map.insert("shanghai","333");

    //STL风格迭代器
    QMap<QString,QString>::Iterator i;
    for(i=map.begin();i!=map.end();++i)
        qDebug()<<""<<i.key()<<""<<i.value();


    i=map.find("shanghai");
    if(i!=map.end())
        i.value()="7777";
    QMap<QString,QString>::const_iterator mi;
    for(mi=map.begin();mi!=map.end();++mi)
        qDebug()<<""<<mi.key()<<""<<mi.value();
    return a.exec();
}
