#include "mapwidget.h"
#include <QSlider>

MapWidget::MapWidget()
{
    QSlider *slider=new QSlider(this);
    slider->setOrientation(Qt::Vertical);
    slider->setRange(1,100);
    slider->setTickInterval(10);
    slider->setValue(50);
}

void MapWidget::readMap()
{
    QString mapName;
    QFile  mapFile();
    int ok=mapFile.open(QIODevice::ReadOnly);
    if(ok)
    {
        QTextStream ts(&mapFile);
        if(!ts.atEnd())
        {
            ts>>mapName;
            ts>>x1>>y1>>x2>>y2;
        }
    }
    map.load(mapName);
}

void MapWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint  viewPoint= event->pos();
    viewCoord->setText(QString::number(viewPoint.x())+","+QString::number(viewPoint.y()));
    QPointF sceneRect =mapToScene(viewPoint);
    sceneCoord->setText(QString::number(sceneRect.x())+","+QString::number(sceneRect.y()));
    QPointF latLon =mapToMap(sceneRect);//场景转地图
    mapCoord->setText(QString::number(latLon.x())+","+QString::number(latLon.y()));

}

void MapWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->drawPixmap(int(sceneRect().left()),int(sceneRect().top()),map);
}

QPointF MapWidget::mapToMap(QPointF p)
{
    QPointF latLon;
    qreal w=sceneRect().width();
    qreal h=sceneRect().height();
    qreal lon=y1-((h/2+p.y())*abs(y1-y2)/h);
    qreal lat=x1-((w/2+p.x())*abs(x1-x2)/w);
    latLon.setX(lat);
    latLon.setY(lon);
}

void MapWidget::slotZoom(int value) //地图缩放
{
    qreal s;
    if(value>zoom)                  //放大
    {
        s=pow(1.01,(value-zoom));

// 函数解释:       long double pow(long double X,int Y);
//                返回X的Y次幂。
    }
    else                            //缩小
    {
        s=pow(1/1.01,(zoom-value));
    }
    scale(s,s);
    zoom=value;
}
