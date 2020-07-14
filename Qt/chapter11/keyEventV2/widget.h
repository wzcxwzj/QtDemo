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

    void  paintEvent(QPaintEvent *event);
    void  keyPressEvent(QKeyEvent *event);
private:
    QPixmap *pix;
    QImage img;
    int startX;
    int startY;

    int width;
    int height;
    int step;


};

#endif // WIDGET_H
