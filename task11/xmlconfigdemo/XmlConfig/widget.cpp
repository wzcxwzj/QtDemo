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

        QString str=ui->textEdit->toPlainText();
        QStringList strList=  str.split("file");

        for(int i=0;i<strList.size();i++)
        {
            int first=strList[i].lastIndexOf("/");

            QString  title=strList[i].right(strList[i].length()-first-1);
            titleList<<title;
            qDebug()<< titleList;
        }

        //获取文件路径
        QString strPath=ui->textEdit->toPlainText();

        QStringList strPathPlict=strPath.split("file:///");

        QStringList path;
        for(int i=1;i<strPathPlict.size();i++)
       {
             path=strPathPlict[i].split("\n");  //("path","")
             QByteArray strp= getFileMd5(path[0]);
             md5List<<QString(strp.toHex().constData());
             path.clear();
        }
        for(int i=0;i<md5List.size();i++)
       {
            //md5.toHex().constData();
            qDebug()<<"File MD5"<<md5List[i];
       }
        versionInformation=ui->lineEdit_2->text();
        versionNum++;
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

    elementText<<doc.createTextNode(QString::number(versionNum));
    version.appendChild(elementText[0]);
    elementText<<doc.createTextNode(currentTime);
    updatetime.appendChild(elementText[1]);
    elementText<<doc.createTextNode(versionInformation);
    describe.appendChild(elementText[2]);
    root.appendChild(version);
    root.appendChild(updatetime);
    root.appendChild(describe);

    QList<QDomElement>md5;
    QList<QDomElement>name;
//    QList<QDomElement>url;
    QList<QDomText>elementTextName;
   // QList<QDomText>elementTextUrl;
    for(int i=0;i<md5List.size();i++)
   {
        md5<<doc.createElement("MD5");   //创建节点common
        md5[i].setAttribute("id", md5List[i]);           //MD5值
        name<<doc.createElement("name");  //MD5的子节点
     //   url<<doc.createElement("url");

        elementTextName<<doc.createTextNode(titleList[i+1]);  //name节点的值
        name[i].appendChild(elementTextName[i]);
       // elementTextUrl<<doc.createTextNode("http://192.168.118.1:3000/update/msc.dll");//url节点的值
       // url[i].appendChild(elementTextUrl[i]);


        md5[i].appendChild(name[i]);                          //name加入MD5
        //md5[i].appendChild(url[i]);                           //url加入MD5
        root.appendChild(md5[i]);

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
