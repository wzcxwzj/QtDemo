#include "histogramview.h"
#include <QPainter>

#include <QDebug>
HistogramView::HistogramView()
{

}

QRect HistogramView::visualRect(const QModelIndex &index)const
{
    qDebug()<<index.child(2,3).data();
}

QModelIndex HistogramView::indexAt(const QPoint &point) const
{

}

void HistogramView::setSelectionModel(QItemSelectionModel *selectionModel)
{

}

QRegion HistogramView::itemRegion(QModelIndex index)
{

}

void HistogramView::paintEvent(QPaintEvent *)
{
        QPainter painter(viewport());
        painter.setPen(Qt::black);
        int x0=40;
        int y0=250;
        //完成x,y坐标轴的绘制，并标注坐标轴的变量
        //y坐标轴
            painter.drawLine(x0,y0,40,30);
            painter.drawLine(38,32,40,30);
            painter.drawLine(40,30,43,32);
            painter.drawText(20,30,tr("人数"));
        for(int i=1;i<5;i++)
        {
            painter.drawLine(-1,-i*50,1,-i*50);
            painter.drawText(-20,-i*50,tr("%1").arg(i*5));
        }

        //x坐标轴
            painter.drawLine(x0,y0,540,250);
            painter.drawLine(538,248,540,250);
            painter.drawLine(540,250,538,252);
            painter.drawText(545,250,tr("部门"));
            int posD=x0+20;
            int row;
        for(row=0;row<model()->rowCount(rootIndex());row++)
        {
            QModelIndex index=model()->index(row,0,rootIndex());

            QString dep=
            model()->data(index).toString();
            painter.drawText(posD,y0+20,dep);
            posD+=50;
        }
        //完成表格第1列数据的柱状统计图的绘制
        int posM=x0+20;//完成表格第2列数据的柱状统计图的绘制=x0+30;
        MRegionList.clear();
        for(row=0;row<model()->rowCount(rootIndex());row++)
        {
            QModelIndex index=model()->index(row,0,rootIndex());
            int male=model()->data(index).toDouble();
            int width=10;
            if(selections->isSelected(index))
                 painter.setBrush(QBrush(
                Qt::blue,Qt::Dense3Pattern
                ));
            else
                painter.setBrush(Qt::blue);
            painter.drawRect(QRect
            (posM,y0-male*10,width,male*10));

            QRegion regionM(posM,y0-male*10,width,male*10);
            MRegionList.insert(row,regionM);
            posM+=50;
       }
        //完成表格第2列数据的柱状统计图的绘制
        //女
        int posF=x0+30;
        FRegionList.clear();
        for(row=0;row<model()->rowCount(rootIndex());row++)
        {
            QModelIndex index=model()->index(row,0,rootIndex());
            int female=model()->data(index).toDouble();
            int width=10;
            if(selections->isSelected(index))
                 painter.setBrush(QBrush(
                Qt::red,Qt::Dense3Pattern
                ));
            else
                painter.setBrush(Qt::red);
            painter.drawRect(QRect
            (posF,y0-female*10,width,female*10));

            QRegion regionF(posF,y0-female*10,width,female*10);
            FRegionList.insert(row,regionF);
            posM+=50;
        }
        //完成表格第3列数据的柱状统计图的绘制
        //退休
        int posS=x0+40;
        SRegionList.clear();
        for(row=0;row<model()->rowCount(rootIndex());row++)
        {
            QModelIndex index=model()->index(row,3,rootIndex());
            int retire=model()->data(index).toDouble();
            int width=10;
            if(selections->isSelected(index))
                 painter.setBrush(QBrush(
                Qt::green,Qt::Dense3Pattern
                ));
            else
                painter.setBrush(Qt::green);
            painter.drawRect(QRect
            (posS,y0-retire*10,width,retire*10));

            QRegion regionS(posS,y0-retire*10,width,retire*10);
            FRegionList.insert(row,regionS);
            posS+=50;
        }
}

void HistogramView::mousePressEvent(QMouseEvent *event)
{

}

void HistogramView::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{

}

void HistogramView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{

}

QModelIndex HistogramView::moveCursor(QAbstractItemView::CursorAction cursorAction, Qt::KeyboardModifiers modifiers)
{

}

int HistogramView::horizontalOffset() const
{

}

int HistogramView::verticalOffset() const
{

}

bool HistogramView::isIndexHidden(const QModelIndex &index) const
{

}

void HistogramView::setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags command)
{

}

QRegion HistogramView::visualRegionForSelection(const QItemSelection &selection) const
{

}
