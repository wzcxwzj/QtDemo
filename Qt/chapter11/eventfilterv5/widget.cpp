#include "widget.h"
#include <QVBoxLayout>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    lab1=new QLabel;
    img.load("F:/2.png");
    img= img.scaled(img.width()*3.9,img.height()*3.9
                     ,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    lab1->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
    lab1->setPixmap(QPixmap::fromImage(img));

    stateLabel=new QLabel;
    stateLabel->setText("鼠标按下标志");

    QVBoxLayout *qvb=new QVBoxLayout(this);
    qvb->addWidget(lab1);
    qvb->addWidget(stateLabel);
    lab1->installEventFilter(this);    //注册监听对象
    resize(300,400);

}

Widget::~Widget()
{

}
bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==lab1)   //判断监听对象
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent=(QMouseEvent *)event;
            if(mouseEvent->button()==Qt::LeftButton)
            {
                stateLabel->setText("你按下了左键...");
            }
            else if(mouseEvent->button()==Qt::MidButton)
            {
                stateLabel->setText("你按下了中键...");
            }
            else if(mouseEvent->button()==Qt::RightButton)
            {
                stateLabel->setText("你按下了右键...");
            }
            QMatrix matrix;
            matrix.scale(1.8,1.8);
            QImage tmpImg=img.transformed(matrix);
            lab1->setPixmap(QPixmap::fromImage(tmpImg));
        }
        if(event->type()==QEvent::MouseButtonRelease)
        {
            stateLabel->setText("鼠标释放...");
            lab1->setPixmap(QPixmap::fromImage(img));
        }
    }
}
void Widget::wheelEvent(QWheelEvent *event)
{
   qDebug()<<event->delta()/500.0;

}
