#ifndef BUFFERFLY_H
#define BUFFERFLY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

class bufferfly:public QObject,QGraphicsItem
{
public:
    bufferfly();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void timerEvent(QTimerEvent *event);
};

#endif // BUFFERFLY_H
