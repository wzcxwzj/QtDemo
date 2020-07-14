#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_sCurPath="F:/";
    createFileModel();
    createSplitter();
    createQListWidget();
    createQListVew();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::createFileModel()
{
    m_pFileModel=new QFileSystemModel();
    m_pFileModel->setReadOnly(false);
    m_pFileModel->setFilter(QDir::AllEntries|QDir::NoDot);


    m_pFileModel->sort(0,Qt::AscendingOrder);
}
void MainWindow::createSplitter()
{
    ui->splitter->setStretchFactor(0,20);
    ui->splitter->setStretchFactor(1,80);
    ui->splitter->setAutoFillBackground(true);
}
void MainWindow::createQListWidget()
{

    ui->listWidget->setLayoutDirection(Qt::LeftToRight);

    QString sDestop=m_sCurPath;
    QDir dir(sDestop);
    dir.setFilter(QDir::Dirs|QDir::NoDotAndDotDot);

    QStringList string;
    string<<"*";

    if(dir.exists())
    {
     QFileInfoList list=  dir.entryInfoList(string,QDir::AllEntries,QDir::DirsFirst);

     ui->listWidget->clear();
     for(unsigned int i=0;i<list.count();i++)
     {
         QFileInfo tmpFiles=list.at(i);
         if(tmpFiles.isDir())
         {
             QIcon icon("F:/1.png");
             QString strName=tmpFiles.fileName();
             m_pItem=new QListWidgetItem(icon,strName);
             m_pItem->setSizeHint(QSize(200,80));
             ui->listWidget->insertItem(i,m_pItem);
         }
         else if(tmpFiles.isFile())
         {

         }
     }

    }

    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(onItemClicked(QListWidgetItem*)));
}
void MainWindow::createQListVew()
{
    QString sPath=m_sCurPath;
    QDir dir(sPath);
    dir.setFilter(QDir::Dirs|QDir::NoDotAndDotDot);

    if(dir.exists())
    {
        ui->listView->setModel(m_pFileModel);
        ui->listView->setRootIndex(m_pFileModel->setRootPath(sPath));

    }
    ui->listView->setMinimumSize(QSize(0,0));
    ui->listView->setMaximumSize(QSize(1870,16777215));
    ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);//设置鼠标弹出弹出框
    ui->listView->setLayoutDirection(Qt::LeftToRight);


//    ui->listView->setParent(0);
//    ui->listView->hide();


    ui->listView->setViewMode(QListView::IconMode);
    ui->listView->setGridSize(QSize(120,120));
    ui->listView->setIconSize(QSize(60,60));
    ui->listView->setTextElideMode(Qt::ElideNone);

    ui->listView->setSelectionMode(QAbstractItemView::SingleSelection);//选择模式  单选/多选


    ui->listView->setWordWrap(true);//设置文字可以换行显示
    ui->listView->setMovement(QListView::Static);   //QListView::Static用户不能移动项目
    ui->listView->setResizeMode(QListView::Adjust); //此属性保存在视图调整大小时项目是否再次布局。

}
void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    //1. 取出文件信息或目录信息
    QFileInfo fi = m_pFileModel->fileInfo(index);

    //2. 判断是否是目录, 如果是目录，进入下一个目录
    if (fi.isDir())
    {
//        if (fi.fileName() == ".." && m_sCurPath == getDesktopPath()) return;
       // queue.enqueue(m_sCurPath);
//        stack.push(m_sCurPath);

        bool bDotDot = (fi.fileName() == "..");
        ui->listView->setRootIndex(bDotDot ? index.parent().parent() : index);
        m_sCurPath = m_pFileModel->filePath(bDotDot ? index.parent().parent() : index);

    }

    m_pFileModel->sort(0);
    m_pFileModel->sort(1);

    //3. 左边树 和 右边点击同步展开
    leftAndRightSync();
}

void MainWindow::onItemClicked(QListWidgetItem *item)
{
    QString str=item->text()+"/";
    QString stt=  m_sCurPath+str;
    qDebug()<<stt;


    QDir dir;
    dir.setPath(stt);
    dir.cd(stt);
    //图标模式
    ui->listView->setModel(m_pFileModel);
    ui->listView->setRootIndex(m_pFileModel->setRootPath(dir.absolutePath()));

}
void MainWindow::leftAndRightSync()
{
    ui->listWidget->setLayoutDirection(Qt::LeftToRight);

    QString sDestop=m_sCurPath;
    QDir dir(sDestop);
    dir.setFilter(QDir::Dirs|QDir::NoDotAndDotDot);

    QStringList string;
    string<<"*";

    if(dir.exists())
    {
     QFileInfoList list=  dir.entryInfoList(string,QDir::AllEntries,QDir::DirsFirst);

     ui->listWidget->clear();
     for(unsigned int i=0;i<list.count();i++)
     {
         QFileInfo tmpFiles=list.at(i);
         if(tmpFiles.isDir())
         {
             QIcon icon("F:/1.png");
             QString strName=tmpFiles.fileName();
             m_pItem=new QListWidgetItem(icon,strName);
             m_pItem->setSizeHint(QSize(200,80));
             ui->listWidget->insertItem(i,m_pItem);
         }
     }

}
}
