#include "mainwindow.h"
#include <QApplication>

#include <QGraphicsScene>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scence=new QGraphicsScene;          //建立场景
    scence->setSceneRect(QRectF(-200,-200,400,400));
    Bufferfly *bufferfly = new Bufferfly;               //图元项
    bufferfly->setPos(-100,0);
    scence->addItem(bufferfly);
    QGraphicsView *view=new QGraphicsView;   //建立视图

    view->setScene(scence);
    view->resize(400,400);
    view->show();
    return a.exec();
}
