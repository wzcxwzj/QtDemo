#include "widget.h"
#include <QGridLayout>
#include <qbitmap.h>
#include <qwidget.h>
#include <qscroller.h>
#include <qlist.h>
#include <qpainter.h>
#include <qimage.h>
#include <qfile.h>
#include <qpoly

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    quick=new QQuickWidget;
    QGridLayout *grid=new QGridLayout(this);
    grid->addWidget(quick);


    quick->setSource(QUrl("qrc:/new/main.qml"));

    resize(555,559);
}

Widget::~Widget()
{

}
