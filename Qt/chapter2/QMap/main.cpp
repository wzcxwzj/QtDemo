#include <QCoreApplication>
#include <QDebug>
#include <QMap>
void JAVA()
{
    QMap<QString,QString> map;
    map.insert("beijing","111");
    map.insert("shanghai","222");
    map.insert("zhengzhou","333");
    QMapIterator<QString,QString> i(map);       //只读迭代器
    for(;i.hasNext();)
        qDebug()<<""<<i.key()<<""<<i.next().value();

    QMutableMapIterator<QString,QString>ci(map);               //读写迭代器
    if(ci.findNext("222"))
            ci.setValue("88888");

    qDebug()<<"";

    QMapIterator<QString,QString>k(map);
    for(;k.hasNext();)
        qDebug()<<""<<k.key()<<""<<k.next().value();

}
void STL()
{
    //STL风格迭代器
    QMap<QString,QString>map;
    map.insert("beijing","222");
    map.insert("henan","333");
    map.insert("shenzhen","444");
    QMap<QString,QString>::const_iterator i;
    for(i=map.begin();i!=map.end();++i)
        qDebug()<<" "<<i.key()<<""<<i.value();

    QMap<QString,QString>::iterator mi;
    mi=map.find("henan");
    if(mi!=map.end())
        mi.value()="99999";
    QMap<QString,QString>::const_iterator modi;
    for(modi=map.begin();modi!=map.end();++modi)
        qDebug()<<" "<<modi.key()<<""<<modi.value();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QMap的插入,遍历,修改
    STL();
    return a.exec();
}
