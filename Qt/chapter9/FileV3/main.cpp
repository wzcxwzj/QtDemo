#include <QCoreApplication>
#include <QObject>
#include <QFile>
#include <QDate>
#include <QDataStream>
#include <QDebug>
#include <QString>


void File()
{
    //QFile读写文件
    //    QFile file("F:/textFile1.txt");
    //    if(file.open(QIODevice::ReadOnly))
    //    {
    //        char buffer[2048];
    //        qint64 len=file.readLine(buffer,sizeof(buffer));

    //        if(len!=-1)
    //        {
    //            qDebug()<<buffer;
    //        }
    //    }
}

void TextStream()
{
    //QTextStream流 写文本
    //    QFile file("F:/data.txt");
    //    if(file.open(QFile::WriteOnly|QFile::Truncate))
    //    {
    //        QTextStream out(&file);
    //        out<<QObject::tr("score:")<<qSetFieldWidth(10)<<left<<90<<endl;
    //    }

}

void fileRun()
{
    //将2进制数据写到数据流
    QFile file("F:/binary1.dat");
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);
    QDataStream out(&file);
   // out<<QString(tr("周何俊:"));
    QString sty="周何俊:";
    out<<sty;
    out<<QDate::fromString("1996/09/25","yyyy/MM/dd");
    out<<(qint32)23;
    file.close();


    //从文件中读取数据
    file.setFileName("F:/binary1.dat");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"ERROR!!!";
    }
    QDataStream in(&file);
    QString str;
    QDate birthDay;
    qint32 num;
    in>>str>>birthDay>>num;
    qDebug()<<str<<birthDay<<num;
    file.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    fileRun();




    return a.exec();
}
