#include <QCoreApplication>
#include <QDebug>

void List()
{
    QList<QString>list;
    {
        QString str="This Qt!";
        list<<str;
    }

    qDebug()<<list[0]<<"study Qt jiayou!";
}

void JAVAListIterator()
{
    QList<int>list;
    list<<1<<2<<3<<4<<5<<6;

    //Java风格的只读迭代器
    QListIterator<int>i(list);
    for(;i.hasNext();)
        qDebug()<<i.next();
}
void JAVAMutableListIterator()
{
    QList<int>list;
    QMutableListIterator<int>i(list); //读写迭代器
    for(int j=0;j<10;j++)
        i.insert(j);

//    QListIterator<int>p(list);        //只读迭代器
//    for(;p.hasNext();)
//        qDebug()<<p.next();

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

    QListIterator<int>q(list);        //只读迭代器
    for(;q.hasNext();)
        qDebug()<<q.next();

}

void STLiterator()
{
    QList<int>list;
    for(int i=0;i<10;i++)
        list.insert(list.end(),i);
    //STL风格
    QList<int>::iterator i;
    for(i=list.begin();i!=list.end();++i)
    {        qDebug()<<*i;
             *i=(*i)*10;
    }

    QList<int>::const_iterator ci;
    for(ci=list.begin();ci!=list.end();++ci)
    {        qDebug()<<(*ci);

    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    STLiterator();
    return a.exec();
}
