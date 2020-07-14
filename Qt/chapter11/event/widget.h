#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QEvent>
#include <QPushButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void mouseMoveEvent(QMouseEvent *event);        //鼠标移动
    void mousePressEvent(QMouseEvent *event);       //鼠标按下
    void mouseReleaseEvent(QMouseEvent *event);     //鼠标释放
    void mouseDoubleClickEvent(QMouseEvent *event); //鼠标双击

    void keyPressEvent(QKeyEvent *event);

public slots:

    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::Widget *ui;
    QPushButton *btn;

};

#endif // WIDGET_H
