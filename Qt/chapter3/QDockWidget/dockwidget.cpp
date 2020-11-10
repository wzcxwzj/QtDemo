#include "dockwidget.h"
#include <QDockWidget>
#include <QTextEdit>

DockWidget::DockWidget(QWidget *parent) : QMainWindow(parent)
{
    QTextEdit *te=new QTextEdit(this);
    te->setText(tr("Main Window"));
    te->setAlignment(Qt::AlignCenter);
    setCentralWidget(te);//将编辑框设为主窗口的中央窗体

    //停靠窗口1
    QDockWidget *dock=new QDockWidget(tr("DockWidget1"),this);
    //可移动
    dock->setFeatures
    (QDockWidget::DockWidgetMovable);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea  |Qt::RightDockWidgetArea);
    QTextEdit *te1=new QTextEdit();
    te1->setText(tr("Window1 ..."));
    dock->setWidget(te1);
    addDockWidget(Qt::RightDockWidgetArea,dock);


    //停靠窗口2
    dock=new QDockWidget(tr("DockWidget2"),this);
    //可移动
    dock->setFeatures
    (QDockWidget::DockWidgetMovable);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea  |Qt::RightDockWidgetArea);
    QTextEdit *te2=new QTextEdit();
    te2->setText(tr("Window2 ..."));
    dock->setWidget(te2);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    //停靠窗口3
    dock=new QDockWidget(tr("DockWidget3"),this);
    //可移动
    dock->setFeatures
    (QDockWidget::DockWidgetMovable);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea  |Qt::RightDockWidgetArea);
    QTextEdit *te3=new QTextEdit();
    te3->setText(tr("Window3 ..."));
    dock->setWidget(te3);
    addDockWidget(Qt::RightDockWidgetArea,dock);


}
