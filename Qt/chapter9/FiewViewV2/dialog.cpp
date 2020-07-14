#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    line1=new QLineEdit();
    listWidget=new QListWidget;
    qvb=new QVBoxLayout(this);

    qvb->addWidget(line1);
    qvb->addWidget(listWidget);

    connect(line1,SIGNAL(returnPressed()),this,SLOT(slotShow(QDir)));
    connect(listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(slotShowDir(QListWidgetItem*)));

    QStringList string;
    string<<"*";



}

Dialog::~Dialog()
{

}
void Dialog::slotShow(QDir)
{

}
void Dialog::showFileInfoList(QFileInfoList *)
{

}
void Dialog::slotShowDir(QListWidgetItem *)
{

}
