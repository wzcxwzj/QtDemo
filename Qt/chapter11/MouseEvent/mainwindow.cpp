#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    StatusLabel=new QLabel(tr("当前位置:"));
    StatusLabel->setFixedWidth(100);
    MouseLabel=new QLabel(tr(""));
    MouseLabel->setFixedWidth(100);


    statusBar()->addPermanentWidget(StatusLabel);
    statusBar()->addPermanentWidget(MouseLabel);
    this->setMouseTracking(true);
    resize(400,200);
}

MainWindow::~MainWindow()
{

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QString str="("+QString::number(event->x())+","+QString::number(event->y())+")";
    if(event->buttons() ==Qt::LeftButton)
    {
        statusBar()->showMessage("左键:"+str);
    }
    else if (event->buttons() ==Qt::MidButton)
    {
        statusBar()->showMessage("中键:"+str);
    }
    else if (event->buttons() ==Qt::RightButton)
    {
        statusBar()->showMessage("右键:"+str);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    MouseLabel->setText("("+QString::number(event->x())+","+QString::number(event->y())+")");
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QString str="("+QString::number(event->x())+","+QString::number(event->y())+")";
    statusBar()->showMessage("释放在:"+str);
}
