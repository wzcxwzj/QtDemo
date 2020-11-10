#include "dialog.h"
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QMatrix>

Dialog::Dialog(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{

    lab1=new QLabel();
    img1.load("4.png");
    lab1->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    lab1->setPixmap(QPixmap::fromImage(img1));

    lab2=new QLabel();
    img2.load("4.png");
    lab2->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    lab2->setPixmap(QPixmap::fromImage(img2));

    lab3=new QLabel();
    img3.load("4.png");
    lab3->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    lab3->setPixmap(QPixmap::fromImage(img3));


    QVBoxLayout *qvb=new  QVBoxLayout(this);
    qvb->addWidget(lab1);
    qvb->addWidget(lab2);
    qvb->addWidget(lab3);

    lab1->installEventFilter(this);
//    lab2
//    lab3
//    stateLab;
//    img1
//    img2
//    img3;
}

Dialog::~Dialog()
{

}

bool Dialog::eventFilter(QObject *watched, QEvent *event)
{
    if(watched ==lab1)
    {
        if(event->type() == Qt::MouseButton)
        {
            QMouseEvent *mouseEvent=(QMouseEvent *)event;
            if(mouseEvent->buttons() == Qt::LeftButton)
            {
                //鼠标左键被按下
            }
            else if(mouseEvent->buttons() == Qt::MiddleButton)
            {
                //中键被按下
            }else if (condition) {

            }
            QMatrix matrix;
            matrix.scale(1.8,1.8);
            QImage tmpImge=img1.transformed(matrix);
            lab1->setPixmap(tmpImge);

        }
    }
}



