#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    lab=new QLabel;
    lab->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    btn=new QPushButton;
    btn->setText("用户自定义消息框实例");
    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(lab,0,0);
    mainLayout->addWidget(btn,0,1);
}

MainWindow::~MainWindow()
{

}
