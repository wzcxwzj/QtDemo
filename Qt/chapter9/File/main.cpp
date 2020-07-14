#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QtDebug>

void textStream()
{
    QFile data("data.txt");
    if(data.open(QFile::WriteOnly|QFile::Truncate))
    {
        QTextStream out(&data);
        out<<QObject::tr("score:")<<qSetFieldWidth(10)<<left<<90<<endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QFile file("");
//    if(file.open(QIODevice::ReadOnly))
//    {
//        char buffer[2048];
//        qint64 lineLen =file.readLine(buffer,sizeof(buffer));
//        if(lineLen!=-1)
//        {
//            qDebug()<<buffer;
//        }
//    }
    textStream();
    return a.exec();
}
