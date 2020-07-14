#include "widget.h"
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setAutoFillBackground(true);
    QPalette palette =this->palette();
    palette.setBrush(QPalette::Window,Qt::white);
    setPalette(palette);

    setMinimumSize(512,256);
    setMaximumSize(512,256);

    width=size().width();
    height=size().height();

    //qDebug()<<width;
    pix=new QPixmap(width,height);
    pix->fill(Qt::white);
    img.load("F:/1.png");


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
    QPainter painter;
    QPen pen;
    pen.setStyle(Qt::DotLine);
    for(int i=step;i<width;i=i+step)
    {
        painter.begin(pix);
        painter.setPen(pen);
        painter.drawLine(QPoint(i,0),QPoint(i,height));
        painter.end();
    }
    for(int j=step;j<height;j=j+step)
    {
        painter.begin(pix);
        painter.setPen(pen);
        painter.drawLine(QPoint(0,j),QPoint(width,j));
         painter.end();
    }
    painter.begin(pix);
    painter.drawImage(QPoint(startX,startY),img);
    painter.end();
}
void  Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier)
    {
        if(event->key()==Qt::Key_Left)
        {
            startX=((startX-1)<0)?startX:startX-1;
        }
        if(event->key()==Qt::Key_Right)
        {
            startX=((startX+1+img.width())>width)?startX:startX+1;
        }
        if(event->key()==Qt::Key_Up)
        {

        }
        if(event->key()==Qt::Key_Down)
        {

        }
    }
    else
    {   startX=startX-startX%step;
        startY=startY-startY%step;
        if(event->key()==Qt::Key_Left)
        {
            startX=((startX+step +img.width())<0)?startX:startX-step;
        }
        if(event->key()==Qt::Key_Right)
        {
            startX=((startX+step+img.width())>width)?startX:startX+step;
        }
        if(event->key()==Qt::Key_Up)
        {

        }
        if(event->key()==Qt::Key_Down)
        {

        }
        if(event->key() ==Qt::Key_Home)
        {
            startX=0;
            startY=0;
        }
        if(event->key()==Qt::Key_End)
        {
            startX=width-img.width();
            startY=height-img.height();
        }
    }
    drawPix();
    update();
}
void  Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(QPoint(0,0),*pix);
    painter.end();
}
