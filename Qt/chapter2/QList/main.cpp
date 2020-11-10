#include <QCoreApplication>
#include <QDebug>

void List()
{
        QList<QString>list;
        {
            QString str="This is hello Qt....";
            list<<str;

        }
        qDebug()<<list[0]<<"Hello word!!";
}

void listTravel()
{

    QList<int>list;
    list<<1<<2<<3<<4<<5;
    QListIterator<int>i(list);
    for(;i.hasNext();)
        qDebug()<<i.next();

    qDebug()<<list;
}
void listIterator()
{
    QList<int>list;
    QMutableListIterator<int>i(list);
    for(int j=0;j<10;j++)
        i.insert(j);

    for(i.toFront();i.hasNext();)
        qDebug()<<i.next();

    for(i.toBack();i.hasPrevious();)
    {
        if(i.previous()%2==0)
        {
            i.remove();
        }
        else
        {
            i.setValue(i.peekNext()*10);
        }
    }
    for(i.toFront();i.hasNext();)
        qDebug()<<i.next();
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //STL风格迭代器
    QList<int>list;
    for(int i=0;i<10;i++)
        list.insert(list.end(),i);
    QList<int>::iterator i;

    for(i=list.begin();i!=list.end();++i)
    {
        qDebug()<<(*i);
        *i=(*i)*10;
    }

    QList<int>::const_iterator ci;
    for(ci=list.begin();ci!=list.end();++ci)
    {
         qDebug()<<*ci;
    }
    // qDebug()<<list;
}


