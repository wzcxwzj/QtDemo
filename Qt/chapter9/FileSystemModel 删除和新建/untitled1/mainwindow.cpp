#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QFileSystemModel();
    model->setRootPath(QDir::currentPath());
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(QDir::currentPath()));


    setWindowTitle("File System Model");

    connect(ui->pushButton, SIGNAL(clicked()),
           this, SLOT(mkdir()));
    connect(ui->pushButton_2, SIGNAL(clicked()),
           this, SLOT(rm()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mkdir()
{
    QModelIndex index = ui->treeView->currentIndex();
        if (!index.isValid()) {
            return;
        }
        QString dirName = QInputDialog::getText(this,
                                                tr("Create Directory"),
                                                tr("Directory name"));
        if (!dirName.isEmpty()) {
            if (!model->mkdir(index, dirName).isValid()) {
                QMessageBox::information(this,
                                         tr("Create Directory"),
                                         tr("Failed to create the directory"));
            }
        }
}
void MainWindow::rm()
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

void MainWindow::on_pushButton_3_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();//选中文件

    QFileInfo tempInfo = model->fileInfo(index);

    qDebug()<<tempInfo.fileName();
    QString strName=tempInfo.fileName();
    QFile file;
    file.copy(strName,"C://Users/Administrator/canBeDeleted/practice/demo/build-untitled1-Desktop_Qt_5_10_0_MinGW_32bit-Debug/回收站/strName.txt");

    QFile file2;
    file2.remove(strName);

}
