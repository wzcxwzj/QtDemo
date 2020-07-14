#include "bufferfly.h"

bufferfly::bufferfly()
{

}

void bufferfly::timerEvent(QTimerEvent *event)
{
    qreal edgex=scene()->sceneRect().right()+boundingRect().width()/2;


    if(pos().x()>edgex)     //超过左边界  水平返回右边界
        setPos();
}
