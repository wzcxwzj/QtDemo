#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setMouseTracking(true);
    btn=new QPushButton(tr("按钮"),this);
    btn->installEventFilter(this);
    int width = size().width();
    qDebug()<<width;
}

Widget::~Widget()
{
    delete ui;
}
void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"x= :"<<event->x();
    qDebug()<<"y= :"<<event->y();
    if(event->button() == Qt::LeftButton)
        qDebug()<<"按下了左键";
    else if(event->button() == Qt::RightButton)
    {
         qDebug()<<"按下了右键";
    }else if (event->button() == Qt::MidButton) {
        qDebug()<<"按下了中间键";
    }
}
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"x= :"<<event->x();
    qDebug()<<"y= :"<<event->y();
}
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<"释放:x: "<<event->x();
    qDebug()<<"释放:y: "<<event->x();
}
void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<"双击";
}
/*******键盘事件*******/
void Widget::keyPressEvent(QKeyEvent *event)
{
   if( event->modifiers()  ==Qt::ControlModifier)
   {
       qDebug()<<"Ctrl键已按下...";
   }
   if( event->key()  ==Qt::Key_Left)
   {
       qDebug()<<"左键已按下...";
   }
   if( event->key()  ==Qt::Key_Right)
   {
       qDebug()<<"右键已按下...";
   }
   if( event->key()  ==Qt::Key_Up)
   {
       qDebug()<<"上键已按下...";
   }
   if( event->key()  ==Qt::Key_Down)
   {
       qDebug()<<"下键已按下...";
   }
}

bool Widget::eventFilter(QObject *watched, QEvent *event)       //事件过滤器,监视事件
{
  if(watched == btn)  //首先判断当前发生事件的对象
  {
    if(event->type() == QEvent::KeyPress) //判断发生的事件类型

        //将事件event转化为鼠标事件  (具体事件)
        qDebug()<<"键盘已按下...";
  }

}

