#include "bufferfly.h"
#include <math.h>
#include <QDebug>

const static double PI=3.1416;
Bufferfly::Bufferfly(QObject *parent) : QObject(parent)
{
    up=true;
    pixUp.load("aa.png");
    pixDown.load("down.png");
    startTimer(100);

}
QRectF Bufferfly::boundingRect() const
{
    qreal adjust=2;
    return QRectF(-pixUp.width()/2-adjust,-pixUp.height()/2-adjust,
                  pixUp.width()+adjust*2,pixUp.height()+adjust*2);
}
void Bufferfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{  qDebug()<<"ss";
    if(up)
    {  qDebug()<<"ssqqs";
        painter->drawPixmap(boundingRect().topLeft(),pixUp);
        up=!up;
    }
    else
    {qDebug()<<"ssrrrrrr";
        painter->drawPixmap(boundingRect().topLeft(),pixDown);
        up=!up;
    }
}
void Bufferfly::timerEvent(QTimerEvent *event)
{
    qDebug()<<"ss";
  qreal edgex=scene()->sceneRect().right()+boundingRect().width()/2;

  qreal edgextop=scene()->sceneRect().top()+boundingRect().width()/2;
  qreal edgexbottom=scene()->sceneRect().bottom()+boundingRect().width()/2;

  if(pos().x() >=edgex)
      setPos(scene()->sceneRect().left(),pos().y());
  if(pos().y() <=edgextop)
      setPos(pos().x(),scene()->sceneRect().bottom());
  if(pos().y() >=edgexbottom)
      setPos(pos().x(),scene()->sceneRect().top());
  angle+=(qrand()%10)-20.0;
  qreal dx=fabs(sin(angle*PI)*10.0);
  qreal dy=(qrand()%20)-10.0;
  setPos(mapToParent(dx,dy));
}




