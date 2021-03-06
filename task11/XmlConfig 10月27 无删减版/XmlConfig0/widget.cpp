#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QString>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <QDomDocument>
#include <QtXml>
#include <QCryptographicHash>
#include <QFile>
#include <QDir>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->textEdit,SIGNAL(textChanged()),this,SLOT(getText()));
    QDateTime curDateTime=QDateTime::currentDateTime();
    currentTime=curDateTime.toString("yyyy-MM-dd");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::getText()
{

        //1.判断当前拖进去的,是否是目录
        /*
                是:  这字符串就切割到上一次目录并保存,
                否:  直接保存文件名就行

                QDir dir();

        */



   // 1.拖进来的是目录
   // 2.截取到当前目录的上一级目录

    QString str=ui->textEdit->toPlainText();
    QStringList strList=  str.split("file:///");

    QStringList pathList;
    for(int i=0;i<strList.size();i++)
    {
//        infoList<<(strList[i]);
        //先干掉"\n"
       QStringList pp=  strList[i].split("\n");
       pathList<<pp[0];
    }
    for(int i=0;i<pathList.size();i++)
    {
        QFileInfo fileInfo(pathList[i]);
        if(fileInfo.isDir())        //目录
        {
            qDebug()<<"Dir  "<<"i="<<i<<pathList[i];
            FindFile(pathList[i]);    //获得目录下全部的文件  并保存到dirPathParse.

        }
        if(fileInfo.isFile())                    //文件
        {
            //fileList                            //这里可能文件也应该要存一个列表
            fileList<<pathList[i];
            qDebug()<<"file"<<"i="<<i<<pathList[i];
        }
         //qDebug()<<pathList[i];
    }
    //文件名解析  因为要对文件名进行md5加密

    for(int i=0;i<dirPathParse.size();i++)  //目录的MD5
    {
        QByteArray strp= getFileMd5(dirPathParse[i]);
         md5List<<QString(strp.toHex().constData());
    }
    for(int i=0;i<md5List.size();i++)
    {
      //  qDebug()<<"Dir File MD5"<<md5List[i];
    }

    for(int i=0;i<fileList.size();i++)  //文件的MD5
    {
        QByteArray strp= getFileMd5(fileList[i]);
        md5FileList<<QString(strp.toHex().constData());
    }
    for(int i=0;i<md5FileList.size();i++)
    {

       // qDebug()<<" File MD5"<<md5FileList[i];
    }

    //写xml
    /*
     *  目录名+文件名+md5
        文件名+md5
    */

    //xml目录名

    for(int i=0;i<dirPathParse.size();i++)
    {
        QString AA=dirPathParse.at(i);

        QStringList BB=AA.split("C:/Users/Administrator/Desktop");  //存放相对路径的地方
        pDir<<BB[1];
       // qDebug()<<P[i];
        qDebug()<<"*****************************"<<pDir[i];
    }

    //xml文件名
    QStringList pFile;
    for(int i=0;i<fileList.size();i++)          //***取最后一个文件名
    {
        //int first=fileList[i].lastIndexOf("/");

        QString  title=fileList.at(i);//.right(strList[i].length()-first-1);

        pFile=title.split("C:/Users/Administrator/Desktop/");;//存放相对路径的地方
        titleList<<pFile[1];

       // qDebug()<<"&&&&&&&&&"<<titleList[i];
    }




//    QFileInfo fileInfo(pathList[0]);
//    if(fileInfo.isDir())        //目录
//    {
//        qDebug()<<"Dir";
//        qDebug()<<"Dir  "<<strList[i];
//    }
//    if(fileInfo.isFile())                    //文件
//    {

//        qDebug()<<"file";
//    }
//    qDebug()<<pathList;



    /***************************************************************************/
//        QString str=ui->textEdit->toPlainText();
//        QStringList strList=  str.split("file");

//        for(int i=0;i<strList.size();i++)          //***取最后一个文件名
//        {
//            int first=strList[i].lastIndexOf("/");

//            QString  title=strList[i].right(strList[i].length()-first-1);
//            titleList<<title;
//            qDebug()<< titleList;
//        }


        //获取文件路径
//        QString strPath=ui->textEdit->toPlainText();  //***去除"/n"

//        QStringList strPathPlict=strPath.split("file:///");

//        QStringList path;
//        for(int i=1;i<strPathPlict.size();i++)
//       {
//             path=strPathPlict[i].split("\n");  //("path","")
//             QByteArray strp= getFileMd5(path[0]);
//             md5List<<QString(strp.toHex().constData());
//             path.clear();
//        }
//        for(int i=0;i<md5List.size();i++)
//       {

//            qDebug()<<"File MD5"<<md5List[i];
//       }

        writeXml();

}
void Widget::writeXml()
{
    QByteArray array;
    QDomDocument doc;
    QDomProcessingInstruction instruction;
    QList<QDomText> elementText;

    instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");

    doc.appendChild(instruction);                       //doc开头加入instruction

    QDomElement root = doc.createElement("root");       //创建root节点
    QDomElement version = doc.createElement("VERSION");   //创建节点common
    QDomElement updatetime = doc.createElement("UPDATETIME");   //创建节点common
    QDomElement describe = doc.createElement("DESCRIBE");   //创建节点common

    elementText<<doc.createTextNode(ui->lineEdit->text());
    version.appendChild(elementText[0]);
    elementText<<doc.createTextNode(currentTime);
    updatetime.appendChild(elementText[1]);
    elementText<<doc.createTextNode("添加");
    describe.appendChild(elementText[2]);
    root.appendChild(version);
    root.appendChild(updatetime);
    root.appendChild(describe);

    QList<QDomElement>md5;
    QList<QDomElement>name;
//    QList<QDomElement>url;
    QList<QDomText>elementTextName;
   // QList<QDomText>elementTextUrl;
    int i;
    for(i=0;i<md5List.size();i++)   //目录xml
   {
        md5<<doc.createElement("MD5");   //创建节点common
        md5[i].setAttribute("id", md5List[i]);           //MD5值
        name<<doc.createElement("name");  //MD5的子节点
//        url<<doc.createElement("url");

        elementTextName<<doc.createTextNode(pDir[i]);  //name节点的值
        name[i].appendChild(elementTextName[i]);
       // elementTextUrl<<doc.createTextNode("http://192.168.118.1:3000/update/msc.dll");//url节点的值
       // url[i].appendChild(elementTextUrl[i]);


        md5[i].appendChild(name[i]);                          //name加入MD5
        /*md5[i].appendChild(url[i]);*/                           //url加入MD5
        root.appendChild(md5[i]);

   }

    for(int j=0;j<md5FileList.size();j++)   //文件xml
   {
        md5<<doc.createElement("MD5");   //创建节点common
        md5[i+j].setAttribute("id", md5FileList[j]);           //MD5值
        name<<doc.createElement("name");  //MD5的子节点
//        url<<doc.createElement("url");

        elementTextName<<doc.createTextNode(titleList[j]);  //name节点的值
        name[i+j].appendChild(elementTextName[i+j]);


        md5[i+j].appendChild(name[i+j]);                          //name加入MD5
        /*md5[i+j].appendChild(url[i+j]);*/                           //url加入MD5
        root.appendChild(md5[i+j]);

   }

    doc.appendChild(root);

    array = doc.toByteArray();

    printf("%s", array.data());


   //将xml保存到文件中
   QFile file("./Description.xml");

   file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
   QTextStream out(&file);
   out.setCodec("UTF-8");
   doc.save(out, 4, QDomNode::EncodingFromTextStream);

   file.close();
}


