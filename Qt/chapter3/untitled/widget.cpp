#include "widget.h"
#include "ui_widget.h"
#include <QCheckBox>
#include <QDebug>


#define MYDELETE(p)  {if (p) { delete   p; p = NULL;}}
#define MYDELETES(p) {if (p) { delete[] p; p = NULL;}}


Widget::Widget(QWidget *parent) :
    BaseWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initTitleBar();
    initThread();
    createSplitter();
    createQTreeWidget();
    createFileModel();
    createQTableVew();
    createQListVew();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initTitleBar()
{
    m_titleBar->setTitleContent("文件资源管理器");
    m_titleBar->setButtonType(MIN_MAX_BUTTON);
    m_titleBar->setTitleWidth(this->width());
    m_titleBar->setTitleHeight(56);

    connect(m_titleBar->advanceBtn,SIGNAL(clicked(bool)),this,SLOT(onDebug()));
    connect(m_titleBar->backBtn,SIGNAL(clicked(bool)),this,SLOT(onBackBtn()));
}
void Widget::initThread()
{
    m_pItem = NULL;
    m_pThread = NULL;
   // m_pOldItem = NULL;
    m_pFileModel = NULL;
    m_iActionState = 0;
    m_pProgressBar = NULL;

    MYDELETE(m_pThread);
    m_pThread = new FileThread(this);
    connect(m_pThread, SIGNAL(copyAndCutFinished()), this, SLOT(onCopyAndCutFinished()));
    connect(m_pThread, SIGNAL(chooseCoverFileOrDir(bool, QString)), this, SLOT(onChooseCoverFileOrDir(bool, QString)));
    connect(this, SIGNAL(chooseCoverFinished(int)), m_pThread, SLOT(onChooseCoverFinished(int)));

}


void Widget::createFileModel()
{
    m_pFileModel=new MyqFileModel();
    m_pFileModel->setReadOnly(false);
    m_pFileModel->setFilter(QDir::AllEntries|QDir::NoDot);


    m_pFileModel->sort(0,Qt::AscendingOrder);
}
void Widget::createSplitter()
{
    ui->splitter->setStretchFactor(0,20);
    ui->splitter->setStretchFactor(1,80);
    ui->splitter->setAutoFillBackground(true);
}

void Widget::createQTreeWidget()
{
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderLabel("目录结构");
    ui->treeWidget->setLayoutDirection(Qt::LeftToRight);

    QString sDestop=getDesktopPath();
    QDir dir(sDestop);
    dir.setFilter(QDir::Dirs|QDir::NoDotAndDotDot);

    if(dir.exists())
    {
       m_pItem=new QTreeWidgetItem(ui->treeWidget,QStringList(sDestop));
       m_pItem->setIcon(0,QIcon("F:/2.png"));
       m_pItem->setData(1,0,sDestop);
       m_items<<m_pItem;
       loadFile(sDestop,m_pItem);

       showChildRenCombox(m_pItem);

      //默认展开根目录
       if (m_pItem) m_pItem->setExpanded(true);
    }
    connect(ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(onItemClicked(QTreeWidgetItem*,int)));

}

void Widget::createQTableVew()
{
    //1. 默认显示桌面下的所有目录和文件
    QString sDesktop = getDesktopPath();
    QDir dir(sDesktop);
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot); //不显示隐藏文件夹 和 文件

    if (dir.exists())
    {
        //显示S桌面所有目录 和 文件 到table
        ui->tableView->setModel(m_pFileModel);
        ui->tableView->setRootIndex(m_pFileModel->setRootPath(sDesktop));

        //展开所有节点
        if (m_pItem) m_pItem->setExpanded(true);

        //在界面显示桌面根目录
         m_sCurPath = sDesktop;
//        ui->lePath->setText(sDesktop);
    }

    //2. 设置table的属性
    ui->tableView->setShowGrid(false);                                    //设置QTableView的透明化
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);   //整行选中
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);    //不可编辑
    ui->tableView->verticalHeader()->hide();                              //隐藏行头
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);

    //3. 设置列标题的排序功能
    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setEnabled(true);

    //4. 自动适应内容
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    //5. 设置列表项的宽度
    ui->tableView->setColumnWidth(0,200);
    ui->tableView->setColumnWidth(1,100);
    ui->tableView->setColumnWidth(2,100);

    ui->tableView->setParent(0);
    ui->tableView->hide();

    //6. 连接点击信号槽
    //connect(header, SIGNAL(sectionClicked(int)), this, SLOT(onSectionClicked(int)));
}

