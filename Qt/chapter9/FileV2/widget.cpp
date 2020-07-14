#include "widget.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QDate>
#include <QApplication>
#include <QDir>
#include <QVBoxLayout>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
     fileOperation();
     textStreamOpation();
     fileRun();
        fileWatcher();
}

Widget::~Widget()
{

}
//通过QFile读文件
void Widget::fileOperation()
{
    QFile file("F:/stu.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        char buffer[1024];
        qint64 numlen= file.readLine(buffer,sizeof(buffer));
        if(numlen != -1)
        {
            qDebug()<<buffer;
        }
    }
}


//通过QTextStream流写文件
void Widget::textStreamOpation()
{
    QFile data("F:/data.txt");
    if(data.open(QFile::WriteOnly |QFile::Truncate))
    {
        QTextStream out(&data);
        out<<QObject::tr("hello word qt ...: ")<<qSetFieldWidth(10)<<left<<90<<endl;
    }

}
//将二进制数据写到数据流
//void Widget::fileRun()
//{
//    QFile datafile("F:/dt.dat");
//    datafile.open(QIODevice::WriteOnly |QIODevice::Truncate);
//    QDataStream out(&datafile);
//    out<<QString(tr("周何俊"));
//    out<<QDate::
//    out<<qint64(22);
//    datafile.close();

//    datafile.setFileName("F:/dt.dat");
//    if(file.open)
//    {

//    }


//}

void Widget::fileRun()
{
    QFile file3("F:/binary.dat");
    file3.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QDataStream out(&file3);
    out<< QString(tr("周何俊"));
    out<< QDate::fromString("1992/09/25","yyyy/MM/dd");
    out<<(quint64)22;
    file3.close();

    file3.setFileName("F:/binary.dat");
    if(!file3.open(QIODevice::ReadOnly))
    {
        qDebug()<<"ERROR!";
    }
    QDataStream in(&file3);
    QString str;
    QDate birthDay;
    quint64 argu;
    in>>str>>birthDay>>argu;
    qDebug()<<str<<birthDay<<argu;
    file3.close();
}
void  Widget::fileWatcher()
{
    QStringList arg=qApp->arguments();
    QString path;
    if(arg.count()>1)
    {
        path=arg[1];
    }
    else
    {
        path=QDir::currentPath();
    }

    pathLabel=new QLabel;
    pathLabel->setText("监视的目录是: " +path);
    QVBoxLayout *qvb =new QVBoxLayout(this);
    qvb->addWidget(pathLabel);

    fileWatcher1.addPath(path);
    connect(&fileWatcher1,SIGNAL(directoryChanged(QString)),this,SLOT(slotShowWidget()));

}

void Widget::slotShowWidget()
{
    QMessageBox::information(this,"监视目录","当前目录已改变");
}
