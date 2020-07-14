#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPalette palette=this->palette();
    palette.setColor(QPalette::Window,Qt::white);
    setPalette(palette);

    setFixedWidth(512);
    setFixedHeight(256);

    width=size().width();
    height=size().height();

    pix=new QPixmap(width,height);
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

    QPainter *painter=new QPainter;
    QPen pen;
    pen.setStyle(Qt::DotLine);

    for(int i=step;i<width;i=i+step)
    {
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(i,0),QPoint(i,height));
    }
    for(int j=step;j<height;j=j+step)
    {
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(0,j),QPoint(width,j));
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

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() ==Qt::ControlModifier)
     {
        qDebug()<<"Ctrl键被按下...";
        if(event->key() ==Qt::Key_Left)
        {
            startX=(startX<0)?startX:startX-1; qDebug()<<startX;
        }
      }
    update();
    drawPix();
}



