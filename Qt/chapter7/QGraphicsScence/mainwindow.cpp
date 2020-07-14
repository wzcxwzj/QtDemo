#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsPixmapItem>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setStyleSheet("QGraphicsView{background-color: rgb(80, 80, 80);}");

    m_pMyScene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(m_pMyScene);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(loadPixmap()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::loadPixmap()
{
    QRect viewRect = ui->graphicsView->geometry();
  QGraphicsPixmapItem  *m_pPixmapItem = new QGraphicsPixmapItem(QPixmap("F:/2.png"));

    m_pMyScene->setSceneRect(1, 1, viewRect.width() - 2, viewRect.height() - 2); //将坐标原点设在显示窗口的左上角
    m_pMyScene->addRect(1, 1, viewRect.width() - 4, viewRect.height() - 4, QPen(Qt::red)); //红色方框标明场景区域

    m_pPixmapItem->setPos((viewRect.width() - m_pPixmapItem->pixmap().width()) / 2,
    (viewRect.height() - m_pPixmapItem->pixmap().height()) / 2); //设定图片在场景中的坐标

    qDebug()<<""<<m_pPixmapItem->pos().x();
    m_pMyScene->addItem(m_pPixmapItem);
}
