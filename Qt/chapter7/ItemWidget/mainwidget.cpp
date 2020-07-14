#include "mainwidget.h"
#include <QHBoxLayout>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QGraphicsScene *scene=new QGraphicsScene;
    scene->setSceneRect(-200,-200,400,400);
    QPixmap *pixmap=new QPixmap("img.png");
    scene->addItem(pixmap);
    view=new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400,400);


}

MainWidget::~MainWidget()
{

}

void MainWidget::createControLFrame()
{
    //旋转控制
    QSlider *rotateSlider=new QSlider;
    rotateSlider->setOrientation(Qt::Horizontal);
    rotateSlider->setRange(0,360);

    //缩放控制
    QSlider *scaleSlider=new QSlider;
    scaleSlider->setOrientation(Qt::Horizontal);
    scaleSlider->setRange(0,360);
    //scaleSlider->setValue(scaleValue);
    //切变控制
    QSlider *shearSlider=new QSlider;
    shearSlider->setOrientation(Qt::Horizontal);
    shearSlider->setRange(0,360);

    //位移控制
    QSlider *translateSlider=new QSlider;
    translateSlider->setOrientation(Qt::Horizontal);
    translateSlider->setRange(0,360);


}

void MainWidget::slotRotate(int)
{

}
