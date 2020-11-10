#include "widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    line=new QLineEdit;
    listWidget=new QListWidget;
    QVBoxLayout *qvb=new QVBoxLayout(this);
    qvb->addWidget(line);
    qvb->addWidget(listWidget);

    connect(line,SIGNAL(returnPressed()),this,SLOT(slotDir()));


}

Widget::~Widget()
{

}
