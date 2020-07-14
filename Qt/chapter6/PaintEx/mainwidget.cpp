#include "mainwidget.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    widgetInit();

}

MainWidget::~MainWidget()
{

}
void MainWidget::widgetInit()
{   paintArea =new PaintArea();

    lab1=new QLabel(tr("形状: "));
    lab2=new QLabel(tr("画笔颜色: "));
    penColorFrame=new QFrame;
    penColorFrame->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    penColorFrame->setAutoFillBackground(true);
    penColorFrame->setPalette(Qt::blue);
    btn1=new QPushButton(tr("更改"));


    lab3=new QLabel(tr("画笔线宽"));
    penWidthSpinbox=new QSpinBox;
    penWidthSpinbox->setRange(0,20);
    connect(penWidthSpinbox,SIGNAL(valueChanged(int)),this,SLOT(showPenWidth(int)));

    lab4=new QLabel(tr("画笔风格"));
    lab5=new QLabel(tr("画笔顶帽"));
    lab6=new QLabel(tr("画笔连接点"));
    lab7=new QLabel(tr("填充模式:"));
    lab8=new QLabel(tr("铺展效果"));

    lab9=new QLabel(tr("画刷颜色"));
    brushColorFrame=new QFrame;
    brushColorFrame->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    brushColorFrame->setAutoFillBackground(true);
    brushColorFrame->setPalette(Qt::green);
    btn2=new QPushButton(tr("更改"));
    connect(btn2,SIGNAL(clicked()),this,SLOT(showBrushColor()));

    lab10=new QLabel(tr("画刷风格"));


    com1=new QComboBox;
    com2=new QComboBox;
    com3=new QComboBox;
    com4=new QComboBox;//画笔风格
    com4->addItem(tr("SolidLine"),static_cast<int>(Qt::SolidLine));
    com4->addItem(tr("DashLine"),static_cast<int>(Qt::DashLine));
    com4->addItem(tr("DotLine"),static_cast<int>(Qt::DotLine));

    com5=new QComboBox;//画笔顶帽
    com5->addItem(tr("SquareCap"),Qt::SquareCap);
    com5->addItem(tr("FlatCap"),Qt::FlatCap);
    com5->addItem(tr("RoundCap"),Qt::RoundCap);


    com6=new QComboBox;//画笔连接点
    com6->addItem(tr("BevelJoin"),Qt::BevelJoin);
    com6->addItem(tr("MiterJoin"),Qt::MiterJoin);
    com6->addItem(tr("RoundJoin"),Qt::RoundJoin);


    com7=new QComboBox;
    com8=new QComboBox;
    com9=new QComboBox;
    com10=new QComboBox;//画刷风格
    com10->addItem(tr("SolidPattern"),static_cast<int>(Qt::SolidPattern));
    com10->addItem(tr("Dense1Pattern"),static_cast<int>(Qt::Dense1Pattern));
    com10->addItem(tr("Dense2Pattern"),static_cast<int>(Qt::Dense2Pattern));
    com10->addItem(tr("Dense3Pattern"),static_cast<int>(Qt::Dense3Pattern));
    com10->addItem(tr("Dense4Pattern"),static_cast<int>(Qt::Dense4Pattern));


    QGridLayout *grid=new QGridLayout;
    grid->addWidget(lab1,0,0);
    grid->addWidget(com1,0,1);
    grid->addWidget(lab2,1,0);
    grid->addWidget(com2,1,1);
    grid->addWidget(btn1,1,2);
    grid->addWidget(lab3,2,0);
    //grid->addWidget(com3,2,1);
    grid->addWidget(penWidthSpinbox,2,1);

    grid->addWidget(lab4,3,0);
    grid->addWidget(com4,3,1);
    grid->addWidget(lab5,4,0);
    grid->addWidget(com5,4,1);
    grid->addWidget(lab6,5,0);
    grid->addWidget(com6,5,1);
    grid->addWidget(lab7,6,0);
    grid->addWidget(com7,6,1);
    grid->addWidget(lab8,7,0);
    grid->addWidget(com8,7,1);
    grid->addWidget(lab9,8,0);
    //grid->addWidget(com9,8,1);
    grid->addWidget(brushColorFrame,8,1);
    grid->addWidget(btn2,8,2);
    grid->addWidget(lab10,9,0);
    grid->addWidget(com10,9,1);


    QHBoxLayout *qhb=new QHBoxLayout(this);

    qhb->addWidget(paintArea);
    qhb->addLayout(grid);
    qhb->setStretchFactor(paintArea,1);
    qhb->setStretchFactor(grid,0);
}
void MainWidget::showPenWidth(int value)
{
    qDebug()<<"设置线宽";
    QColor color=penColorFrame->palette().color(QPalette::Window);
    Qt::PenStyle style=Qt::PenStyle(com4->itemData(com4->currentIndex(),Qt::UserRole).toInt());
    Qt::PenCapStyle cap=Qt::PenCapStyle(com5->itemData(com5->currentIndex(),Qt::UserRole).toInt());
    Qt::PenJoinStyle join= Qt::PenJoinStyle(com6->itemData(com6->currentIndex(),Qt::UserRole).toInt());
    paintArea->setPen(QPen(color,value,style,cap,join));
}
void MainWidget::showBrushColor()
{
    QColor color=QColorDialog::getColor(static_cast<int>(Qt::blue));
    brushColorFrame->setPalette(QPalette(color));
    showBrush(com10->currentIndex());
}
void MainWidget::showBrush(int value)
{
     QColor color=brushColorFrame->palette().color(QPalette::Window);
     Qt::BrushStyle style=Qt::BrushStyle(com10->itemData(value,Qt::UserRole).toInt());
     if(style ==Qt::LinearGradientPattern)
     {
         QLinearGradient linearGradient(0,0,400,400);
         linearGradient.setColorAt(0.0,Qt::white);
         linearGradient.setColorAt(0.2,color);
         linearGradient.setColorAt(1.0,Qt::black);
         linearGradient.setSpread(spread);
         paintArea->setBrush(linearGradient);
     }
     else
     {
         paintArea->setBrush(QBrush(color,style));
     }





}


void MainWidget::wheelEvent(QWheelEvent *event)
{
    qDebug()<<"你动了滚轮!!";
}


