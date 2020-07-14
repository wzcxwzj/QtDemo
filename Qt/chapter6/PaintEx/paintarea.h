#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    explicit PaintArea(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    void setPen(QPen);
    void setBrush(QBrush);
signals:

public slots:

private:
    QPen pen;
    QBrush brush;
};

#endif // PAINTAREA_H
