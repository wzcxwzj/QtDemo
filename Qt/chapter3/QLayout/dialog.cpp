#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    combox=new QComboBox();
    userName=new QLabel(tr("用户名:"));
    Name=new QLabel(tr("姓名:"));

    age=new QLabel(tr("姓别:"));
    departMent=new QLabel(tr("部门:"));
    note=new QLabel(tr("备注:"));
    headPortrait=new QLabel(tr("头像:"));
    personElucidation=new QLabel(tr("个人说明:"))
    headIconLabel=new QLabel();

    line1
    line2
    line3
    edit1
    edit2;
    btn1
    btn2
    btn3;


}

Dialog::~Dialog()
{

}
