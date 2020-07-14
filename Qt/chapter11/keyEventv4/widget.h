#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void drawPix();

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

    QPixmap *pix;
    QImage img;

    int startX;
    int startY;

    int width;
    int height;
    int step;

};

#endif // WIDGET_H
