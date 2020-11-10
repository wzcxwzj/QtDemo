#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "basewindow.h"

namespace Ui {
class Widget;
}

class Widget : public BaseWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:

    void initTitleBar();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
