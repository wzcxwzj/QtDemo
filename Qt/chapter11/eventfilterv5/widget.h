#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QMatrix>
#include <QMouseEvent>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    bool eventFilter(QObject *watched, QEvent *event);
    void wheelEvent(QWheelEvent *event);
private:
    QLabel *lab1,*stateLabel;
    QImage img;
    double m_currentIndex;
};

#endif // WIDGET_H
