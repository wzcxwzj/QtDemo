#ifndef MAPWIDGET_H
#define MAPWIDGET_H
#include <QGraphicsView>
#include <QLabel>
#include <QMouseEvent>
#include <QFile>
#include <QTextStream>

class MapWidget : public QGraphicsView
{
public:
    MapWidget();
    void readMap();              //读取地图信息
    QPointF mapToMap(QPointF );//场景坐标转地图坐标
public slots:
    void slotZoom(int);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void drawBackground(QPainter *painter, const QRectF &rect);//完成地图显示功能
private:
    QPixmap map;
    qreal zoom;
    QLabel *viewCoord;      //视图坐标
    QLabel *sceneCoord;     //场景坐标
    QLabel *mapCoord;       //地图坐标

    double x1,y1;
    double x2,y2;

};

#endif // MAPWIDGET_H
