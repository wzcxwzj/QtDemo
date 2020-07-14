#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   QStandardItemModel *model=new QStandardItemModel(4,2);

   model->setHeaderData(0,Qt::Horizontal,tr("Label"));
   model->setHeaderData(1,Qt::Horizontal,tr("Quantity"));

   for(int row=0;row<4;++row)
   {
       for(int column=0;column<2;++column)
       {
           QModelIndex index=model->index(row,column,QModelIndex());
           model->setData(index,QVariant((row+1)*(column+1)));
       }
   }
   ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
