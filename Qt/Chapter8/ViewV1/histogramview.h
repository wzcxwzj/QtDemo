#ifndef HISTOGRAMVIEW_H
#define HISTOGRAMVIEW_H

#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QRegion>

class HistogramView : public QAbstractItemView
{  /* Q_OBJECT*/
public:
   HistogramView();
    QRect visualRect(const QModelIndex &index) const;
    QModelIndex indexAt(const QPoint &point) const;

    void setSelectionModel(QItemSelectionModel *selectionModel);
    QRegion itemRegion(QModelIndex index);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
protected slots:
     void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
     void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
protected:
     QModelIndex moveCursor(QAbstractItemView::CursorAction cursorAction, Qt::KeyboardModifiers modifiers);
     int horizontalOffset()const;
     int verticalOffset()const;
     bool isIndexHidden(const QModelIndex &index) const;
     void setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags command);
     QRegion visualRegionForSelection(const QItemSelection &selection) const;
private:
    QItemSelectionModel *selections;
    QList<QRegion>MRegionList;
    QList<QRegion>FRegionList;
    QList<QRegion>SRegionList;
};

#endif // HISTOGRAMVIEW_H
