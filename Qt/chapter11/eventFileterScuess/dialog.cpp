#include "dialog.h"
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QMatrix>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    lab1=new QLabel();
    lab1->setGeometry(0,0,700,600);
    img1.load("F:/1.jpg");
    lab1->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    lab1->setPixmap(QPixmap::fromImage(img1));


    stateLab=new QLabel;
    stateLab->setText("鼠标按下的标志: ");

    QVBoxLayout *qvb=new QVBoxLayout(this);
    qvb->addWidget(lab1);
    qvb->addWidget(stateLab);

    lab1->installEventFilter(this);     //设置图片的监视对象

}

Dialog::~Dialog()
{

}

bool Dialog::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == lab1)        //判断发生事件的对象
    {
      if(event->type() == QEvent::MouseButtonPress)  //判断发生事件的类型,,是否等于鼠标按下事件
      {
          QMouseEvent *mouseEvent=(QMouseEvent *)event;                                         //将事件对象转为具体的事件类型
          if(mouseEvent->buttons() == Qt::LeftButton)
          {
                stateLab->setText("鼠标左键被按下");
          }
          else if (mouseEvent->buttons() == Qt::MidButton)
          {
               stateLab->setText("鼠标中键被按下");
          }
          else if (mouseEvent->buttons() == Qt::RightButton)
          {
               stateLab->setText("鼠标右键被按下");
          }
          QMatrix matrix;
          matrix.scale(1.8,1.8);
          QImage tmpImg=img1.transformed(matrix);
          lab1->setPixmap(QPixmap::fromImage(tmpImg));
      }
      else if (event->type() == QEvent::MouseButtonRelease)
      {
           stateLab->setText("鼠标释放左边图片");
           lab1->setPixmap(QPixmap::fromImage(img1));
      }


    }
}
