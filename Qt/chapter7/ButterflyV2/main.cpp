#include "mainwindow.h"
#include <QApplication>
#include "bufferfly.h"
#include <QGraphicsScene>
#include <QGraphicsView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QGraphicsScene *scene=new QGraphicsScene;
    bufferfly *buffly=new bufferfly;
    buffly->setPos();
    scene->addItem(buffly); //将图元加入进场景

    QGraphicsView *view=new QGraphicsView;  //将场景放进视图
    view->setScene(scene);

    return a.exec();
}