QByteArray Widget::getFileMd5(QString filePath)
{
    QFile localFile(filePath);

    if (!localFile.open(QFile::ReadOnly))
    {
        qDebug() << "file open error.";
        return 0;
    }

    QCryptographicHash ch(QCryptographicHash::Md5);

    quint64 totalBytes = 0;
    quint64 bytesWritten = 0;
    quint64 bytesToWrite = 0;
    quint64 loadSize = 1024 * 4;
    QByteArray buf;

    totalBytes = localFile.size();
    bytesToWrite = totalBytes;

    while (1)
    {
        if(bytesToWrite > 0)
        {
            buf = localFile.read(qMin(bytesToWrite, loadSize));
            ch.addData(buf);
            bytesWritten += buf.length();
            bytesToWrite -= buf.length();
            buf.resize(0);
        }
        else
        {
            break;
        }

        if(bytesWritten == totalBytes)
        {
            break;
        }
    }

    localFile.close();
    QByteArray md5 = ch.result();

    return md5;
}




bool Widget::FindFile(const QString &path)
{
    QDir dir(path);
    if (!dir.exists())
    {
        return false;
    }
    dir.setFilter(QDir::Dirs | QDir::Files);
    dir.setSorting(QDir::DirsFirst);//文件夹排在前面
    QFileInfoList list = dir.entryInfoList();
    int i = 0;

    bool bIsDir;
    do
    {
        QFileInfo fileInfo = list.at(i);
        QString strFilename = fileInfo.fileName();
        uint gid = fileInfo.groupId();
        QString strDateTime = fileInfo.lastModified().toString("yyyy-MM-dd hh:mm:ss");
        QString strPath = fileInfo.absoluteFilePath();
        if (fileInfo.fileName() == "." | fileInfo.fileName() == "..")
        {
            ++i;
            continue;
        }
        bIsDir = fileInfo.isDir();
        if (bIsDir)//如果是文件夹
        {
            ++m_nDirCount;//目录个数
            FindFile(fileInfo.filePath());
        }
        else
        {
            ++m_nFilesCount;//文件个数
                            //fileInfo.fileName() fileInfo.baseName() fileInfo.path() fileInfo.completeSuffix() fileInfo.suffix()
           // qDebug() << "groupId=" << fileInfo.groupId() << "lastModified=" << fileInfo.lastModified().toString("yyyy-MM-dd hh:mm:ss") << "absoluteFilePath=" << fileInfo.absoluteFilePath();
                dirPathParse<<fileInfo.absoluteFilePath();
        }
        ++i;
    } while (i < list.size());

    return true;

}




































//   QDomElement root = doc.createElement("root");       //创建root节点
//   QDomElement common = doc.createElement("common");   //创建节点common
//   QDomElement meters = doc.createElement("meters");   //创建节点meters
//   QDomElement meter = doc.createElement("meter");
//   QDomElement function = doc.createElement("function");

//   meters.setAttribute("total", "0");                  //设置属性名字和值
//   meter.setAttribute("id", "0001");
//   meter.setAttribute("FileName", titleList[1]);

//   function.setAttribute("id", "01");                //
//   function.setAttribute("error", "");

//   meters.appendChild(meter);
//   common.appendChild(meters);                         //将meters节点添加到common节点中
//   doc.appendChild(root);                              //将root节点添加到doc
//   root.appendChild(common);                           //将common节点添加到root节点中
//   meter.appendChild(function);

//   meters.setAttribute("total", "12");
