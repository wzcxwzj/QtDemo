#include "fileview.h"

FileView::FileView(QDialog *parent)
    : QDialog(parent)
{
    setWindowTitle("File View");
    fileLineEdit=new QLineEdit(tr("/"));
    fileListWidget=new QListWidget;
    mainlayout=new QVBoxLayout(this);
    mainlayout->addWidget(fileLineEdit);
    mainlayout->addWidget(fileListWidget);

    connect(fileLineEdit,SIGNAL(returnPressed()),this,SLOT(slotShow(QDir)));
    connect(fileListWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(slotDirShow(QListWidgetItem*)));
    QString root="/";
    QDir rootDir(root);
    QStringList string;
    string <<"*";
    QFileInfoList list=rootDir.entryInfoList(string);
    showFileInfoList(list);
}

FileView::~FileView()
{

}
void FileView::slotShow(QDir dir)       //显示目录dir下所有的文件
{
    QStringList string;
    string<<"*";
    QFileInfoList list=dir.entryInfoList(string,QDir::AllEntries,QDir::DirsFirst);
    showFileInfoList(list);
}
void FileView::showFileInfoList(QFileInfoList list)
{
    fileListWidget->clear();    //清空列表控件
    for(unsigned int i=0;i<list.count();i++)
    {
        QFileInfo tmpFileInfo=list.at(i);
        if(tmpFileInfo.isDir())
        {
            QIcon icon("");
            QString fileName=tmpFileInfo.fileName();
            QListWidgetItem *tmp=new QListWidgetItem(icon,fileName);
            fileListWidget->addItem(tmp);
        }
        else if(tmpFileInfo.isFile())
        {
            QIcon icon("");
            QString fileName=tmpFileInfo.fileName();
            QListWidgetItem *tmp=new QListWidgetItem(icon,fileName);
            fileListWidget->addItem(tmp);
        }
    }
}

//根据用户的选择显示下一级目录的所有文件
void FileView::slotDirShow(QListWidgetItem *item)
{
    QString str=item->text();   //将下一级的目录名保存在str中
    QDir dir;
    dir.setPath(fileLineEdit->text());
    dir.cd(str);
    fileLineEdit->setText(dir.absolutePath());
    slotShow(dir);              //显示当前目录下的所有文件
}

