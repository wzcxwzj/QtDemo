#include "butterfly.h"
#include <QPainter>
#include <QDebug>

const static double PI=3.1416;
Butterfly::Butterfly(QObject *parent) : QObject(parent)
{
    up=true;
    pix_Up.load("F:/2.png");
    pix_Down.load("F:/2.png");
    startTimer(100);

   // qDebug()<<pix_Up.width()/2+4;
}

QRectF Butterfly::boundingRect() const
{
    qreal adjust=2;
    return QRectF(-pix_Up.width()/2-adjust,-pix_Up.height()/2-adjust,
                  pix_Up.width()+adjust*2,pix_Up.height()+2*adjust);


}

void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(up)
    {
        painter->drawPixmap(boundingRect().topLeft(),pix_Up);
        up=!up;
    }
    else
    {
        painter->drawPixmap(boundingRect().topLeft(),pix_Down);
        up=!up;
    }
}

void Butterfly::timerEvent(QTimerEvent *event)
{
    //边界控制
    qreal edgex=scene()->sceneRect().right()+boundingRect().width()/2;   //限定蝴蝶飞舞的右边界
    qreal edgextop=scene()->sceneRect().top()+boundingRect().height()/2;//限定蝴蝶飞舞的上边界
    qreal edgexbottom=scene()->sceneRect().bottom()+boundingRect().height()/2;//限定蝴蝶飞舞的下边界

    if(pos().x()>edgex) //若超过了右边界, 水平移动到左边界
        setPos(scene()->sceneRect().left(),pos().y());
    if(pos().y()>edgextop) //若超过了上边界, 则垂直移回下边界
        setPos(pos().x(),scene()->sceneRect().bottom());
    if(pos().y()>edgexbottom)  //若超过了下边界, 则垂直移回上边界
        setPos(pos().x(),scene()->sceneRect().top());

    angle+=(qrand()%10)/20.0;
    qreal dx=fabs(sin(angle*PI)*10.0);
    qreal dy=fabs(qrand()%20)-10.0;
    setPos(mapToParent(dx,dy));
}