void Widget::createQListVew()
{
    QString sPath=getDesktopPath();
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
void Widget::showChildRenCombox(QTreeWidgetItem *rItem)
{
    int count= rItem->childCount();//childCount表示有多少个子项
    if(count==0) return;

    for(int i=0;i<count;i++)//child返回每一项
    {
        loadFile(rItem->child(i)->data(1,0).toString(),rItem->child(i));
        //qDebug()<<rItem->child(i)->data(1,0).toString();
    }
}
void Widget::loadFile(QString sPath,QTreeWidgetItem *item)
{

    QDir dir(sPath);
    if(!dir.exists())return;

    dir.setFilter(QDir::Dirs|QDir::NoDotAndDotDot);
    QFileInfoList list =   dir.entryInfoList();


    int nCount=list.size();
    for(int i=0;i<nCount;i++)
    {
        QFileInfo info=list.at(i);
        if(!info.isDir()) continue;

        QTreeWidgetItem *pFileItem=new QTreeWidgetItem(QStringList(info.fileName()),0);
        pFileItem->setData(1,0,info.filePath());
        item->addChild(pFileItem);
    }
}
void Widget::leftAndRightSync()
{
    ui->treeWidget->collapseAll();
    m_allPathList.clear();
    getAllLastpath(m_sCurPath);

    int nSize=m_allPathList.size();
    if(nSize == 0)
    {
        return;
    }
    QTreeWidgetItem *rootItem=NULL;
    if(m_pItem && (m_allPathList.at(nSize-1)==m_pItem->data(1,0).toString())) rootItem=m_pItem;

    qDebug()<<m_allPathList.at(nSize-1);
    qDebug()<<m_pItem->data(1,0).toString();
    if(rootItem) ui->treeWidget->expandItem(rootItem);
    for(int i=nSize-2;i>=0;i--)
    {
        rootItem = getChildItemByPath(rootItem, m_allPathList.at(i));
        if (rootItem) ui->treeWidget->expandItem(rootItem);
        qDebug()<<"Sdsad";
    }
}
QTreeWidgetItem *Widget::getChildItemByPath(QTreeWidgetItem *parent,QString sPath)
{
    QTreeWidgetItem *childItem=NULL;
    int nCount=parent->childCount();
    for(int i=0;i<nCount;i++)
    {
        if(parent->child(i)->data(1,0).toString()!=sPath)continue;
        childItem=parent->child(i);
        break;
    }
    return childItem;
}
//通过当前路径获取所有的上一级路径
void Widget::getAllLastpath(QString sCurPath)
{
    if(sCurPath=="")return;
    if(sCurPath==getDesktopPath())
    {
        m_allPathList<<sCurPath;
        return;
    }
    m_allPathList<<sCurPath;
    QString str=sCurPath.mid(0,sCurPath.lastIndexOf("/"));
    getAllLastpath(str);
}
QString Widget::getDesktopPath()        //获取系统桌面路径
{
    return QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
}

//iOperation=0 : copy   iOperation=1 : cut
void Widget::prepareCopyAndCutPath()
{
    //1. 清空上一次复制 或 拷贝的文件路径
    m_sSourcePath.clear();

    //2. 判断当前是在列表模式 还是 图标模式
    QModelIndexList list = m_bViewState ? ui->listView->selectionModel()->selectedIndexes() : ui->tableView->selectionModel()->selectedIndexes();
    int nCount = list.size();
qDebug()<<m_bViewState;
    int iStep = 1;
    if (m_bViewState)
    {

    }
    else
    {
        iStep = 4;
    }

    //把用户选择的所有文件夹 和 文件路径保存起来，用于粘贴
    for (int i = 0; i < nCount; i += iStep)
    {
        m_sSourcePath << m_pFileModel->fileInfo(list.at(i)).filePath();
        qDebug()<<m_sSourcePath;
    }

    m_iActionState = -1;  //只要不等于0就可以
}

//通过路径获取路径下的文件或者文件夹名称
QString Widget::getPathName(QString sPath)
{
    if (!sPath.contains("/")) return sPath;
    return sPath.right(sPath.size() - sPath.lastIndexOf("/") - 1);
}

//释放m_listTreeWidgetItem容器装载的item内存
void Widget::freeListTreeWidgetItem()
{
    int iCount = m_items.count();
    for (int i = iCount - 1; i >= 0; i--)
    {
        QTreeWidgetItem* pItem = m_items[i];
        MYDELETE(pItem);
    }
    m_items.clear();
}

//当发生更新操作时对QTreeWidget的手动改变
void Widget::updateTreeWidgetData()
{
    //0.先清空原来的目录结构
    freeListTreeWidgetItem();
    ui->treeWidget->clear();

    //1.添加SDCard目录
    QDir dir(getDesktopPath());
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    if (dir.exists())
    {
        m_pItem = new QTreeWidgetItem(ui->treeWidget, QStringList(QString(getDesktopPath())));
        m_items << m_pItem;
        m_pItem->setIcon(0,QIcon(":/icon/icon_64_open.png"));
        m_pItem->setData(1, 0, QString(getDesktopPath()));

        loadFile(getDesktopPath(), m_pItem);
        showChildRenCombox(m_pItem);
    }

    m_allPathList.clear();
    getAllLastpath(m_sCurPath);

    int nSize = m_allPathList.count();
    if (nSize >= 3)
    {
        QTreeWidgetItem* item = NULL;
        for (int j = 0; j < m_items.count(); j++)
        {
            if (m_items.at(j)->data(1, 0).toString() != m_allPathList.at(nSize - 3)) continue;

            item = m_items.at(j);
            break;
        }

        if (item) showChildRenCombox(item);
        for (int i = nSize - 4 ;i >= 0; i--)
        {
            if (!item) break;
            item = getChildItemByPath(item, m_allPathList.at(i));
            showChildRenCombox(item);
        }
    }
   // m_pOldItem = NULL;        //确保槽函数中的的值同步

    leftAndRightSync();
}

void Widget::on_tableView_doubleClicked(const QModelIndex &index)
{
    //1. 取出文件信息或目录信息
    QFileInfo fi = m_pFileModel->fileInfo(index);
    qDebug()<<"鼠标在列表模式窗口双击:"<<m_sCurPath;
    //2. 判断是否是目录, 如果是目录，进入下一个目录
    if (fi.isDir())
    {
        if (fi.fileName() == ".." && m_sCurPath == getDesktopPath()) return;

        QModelIndex mIndex = m_pFileModel->index(fi.filePath());
        ui->tableView->setRootIndex(mIndex);
        m_sCurPath = m_pFileModel->filePath(mIndex);
    }

//    //3. 左边树 和 右边点击同步展开
    leftAndRightSync();

//    //4. 如果双击的是 文本文件 或者 图片文件， 则打开浏览

}
void Widget::on_listView_doubleClicked(const QModelIndex &index)
{
    //1. 取出文件信息或目录信息
    QFileInfo fi = m_pFileModel->fileInfo(index);

    //2. 判断是否是目录, 如果是目录，进入下一个目录
    if (fi.isDir())
    {
        if (fi.fileName() == ".." && m_sCurPath == getDesktopPath()) return;
       // queue.enqueue(m_sCurPath);
        stack.push(m_sCurPath);

        bool bDotDot = (fi.fileName() == "..");
        ui->listView->setRootIndex(bDotDot ? index.parent().parent() : index);
        m_sCurPath = m_pFileModel->filePath(bDotDot ? index.parent().parent() : index);

    }

    m_pFileModel->sort(0);
    m_pFileModel->sort(1);

    //3. 左边树 和 右边点击同步展开
    leftAndRightSync();
}
//bFile  true : file   false : dir
void Widget::createDirOrFile(bool bFile)
{
    QString sPathDes = m_sCurPath + "/" + (bFile ? tr("新建文本文档0") : tr("新建文件夹0"));

    while (dirIsExistsCurrentPath(sPathDes, m_sCurPath))
    {
        int iNum = -1;
        QString sFileName = sPathDes.mid(sPathDes.lastIndexOf("/") + 1);

        int iLength = QString((bFile ? tr("无标题文档") : tr("NewFolder"))).length();

        if (bFile ? (sFileName.left(iLength) == tr("无标题文档")) : (sFileName.left(iLength) == tr("NewFolder")))
        {
            QString sNum = sFileName.mid(iLength);
            bool bNum = stringIsNumber(sNum);
            iNum = bNum ? sNum.toInt() : -1;
        }

        sPathDes = (iNum == -1) ? (m_sCurPath + "/" + (bFile ? tr("无标题文档%1").arg(1) : tr("NewFolder%1").arg(1)))
                                : (m_sCurPath + "/" + (bFile ? tr("无标题文档%1").arg(++iNum) : tr("NewFolder%1").arg(++iNum)));
    }

    if (bFile)
    {
        QFile file(sPathDes);
        file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
        file.close();
    }
    else
    {
        m_pFileModel->mkdir(m_pFileModel->index(m_sCurPath), sPathDes);

        updateTreeWidgetData();
    }

}

//判断文件夹是否存在当前路径下
bool Widget::dirIsExistsCurrentPath(QString dirName, QString sCurPath)
{
    QDir dir(sCurPath);
    return dir.exists(dirName);
}

//判断字符串是不是纯数字
bool Widget::stringIsNumber(QString str)
{
    QByteArray ba = str.toLatin1(); //将QString转换成char*
    const char *s = ba.data();
    while(*s && *s >= '0' && *s <= '9') s++;
    return ((*s) == 0);
}

//文件夹冲突对话框弹出
int Widget::dirOrFileConflict(bool bDir, QString sNameSrc)
{
    QMessageBox box(QMessageBox::Question
                    , tr(bDir ? "文件夹冲突" : "文件冲突")
                    , bDir ? (tr("替换文件夹\"") + sNameSrc + "\"?") : tr("文件已存在，是否覆盖？")
                    , QMessageBox::Cancel | QMessageBox::Ok
                    , this);

    box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

    box.setDefaultButton(QMessageBox::Ok);
    box.setButtonText(QMessageBox::Ok, bDir ? tr("替换") : tr("覆盖"));
    box.setButtonText(QMessageBox::Cancel, tr("取消"));

    QCheckBox* checkBox = new QCheckBox("应用到所有文件", &box);
    checkBox->setGeometry(60, 30, 100, 20);
    checkBox->show();
    int selectNum = box.exec();

    int iCoverType = checkBox->isChecked() ? 2 : 1;

    MYDELETE(checkBox);
    if (selectNum == QMessageBox::Cancel) return -1;

    return iCoverType;
}

void  Widget::onItemClicked(QTreeWidgetItem *item,int)
{

    showChildRenCombox(item);
    m_sCurPath=item->data(1,0).toString();

    //列表模式
    ui->tableView->setModel(m_pFileModel);
    ui->tableView->setRootIndex(m_pFileModel->setRootPath(m_sCurPath));

    //图标模式
    ui->listView->setModel(m_pFileModel);
    ui->listView->setRootIndex(m_pFileModel->setRootPath(m_sCurPath));
}

void Widget::on_tbList_clicked()
{
    qDebug()<<"sss";
    //隐藏图标
    ui->listView->setParent(0);
    ui->listView->hide();

    //显示列表视图
    ui->tableView->setParent(ui->splitter);
    ui->tableView->show();

    //界面的比例分配
    ui->splitter->setStretchFactor(0, 20);
    ui->splitter->setStretchFactor(1, 80);
    ui->splitter->setAutoFillBackground(true);


    ui->tbList->setCheckable(true);
    ui->tbList->setFocus();

}
//设置视图 为图标模式
void Widget::on_tbIcon_clicked()
{
    //隐藏列表视图
    ui->tableView->setParent(0);
    ui->tableView->hide();

    //显示图标视图
    ui->listView->setParent(ui->splitter);
    ui->listView->show();

    //记录为列表视图
   // m_bViewState = false;

    //界面的比例分配
    ui->splitter->setStretchFactor(0, 20);
    ui->splitter->setStretchFactor(1, 80);
    ui->splitter->setAutoFillBackground(true);

    //开关状态
    ui->tbIcon->setChecked(true);
    ui->tbIcon->setFocus();

    ui->tbList->setChecked(false);
}

//在列表模式 右键 弹出菜单
void Widget::on_tableView_customContextMenuRequested(const QPoint &pos)
{
    customContextMenuRequested(pos, false);
    qDebug()<<"tableView";
}

//在图标模式 右键 弹出菜单
void Widget::on_listView_customContextMenuRequested(const QPoint &pos)
{
    customContextMenuRequested(pos, true);
}

//右键弹出菜单
void Widget::customContextMenuRequested(const QPoint &pos, bool bListView)
{
   // m_ptPress = pos;

    //开始
    QMenu menu0;
    QMenu menu1;//二级菜单

    //判断是在文件夹 还是 在文件上点击鼠标右键
    bool bValid = bListView ? ui->listView->indexAt(pos).isValid() : ui->tableView->indexAt(pos).isValid();

    if (bValid) //在文件夹 或 文件上点击鼠标右键
    {
        qDebug()<<"youxiao";
        //判断当前在哪种模式 列表模式 还是 图标模式
        QModelIndex index =  bListView ? ui->listView->indexAt(pos) : ui->tableView->indexAt(pos);

        //如果是在 文件夹 上点击右键鼠标 则弹出打开
        if (m_pFileModel->isDir(index))
        {
            QAction* pActionOpen = menu0.addAction(tr("打开"));
            connect(pActionOpen, SIGNAL(triggered()), this, SLOT(onActionOpen()));
            menu0.addSeparator();
        }
//        //else如果是在文本文件 和 图片文件 上点击鼠标右键 则创建二级菜单，让用户选择打开方式
//        {
//            QAction* pActionOpenWay = menu0.addAction(tr("打开方式"));

//            //添加二级菜单 用图片浏览器打
//            QAction* pActionOpenImage = menu1.addAction(tr("用图片浏览器打开"));
//            connect(pActionOpenImage, SIGNAL(triggered()), this, SLOT(onActionOpenImage()));

//            //添加二级菜单 用文本浏览器打开
//            QAction* pActionOpenText = menu1.addAction(tr("用文本浏览器打开"));
//            connect(pActionOpenText, SIGNAL(triggered()), this, SLOT(onActionOpenText()));

//            pActionOpenWay->setMenu(&menu1);
//        }

        QAction* pActionNewDir = menu0.addAction(tr("新建文件夹"));
        connect(pActionNewDir, SIGNAL(triggered()), this, SLOT(onActionNewDir()));

        QAction* pActionNewFile = menu0.addAction(tr("新建文档"));
        connect(pActionNewFile, SIGNAL(triggered()), this, SLOT(onActionNewFile()));

        menu0.addSeparator();

        QAction* pActionCopy = menu0.addAction(tr("复制"));
        connect(pActionCopy, SIGNAL(triggered()), this, SLOT(onActionCopy()));

        QAction* pActionCut = menu0.addAction(tr("剪切"));
        connect(pActionCut, SIGNAL(triggered()), this, SLOT(onActionCut()));

        QAction* pActionPaste = menu0.addAction(tr("粘贴"));
        connect(pActionPaste, SIGNAL(triggered()), this, SLOT(onActionPaste()));


//        QAction* pActionRename = menu0.addAction(tr("重命名"));
//        connect(pActionRename, SIGNAL(triggered()), this, SLOT(onActionRename()));

        QAction* pActionDelete = menu0.addAction(tr("删除"));
        connect(pActionDelete, SIGNAL(triggered()), this, SLOT(onActionDelete()));

        if (m_pFileModel->filePath(index).right(2) == "..")
        {
            pActionCopy->setEnabled(false);
            pActionCut->setEnabled(false);
            //pActionRename->setEnabled(false);
            pActionDelete->setEnabled(false);
        }

       // if (m_iActionState == 0) pActionPaste->setEnabled(false);
    }
    else //在空白处点击鼠标右键
    {
        QAction* pActionNewDir = menu0.addAction(tr("新建文件夹"));
        connect(pActionNewDir, SIGNAL(triggered()), this, SLOT(onActionNewDir()));

        QAction* pActionNewFile = menu0.addAction(tr("新建文档"));
        connect(pActionNewFile, SIGNAL(triggered()), this, SLOT(onActionNewFile()));

        menu0.addSeparator();

        QAction* pActionPaste = menu0.addAction(tr("粘贴"));
        connect(pActionPaste, SIGNAL(triggered()), this, SLOT(onActionPaste()));
     //   if (m_iActionState == 0) pActionPaste->setEnabled(false);
    }

    menu0.exec(QCursor::pos());
}

//打开
void Widget::onActionOpen()
{
    //1. 先判断当前是列表模式 还是 图标模式
    //QModelIndex index =  m_bViewState ? ui->listView->indexAt(m_ptPress) : ui->tableView->indexAt(m_ptPress);

    //2. 取出文件信息
  //  QFileInfo fi = m_pFileModel->fileInfo(index);

    //3. 判断当前的文件是文件夹还是文件
//    if (fi.isDir())
//    {
//        if (fi.fileName() == ".." && m_sCurPath == getDesktopPath()) return;

//        QModelIndex mIndex = m_pFileModel->index(fi.filePath());
//        m_bViewState ? ui->listView->setRootIndex(mIndex) : ui->tableView->setRootIndex(mIndex);

//        m_sCurPath = m_pFileModel->filePath(mIndex);

//    }

//    if (!m_bViewState)
//    {
//        m_pFileModel->sort(0);
//        m_pFileModel->sort(1);
//    }

//    leftAndRightSync();
}

//复制
void Widget::onActionCopy()
{
    m_iOperation = 0;
    prepareCopyAndCutPath();
}

//剪切
void Widget::onActionCut()
{
    m_iOperation = 1;
    prepareCopyAndCutPath();
}

//重命名
void Widget::onActionRename()
{
    //判断当前在哪种模式点击重命名,在那种模式下点击，就从哪种模式中取文件信息
//    QModelIndex index =  m_bViewState ? ui->listView->indexAt(m_ptPress) : ui->tableView->indexAt(m_ptPress);

    //设置可编辑
  //  m_bViewState ? ui->listView->edit(index) : ui->tableView->edit(index);

    //获取需要改名字的文件夹 或 文件的全路径
  //  QString sReNamePath = m_pFileModel->filePath(index);

    //通过路径
//    QString sOldName = getPathName(sReNamePath);

//    m_bViewState ?  ui->listView->setCurrentIndex(m_pFileModel->index(sReNamePath))
//                  : ui->tableView->setCurrentIndex(m_pFileModel->index(sReNamePath));


//    RenameDlg dlg(this);
//    dlg.setRename(sOldName);
//    dlg.exec();

  //  if (m_bViewState) ui->listView->setCurrentIndex(m_pFileModel->index(sReNamePath));

//    QString sNewNamePath = sReNamePath.left(sReNamePath.size() - sOldName.size()) + dlg.RenameInformation();
//    if (m_pFileModel->isDir(m_pFileModel->index(sReNamePath)))
//    {
//        QDir dir(sReNamePath);
//        dir.rename(sReNamePath, sNewNamePath);
//    }
//    else
//    {
//        QFile::rename(sReNamePath, sNewNamePath);
//    }
//    sReNamePath = sNewNamePath;

//    m_bViewState ? ui->lvFileList->setCurrentIndex(m_pFileModel->index(sReNamePath))
//                 : ui->listView->setCurrentIndex(m_pFileModel->index(sReNamePath));

    //重新更新目录
  //  updateTreeWidgetData();
}
//删除
void Widget::onActionDelete()
{
    QMessageBox box(QMessageBox::Question
                    , tr("温馨提示："), tr("删除后不可恢复，请慎重考虑！！！")
                    , QMessageBox::Cancel | QMessageBox::Ok
                    , this);
    box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    box.setDefaultButton(QMessageBox::Ok);
    box.setButtonText(QMessageBox::Ok, tr("确认"));
    box.setButtonText(QMessageBox::Cancel, tr("取消"));
    int selectNum = box.exec();
    if (selectNum != QMessageBox::Ok) return;

    if (m_bViewState)
    {
        QModelIndexList list = ui->listView->selectionModel()->selectedIndexes();

        if (list.size() == 0) return;
        if (!list.at(0).isValid()) return;

        int nCount = list.size();
        for (int i = 0; i < nCount; i++)
        {
            QModelIndex index = list.at(i);
            if (m_pFileModel->filePath(index).right(2) == "..") continue;

            //删除文件夹/文件
            m_pFileModel->remove(index);
            if (m_pFileModel->isDir(index)) updateTreeWidgetData();
        }
    }
    else
    {
        QModelIndex index = ui->listView->indexAt(m_ptPress);
        if (!index.isValid()) return;

        //删除文件夹/文件
        m_pFileModel->remove(index);
        if (m_pFileModel->isDir(index)) updateTreeWidgetData();
    }
}

void Widget::onDebug()
{
    QString sDesktop;
    if (stack.isEmpty()) {
        sDesktop=getDesktopPath();
        stack.push(sDesktop);
        qDebug()<<stack.size();
    }
    sDesktop=stack.pop();
    ui->listView->setRootIndex(m_pFileModel->setRootPath(sDesktop));
    stack1.push(sDesktop);

    qDebug()<<"xxxxxxx:"<<sDesktop;
}
void Widget::onBackBtn()
{
    QString sDesktop;
    if (stack1.isEmpty()) {
        sDesktop=getDesktopPath();
        stack1.push(sDesktop);
        qDebug()<<stack1.size();
    }
    sDesktop=stack1.pop();
    ui->listView->setRootIndex(m_pFileModel->setRootPath(sDesktop));
    qDebug()<<"yyyyyyyyyyyy:"<<sDesktop;
}

//点到空白处 新建文件夹
void Widget::onActionNewDir()
{
    createDirOrFile(false);
}

//点到空白处 新建文档
void Widget::onActionNewFile()
{
    createDirOrFile(true);
}
void Widget::onActionPaste()
{
    qDebug()<<"Rrrr";
    MYDELETE(m_pProgressBar);
    m_pProgressBar = new QProgressBar(NULL);
    m_pProgressBar->setWindowTitle(tr("正在复制中，请稍候......"));
    m_pProgressBar->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    m_pProgressBar->move(700, 380);
    m_pProgressBar->resize(520, 40);
    m_pProgressBar->setRange(0, 0);  //范围设置为0到0，会产生动画效果
    m_pProgressBar->show();
    qDebug()<<"ppppppppppppp";
    if (m_pThread->isRunning()) m_pThread->terminate();

    m_pThread->setCopyAndCutParam(m_sSourcePath, m_iOperation, m_pFileModel, m_sCurPath);
    m_pThread->start();
}



//槽函数， 线程复制或者剪切完毕后，给主线程反馈信号
void Widget::onCopyAndCutFinished()
{
    m_pProgressBar->hide();
    m_pProgressBar->close();
    MYDELETE(m_pProgressBar);

    updateTreeWidgetData();
    if (m_iOperation == 1) m_iActionState = 0;
}

//选择是否覆盖冲突文件或文件夹
void Widget::onChooseCoverFileOrDir(bool bDir, QString sNameSrc)
{
    int bCover = dirOrFileConflict(bDir, sNameSrc);
    emit chooseCoverFinished(bCover);
}



