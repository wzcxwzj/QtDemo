#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette palette=this->palette();
    palette.setColor(QPalette::Window,Qt::white);
    setPalette(palette);

    setMinimumSize(521,256);
    setMaximumSize(512,256);
    width=size().width();
    height=size().height();



    pix=new QPixmap(width,height);
    pix->fill(Qt::white);
    img.load("F:/2.png");


    startX=100;
    startY=100;

    step=20;
    drawPix();
    resize(512,256);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawPix()
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
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers()==Qt::ControlModifier)
    {
        //按下Ctrl键
        if(event->key()==Qt::Key_Left)
        {
            startX=(startX-1<0)?startX:startX-1;
        }
        if(event->key()==Qt::Key_Right)
        {
            startX=((startX+1+img.width())>width)?startX:startX+1;
        }
        if(event->key()==Qt::Key_Up)
        {
            startY=(startY-1<0)?startY:startY-1;
        }
        if(event->key()==Qt::Key_Down)
        {
            startY=((startY+1+img.height())>height)?startY:startY+1;
        }
    }
    else
    {
        startX=startX-startX%step;
        startY=startY-startY%step;

        if(event->key()==Qt::Key_Left)
        {
            startX=(startX-step<0)?startX:startX-step;
        }
        if(event->key()==Qt::Key_Right)
        {
            startX=((startX+step+img.width())>width)?startX:startX+step;
        }
        if(event->key()==Qt::Key_Up)
        {
            startY=(startY-step<0)?startY:startY-step;
        }
        if(event->key()==Qt::Key_Down)
        {
           startY=((startY+img.height())>height)?startY:startY+step;
        }
        if(event->key()==Qt::Key_Home)      //home键
        {
            startX=0;
            startY=0;
        }
        if(event->key()==Qt::Key_Escape)      //end键
        {
            startX=0;
            startY=0;
        }
        if(event->key()==Qt::Key_End)      //end键
        {
           startX=width-img.width();
           startY=height-img.height();

        }
    }

    update();
    drawPix();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(QPoint(0,0),*pix);
    painter.end();

}
