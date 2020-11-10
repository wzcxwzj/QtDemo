#include "widget.h"
#include <QDebug>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

   setAutoFillBackground(true);
   QPalette palette=this->palette();
   palette.setColor(QPalette::Window,Qt::white);
   setPalette(palette);
   setMinimumSize(512,256);
   setMaximumSize(512,256);
   width = size().width();
   height =size().height();

   pix=new QPixmap(width,height);
   pix->fill(Qt::white);
   img.load("pix.png");

   startX =100;
   startY =100;
   step =20;
   drawPix();
   resize(512,256);
}

Widget::~Widget()
{

}
void Widget::drawPix()
{
    pix->fill(Qt::white);
    QPainter *painter=new QPainter;
    QPen pen(Qt::DotLine);

    for(int i=step;i<width;i=i+step)
    { qDebug()<<"ssss";

        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(i,0),QPoint(i,height));
        painter->end();
    }
    for(int j=step;j<height;j=j+step)
    { qDebug()<<"ssss";

        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(0,j),QPoint(width,j));
        painter->end();
    }
    painter->begin(pix);
    painter->drawImage(QPoint(startX,startY),img);
    painter->end();

}
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(QPoint(0,0),*pix);
    painter.end();
}
