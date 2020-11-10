#include "widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    lab=new QLabel;
    lab->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    btn=new QPushButton;
    btn->setText("用户自定义消息框实例");
    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(lab,0,0);
    mainLayout->addWidget(btn,0,1);

    connect(btn,SIGNAL(clicked()),this,SLOT(showCustDlg()));
}

Widget::~Widget()
{

}
void Widget::showCustDlg()
{
    lab->setText("Custem Message Box");
    QMessageBox cusstemMessage;
    cusstemMessage.setWindowTitle("用户自定义消息框..");
    QPushButton *btn1=cusstemMessage.addButton(tr("Yes"),QMessageBox::ActionRole);
    QPushButton *btn2=cusstemMessage.addButton(tr("No"),QMessageBox::ActionRole);

    cusstemMessage.setText("这是一个用户自定义的消息框");

    cusstemMessage.exec();
    if(cusstemMessage.clickedButton() ==btn1)
        lab->setText("Custem Message Box/Yes");
    if(cusstemMessage.clickedButton() ==btn2)
        lab->setText("Custem Message Box/No");

}
