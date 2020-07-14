#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    QList<QString>list;
//    {
//        QString str = "How are you!";
//        list<<str;
//    }
//    qDebug()<<list[1]<<"Qt";


//Java风格只读迭代器
//   QList<int>list;
//   list<<1<<2<<3<<4<<5;

//   QListIterator<int>i(list);
//   for(;i.hasNext();)
//        qDebug()<<i.next();

//Java风格读写迭代器
   QList<int>list;
   QMutableListIterator<int>i(list);
   for(int j=1;j<10;j++)
       i.insert(j);
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
   //previous   返回前一个列表项的内容，并将迭代点移动到前一个列表项之前
   //peekPrevious  返回前一个列表项，但不移动迭代点

   for(i.toFront();i.hasNext();)
       qDebug()<<i.next();

    return a.exec();
}
