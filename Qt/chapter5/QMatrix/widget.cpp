#include "widget.h"
#include "ui_widget.h"
#include <QMatrix>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    img.load("desktop.png");
    ui->label->setPixmap(QPixmap::fromImage(img));



}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QMatrix matrix;
    matrix.scale(2,2);
    img=img.transformed(matrix);

    ui->label->setPixmap(QPixmap::fromImage(img));

}

void Widget::on_pushButton_3_clicked()
{
    QMatrix matrix;
    matrix.scale(0.5,0.5);
    img=img.transformed(matrix);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void Widget::on_pushButton_2_clicked()
{
    QMatrix matrix;
    matrix.rotate(90);
    img=img.transformed(matrix);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void Widget::on_pushButton_4_clicked()
{

    QMatrix matrix;
    matrix.rotate(180);
    img=img.transformed(matrix);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void Widget::on_pushButton_5_clicked()
{

    QMatrix matrix;
    matrix.rotate(270);
    img=img.transformed(matrix);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void Widget::on_pushButton_16_clicked()
{
    //横向镜像
    img=img.mirrored(true,false);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void Widget::on_pushButton_17_clicked()
{
    //纵向镜像
    img=img.mirrored(false,true);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
