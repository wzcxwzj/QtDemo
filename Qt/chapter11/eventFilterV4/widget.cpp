#include "widget.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QMouseEvent>
#include <QMatrix>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    lab1=new QLabel();
    img.load("F:/2.png");
    lab1->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    lab1->setPixmap(QPixmap::fromImage(img));

    stateLabel=new QLabel(tr("鼠标按下标志"));
    QVBoxLayout *qhb=new QVBoxLayout(this);
    qhb->addWidget(lab1);
    qhb->addWidget(stateLabel);


    lab1->installEventFilter(this); //注册事件监听
    resize(300,400);
}
Widget::~Widget()
{

}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==lab1)       //是否是监听对象
    {
//        qDebug()<<"sddddwdw";
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *moustEvent=(QMouseEvent *)event;
            if(moustEvent->buttons()&Qt::LeftButton)
            {
                stateLabel->setText("你按下了左键...");
            }
            else if(moustEvent->button()==Qt::RightButton)
            {
                stateLabel->setText("你按下了右键...");
            }
            else if(moustEvent->button()==Qt::MidButton)
            {
                stateLabel->setText("你按下了中键...");
            }
            QMatrix matrix;
            matrix.scale(1.8,1.8);
            QImage tmpImg=img.transformed(matrix);
            lab1->setPixmap(QPixmap::fromImage(tmpImg));
        }
         if(event->type() == QEvent::MouseButtonRelease)
        {
            stateLabel->setText("鼠标释放...");
            lab1->setPixmap(QPixmap::fromImage(img));
        }
    }
}
