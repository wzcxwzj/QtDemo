#include <QCoreApplication>
#include <QMap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMap<QString,QString>map;
    map.insert("beijing","111");
    map.insert("henan","222");
    map.insert("shanghai","333");

    QMapIterator<QString,QString>i(map);    //只读迭代器
    for(;i.hasNext();)
        qDebug()<<i.key()<<""<<i.next().value();

    QMutableMapIterator<QString,QString>ci(map);//读写迭代器
    if(ci.findNext("222"))
        ci.setValue("444");

    QMapIterator<QString,QString>mi(map);
    qDebug()<<"";
    for(;mi.hasNext();)
        qDebug()<<mi.key()<<""<<mi.next().value();

    return a.exec();
}
