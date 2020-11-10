#include "widget.h"
#include "ui_widget.h"

#include <QDir>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QAbstractItemView>
#include <QModelIndex>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QFileSystemModel(this);
    model->setRootPath(QDir::currentPath());
    ui->lvFileList->setModel(model); //设置数据模型
    QString sPathSrc="C://Qt/Qt5.10.0/dist/hhhh.txt";

   QString str= sPathSrc.mid(sPathSrc.lastIndexOf("/") + 1);

    QModelIndex tempIndex = model->index(sPathSrc);
    QFileInfo tempInfo = model->fileInfo(tempIndex);

    qDebug()<<str;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::rm()
{
    QModelIndex index = ui->treeView->currentIndex();
    if (!index.isValid()) {
        return;
    }
    bool ok;
    if (model->fileInfo(index).isDir()) {
        ok = model->rmdir(index);
    } else {
        ok = model->remove(index);
    }
    if (!ok) {
        QMessageBox::information(this,
                         tr("Remove"),
                         tr("Failed to remove %1").arg(model->fileName(index)));
    }
}
