#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QQuickWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QQuickWidget *quick;
};

#endif // WIDGET_H
