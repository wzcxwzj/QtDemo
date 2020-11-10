#include "widget.h"
#include <QDebug>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPalette palette=this->palette();
    palette.setColor(QPalette::Window,Qt::white);
    setPalette(palette);

    setMinimumSize(512,256);
    setMaximumSize(512,256);

    width=size().width();
    height=size().height();
    qDebug()<<width;
    pix=new QPixmap(width,height);
    pix->fill(Qt::white);
    img.load("F:/2.png");
    startX=100;
    startY=100;

    step=20;
    drawPix();
    resize(512,256);
}

Widget::~Widget()
{

}
void Widget::drawPix()
{
    pix->fill(Qt::white);
    QPainter *painter =new QPainter;
    QPen pen;
    pen.setStyle(Qt::DotLine);
    for(int i=step;i<width;i=i+step)
    {
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(i,0),QPoint(i,height));
        painter->end();
    }
    for(int j=step;j<height;j=j+step)
    {
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(0,j),QPoint(width,j));
        painter->end();
    }
    painter->begin(pix);
    painter->drawImage(QPoint(startX,startY),img);
}
void Widget::paintEvent(QPaintEvent *event)
{
  QPainter painter;
  painter.begin(this);
  painter.drawPixmap(QPoint(0,0),*pix);
  painter.end();
}
 void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers()==Qt::ControlModifier)
    {
        qDebug()<<"Ctrl键";
        if(event->key()==Qt::Key_Left)
        {
            qDebug()<<"左键";
        }
    }
    else {
        if(event->key()==Qt::Key_Left)
        {
            qDebug()<<"你按下了左键";
        }
    }
}
