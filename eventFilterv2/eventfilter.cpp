#include "eventfilter.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QMatrix>

EventFilter::EventFilter(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    lab1=new QLabel(this);
    img1.load("C:/Users/Administrator/Documents/canBeDeleted/practice/delete/delete/build-eventFilter-Desktop_Qt_5_10_0_MinGW_32bit-Debug/1.png");
    lab1->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    lab1->setPixmap(QPixmap::fromImage(img1));

    lab2=new QLabel;
    img2.load("2.png");
    lab2->setAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
    lab2->setPixmap(QPixmap::fromImage(img2));

    lab3=new QLabel;
    lab3->setAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
    img3.load("3.png");
    lab3->setPixmap(QPixmap::fromImage(img3));

    stateLab=new QLabel(tr("鼠标按下标志:"));
    stateLab->setAlignment(Qt::AlignHCenter);
    QHBoxLayout *qhb =new QHBoxLayout;
    qhb->addWidget(lab1);
    qhb->addWidget(lab2);
    qhb->addWidget(lab3);

    QVBoxLayout *qvb=new QVBoxLayout(this);
    qvb->addLayout(qhb);
    qvb->addWidget(stateLab);

    lab1->installEventFilter(this);//为每一个图片安装事件过滤器
    lab2->installEventFilter(this);
    lab3->installEventFilter(this);
}

EventFilter::~EventFilter()
{

}

bool EventFilter::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == lab1) //判断当前发生事件的对象
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent=(QMouseEvent *)event;
            if(mouseEvent->buttons()&Qt::LeftButton)
            {
                stateLab->setText(tr("左键按下左边图片"));
            }
            else if (mouseEvent->buttons()&Qt::MidButton)
            {
                 stateLab->setText(tr("中键按下中边图片"));
            }
            else if(mouseEvent->buttons()&Qt::RightButton)
            {
                 stateLab->setText(tr("右键按下右边图片"));
            }
            /*显示缩小图片*/
            QMatrix matrix;
            matrix.scale(1.8,1.8);
            QImage tmpImg=img1.transformed(matrix);
            lab1->setPixmap(QPixmap::fromImage(tmpImg));

        }

        /*鼠标释放事件的处理，恢复图片的大小*/
        if(event->type()==QEvent::MouseButtonRelease)
        {
            stateLab->setText(tr("鼠标释放左边图片"));
            lab1->setPixmap(QPixmap::fromImage(img1));
        }

    }else if (watched ==lab2) {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent=(QMouseEvent *)event;
            if(mouseEvent->buttons()&Qt::LeftButton)
            {
                stateLab->setText(tr("左键按下左边图片"));
            }
            else if (mouseEvent->buttons()&Qt::MidButton)
            {
                stateLab->setText(tr("中键按下中边图片"));
            }
            else if(mouseEvent->buttons()&Qt::RightButton)
            {
                 stateLab->setText(tr("右键按下右边图片"));
            }
            /*显示缩小图片*/
            QMatrix matrix;
            matrix.scale(1.8,1.8);
            QImage tmpImg=img1.transformed(matrix);
            lab2->setPixmap(QPixmap::fromImage(tmpImg));

        }

        /*鼠标释放事件的处理，恢复图片的大小*/
        if(event->type()==QEvent::MouseButtonRelease)
        {
            stateLab->setText(tr("鼠标释放左边图片"));
            lab2->setPixmap(QPixmap::fromImage(img1));
        }
    }
    else if (watched == lab3)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent=(QMouseEvent *)event;
            if(mouseEvent->buttons()&Qt::LeftButton)
            {
                stateLab->setText(tr("左键按下左边图片"));
            }
            else if (mouseEvent->buttons()&Qt::MidButton)
            {
                stateLab->setText(tr("中键按下中边图片"));
            }
            else if(mouseEvent->buttons()&Qt::RightButton)
            {
                 stateLab->setText(tr("右键按下右边图片"));
            }
            /*显示缩小图片*/
            QMatrix matrix;
            matrix.scale(1.8,1.8);
            QImage tmpImg=img1.transformed(matrix);
            lab3->setPixmap(QPixmap::fromImage(tmpImg));

        }

        /*鼠标释放事件的处理，恢复图片的大小*/
        if(event->type()==QEvent::MouseButtonRelease)
        {
            stateLab->setText(tr("鼠标释放左边图片"));
            lab3->setPixmap(QPixmap::fromImage(img1));
        }
    }
}

//void EventFilter::eventInit()
//{

//    //首先为监视对象安装事件过滤器

//    lab1->installEventFilter(this);
//}
//bool EventFilter::eventFilter(QObject *watched, QEvent *event)
//{

//    if(watched==lab1)
//    {
//        if(event->type() ==Qt::MouseButton) //判断事件类型
//        {
//            QMouseEvent *mouseEvent=(QMouseEvent *)event;
//            if(mouseEvent->buttons() == Qt::LeftButton)
//            {

//            }
//            else if(mouseEvent->buttons() ==Qt::MidButton)
//            {

//            }
//            else if(mouseEvent->button()==Qt::RightButton)
//            {

//            }
//        }
//        QMatrix matrix;
//        matrix.scale(1.8,1.8);
//        QImage tmpImag=img1.transformed(matrix);
//        lab1->setPixmap(QPixmap::fromImage(tmpImag));


//    }

//}

//bool EventFilter::eventFilter(QObject *watched, QEvent *event)
//{
//    lab2->installEventFilter(this);

//    if(watched==lab2)
//    {
//        if(event->type() == Qt::MouseButton)
//         {   QMouseEvent *mouseEvent=(QMouseEvent *)event;
//            if(mouseEvent->buttons()  == Qt::LeftButton)
//            {}
//         }
//    }



//}
