#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //甭管怎么做,肯定要先做出一版
    //可以错,但是不可以不做.


    //建立场景
    //将视图加入场景
    //对于图元来说
    //1.设置图元的边界范围   QPointF boundingRect()const;
    //2.重绘函数,,绘制图元   void paint(QPainter *painter,const QStyleOptionGraphicsItem *opation,QWidget *widget);
    //{
                //painter->drawPixmap();
    //}
    //3.将图元加入场景                    ---->scene->addItem(pixItem);
    //4.设置图元在场景中的坐标              -----pixItem->setPos();

//    QGraphicsView
//   rotate()    旋转
//   scale()     缩放
//   shear()     切变
//   tarnslate() 位移

}

MainWindow::~MainWindow()
{

}
