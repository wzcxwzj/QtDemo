#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

class Butterfly : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Butterfly(QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void timerEvent(QTimerEvent *event);
signals:

public slots:

private:
    bool up;
    QPixmap pix_Up;
    QPixmap pix_Down;
    qreal angle;

};

#endif // BUTTERFLY_H
