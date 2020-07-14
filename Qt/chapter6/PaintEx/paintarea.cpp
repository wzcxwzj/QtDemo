#include "paintarea.h"
#include <QDebug>

PaintArea::PaintArea(QWidget *parent) : QWidget(parent)
{
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    setMinimumSize(400,400);
}
void PaintArea::setPen(QPen p)
{
    pen=p;
    update();
    qDebug()<<"pen";
}
void PaintArea::setBrush(QBrush b)
{
    brush=b;
    update();
    qDebug()<<"brush";
}
void PaintArea::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen(pen);
    p.setBrush(brush);
    QRect rect(50,100,300,200);
    p.drawLine(rect.topLeft(),rect.bottomRight());

}
