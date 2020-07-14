#ifndef BUFFERFLY_H
#define BUFFERFLY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

class Bufferfly : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Bufferfly(QObject *parent = nullptr);
    void timerEvent(QTimerEvent *event);
    QRectF boundingRect()const;

signals:
public slots:
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);  //重绘函数
private:
    bool up;
    QPixmap pixUp;
    QPixmap pixDown;

    qreal angle;
};

#endif // BUFFERFLY_H
