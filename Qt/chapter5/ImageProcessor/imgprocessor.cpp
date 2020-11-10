#include "imgprocessor.h"

ImgProcessor::ImgProcessor(QWidget *parent)
    : QMainWindow(parent)
{
    createAction();
    createMenus();
    createToolBar();


    //1.创建动作,将动作关联槽,信号triggerd()
    //2.创建菜单
    //3.将动作加入菜单栏
    //4.将动作加入工具栏
    //5.点击菜单栏或工具栏，执行动作，触发动作槽函数.
}

ImgProcessor::~ImgProcessor()
{

}
void ImgProcessor::createAction()
{
    openFileAction=new QAction("打开",this);
    openFileAction->setStatusTip(tr("打开文件"));

    QAction *zoomInAction;      //缩放
    QAction *zoomOutAction;     //缩小
    QAction *rotate90Action;    //旋转90
    QAction *rotate180Action;    //旋转90
    QAction *rotate270Action;    //旋转90
    QAction *mirrorVerticalAction;       //横向镜像
    QAction *mirrorHorizontalAtion;       //纵向镜像
}
void ImgProcessor::createMenus()
{
    fileMenu=menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openFileAction);

    zoomMenu=menuBar()->addMenu(tr("编辑"));
    rotateMenu=menuBar()->addMenu(tr("旋转"));
}
void ImgProcessor::createToolBar()
{
    fileTool=addToolBar(tr("File"));
    fileTool->addAction(openFileAction);
}
