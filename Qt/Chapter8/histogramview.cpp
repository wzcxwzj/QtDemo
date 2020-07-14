#include "histogramview.h"
#include <QPainter>

HistogramView::HistogramView(QWidget parent):QAbstractItemView(parent)
{

}

//void HistogramView::paintEvent(QPaintEvent *)
//{
//    QPainter painter(viewport());
//    painter.setPen(Qt::black);
//    int x0=40;
//    int y0=250;
//    //完成x,y坐标轴的绘制，并标注坐标轴的变量
//    //y坐标轴
//    painter.drawLine(x0,y0,40,30);
//    painter.drawLine(38,32,40,30);
//    painter.drawLine(40,30,43,32);
//    painter.drawText(20,30,tr("人数"));
//    for(int i=1;i<5;i++)
//    {
//    painter.drawLine(-1,-i*50,1,-i*50);
//    painter.drawText(-20,-i*50,tr("%1").arg(i*5));
//    }

//    //x坐标轴
//    painter.drawLine(x0,y0,540,250);
//    painter.drawLine(538,248,540,250);
//    painter.drawLine(540,250,538,252);
//    painter.drawText(540,250,tr("部门"));
//    int posD=x0+20;
//    int row;
//    for(row=0;row<model()->rowCount(rootIndex());row++)
//    {
//    QModelIndex index=model()->index(row,0,rootIndex());

//    QString dep=
//    model()->data(index).toString();
//    painter.drawText(posD,y0+20,dep);
//    posD+=50;
//    }
//}
