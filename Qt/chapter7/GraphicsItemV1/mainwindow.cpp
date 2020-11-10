#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{   createActions();
    createMenus();

    scene=new QGraphicsScene;
    scene->setSceneRect(-200,-200,400,400);
    initScene();

    QGraphicsView *view=new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400,400);
    view->show();
    setCentralWidget(view);
    resize(550,450);
    setWindowTitle(tr("Grphics Items"));
}

MainWindow::~MainWindow()
{

}

void MainWindow::initScene()
{
    int i;
    //for(i=0;i<3;i++)
    slotAddEllipseItem();
    addFlashItem();
}

void MainWindow::createActions()
{
    newAct=new QAction(tr("新建"),this);
    clearAct=new QAction(tr("清除"),this);
    exitAct=new QAction(tr("退出"),this);
    addElipseItemAct=new QAction(tr("加入 椭圆"),this);
    addPolygonItemAct=new QAction(tr("加入 多边形"),this);
    addTextItemAct=new QAction(tr("加入 文字"),this);
    addRectItemAct=new QAction(tr("加入 长方形"),this);
    addAlphaItemact=new QAction(tr("加入 透明图片"),this);
    connect(newAct,SIGNAL(triggered()),this,SLOT(slotNew()));
    connect(clearAct,SIGNAL(triggered()),this,SLOT(slotClear()));
 //   connect(exitAct,SIGNAL(triggered()),this,SLOT());
    connect(addElipseItemAct,SIGNAL(triggered()),this,SLOT(slotAddEllipseItem()));
//    connect(addPolygonItemAct,SIGNAL(triggered()),this,SLOT());
//    connect(addTextItemAct,SIGNAL(triggered()),this,SLOT());
//    connect(addRectItemAct,SIGNAL(triggered()),this,SLOT());
//    connect(addAlphaItemact,SIGNAL(triggered()),this,SLOT());


}

void MainWindow::createMenus()
{
    QMenu *fileMenu=menuBar()->addMenu(tr("文件"));
        fileMenu->addAction(newAct);
        fileMenu->addAction(clearAct);
        fileMenu->addSeparator();
        fileMenu->addAction(exitAct);
     QMenu *itemsMenu=menuBar()->addMenu(tr("元素"));
        itemsMenu->addAction(addElipseItemAct);
        itemsMenu->addAction(addPolygonItemAct);
        itemsMenu->addAction(addTextItemAct);
        itemsMenu->addAction(addRectItemAct);
        itemsMenu->addAction(addAlphaItemact);
}

void MainWindow::slotNew()
{
    slotClear();
    initScene();
    MainWindow *newWin=new MainWindow;
    newWin->show();
}

void MainWindow::slotClear()
{
    QList<QGraphicsItem *>listItem=scene->items();
    while (!listItem.empty())
    {
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
}
//场景坐标，x轴正方向向右，y轴正方向向下.
void MainWindow::slotAddEllipseItem()
{
    QGraphicsEllipseItem *item=new QGraphicsEllipseItem(QRectF(0,0,80,60));
    item->setPen(Qt::NoPen);
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
    //item->setPos(-152,78);
    qDebug()<<(qrand()%int(scene->sceneRect().width()))-200;
    qDebug()<<(qrand()%int(scene->sceneRect().height()))-200;
}

void MainWindow::addFlashItem()
{
   FlashItem *item=new FlashItem;
   scene->addItem(item);
   item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                (qrand()%int(scene->sceneRect().height()))-200);
}
