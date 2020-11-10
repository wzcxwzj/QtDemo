#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QPaintEvent>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void drawPix();
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    QPixmap *pix;  //作为一个绘图设备，使用双缓冲机制实现图形的绘制
    QImage  img;  //界面中间小图标

    int startX;
    int startY;

    int width;
    int height;
    int step;
};

#endif // WIDGET_H
