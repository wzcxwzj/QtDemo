#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    bool  eventFilter(QObject *watched, QEvent *event);
private:
    QLabel *lab1,*stateLabel;
    QImage img;


};

#endif // WIDGET_H
