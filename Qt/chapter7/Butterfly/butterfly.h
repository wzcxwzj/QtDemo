#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QGraphicsItem>    //图元类
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>

class Butterfly : public QObject,QGraphicsItem
{
public:
    Butterfly();

private:
    bool up;
    QPixmap pix_up;
    QPixmap pix_down;
    qreal angle;
};

#endif // BUTTERFLY_H
