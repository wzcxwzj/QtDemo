#include "dialog.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDateTime>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    fileName =new QLabel(tr("文件名:"));
    fileSize =new QLabel(tr("大小:"));
    fileCreateTime=new QLabel(tr("创建时间:"));
    fileChangeTime=new QLabel(tr("最后的修改时间:"));
    fileLastTime=new QLabel(tr("最后的访问时间:"));
    fileAttribute=new QLabel(tr("属性:"));
    line1=new QLineEdit();
    line2=new QLineEdit();
    line3=new QLineEdit();
    line4=new QLineEdit();
    line5=new QLineEdit();
    fileBtn=new QPushButton(tr("文件"));
    connect(fileBtn,SIGNAL(clicked(bool)),this,SLOT(slotFile()));
    fileInfoBtn=new QPushButton(tr("获得文件信息"));
    connect(fileInfoBtn,SIGNAL(clicked(bool)),this,SLOT(slotGetfileInfo()));

    QHBoxLayout *qhb=new QHBoxLayout();
    qhb->addWidget(line1);
    qhb->addWidget(fileBtn);

    QGridLayout *grid=new QGridLayout();
    grid->addWidget(fileName,0,0);
    grid->addLayout(qhb,0,1);

    grid->addWidget(fileSize,1,0);
    grid->addWidget(line2,1,1);
    grid->addWidget(fileCreateTime,2,0);
    grid->addWidget(line3,2,1);
    grid->addWidget(fileChangeTime,3,0);
    grid->addWidget(line4,3,1);
    grid->addWidget(fileLastTime,4,0);
    grid->addWidget(line5,4,1);


    dirCheck =new QCheckBox(tr("目录"));
    fileCheck=new QCheckBox(tr("文件"));
    symbolicLink=new QCheckBox(tr("符号链接"));
    hideCheck=new QCheckBox(tr("隐藏"));
    readCheck=new QCheckBox(tr("读"));
    writeCheck=new QCheckBox(tr("写"));
    perFormCheck=new QCheckBox(tr("执行"));

    QHBoxLayout *qhb1=new QHBoxLayout();
    qhb1->addWidget(dirCheck);
    qhb1->addWidget(fileCheck);
    qhb1->addWidget(symbolicLink);
    qhb1->addWidget(hideCheck);
    qhb1->addWidget(readCheck);
    qhb1->addWidget(writeCheck);
    qhb1->addWidget(perFormCheck);

    QVBoxLayout *qvb=new QVBoxLayout(this);
    qvb->addLayout(grid);
    qvb->addWidget(fileAttribute);
    qvb->addLayout(qhb1);
    qvb->addWidget(fileInfoBtn);

    //    fileInfoBtn
}

Dialog::~Dialog()
{

}
void Dialog::slotFile()
{
  QString strName=QFileDialog::getOpenFileName(this,"打开","/","files (*)");
  line1->setText(strName);
}
void Dialog::slotGetfileInfo()
{
    QString fileName=line1->text();
    QFileInfo fileInfo(fileName);
    qint64 size= fileInfo.size();    //大小
    QDateTime cread         =   fileInfo.created();
    QDateTime lastModifi    =   fileInfo.lastModified();             //QFileInfo对象, 最后修改时间
    QDateTime lastread      =   fileInfo.lastRead();                 //QFileInfo对象, 最后访问时间

    /*判断QFileInfo对象的文件类型属性*/
    bool isDir= fileInfo.isDir();
    bool isFile= fileInfo.isFile();
    bool isSymLink= fileInfo.isSymLink();  //判断QFileInfo对象的文件类型属性，此处为符号链接文件
    bool isHidden= fileInfo.isHidden();    //判断QFileInfo对象的隐藏属性
    bool isReadable= fileInfo.isReadable();  //判断QFileInfo对象的读属性
    bool isWriteable= fileInfo.isWritable();  //判断QFileInfo对象的写属性
    bool isExecutable= fileInfo.isExecutable(); //判断QFileInfo对象的可执行属性

    line2->setText(QString::number(size));
    line3->setText(cread.toString());
    line4->setText(lastModifi.toString());
    line5->setText(lastread.toString());

    dirCheck->setCheckState(isDir?Qt::Checked:Qt::Unchecked);
    fileCheck->setCheckState(isFile?Qt::Checked:Qt::Unchecked);
    symbolicLink->setCheckState(isSymLink?Qt::Checked:Qt::Unchecked);
    hideCheck->setCheckState(isHidden?Qt::Checked:Qt::Unchecked);
    readCheck->setCheckState(isReadable?Qt::Checked:Qt::Unchecked);
    writeCheck->setCheckState(isWriteable?Qt::Checked:Qt::Unchecked);
    perFormCheck->setCheckState(isExecutable?Qt::Checked:Qt::Unchecked);
}
