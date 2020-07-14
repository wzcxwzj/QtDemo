#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "paintarea.h"

#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QGradient>
#include <QTextEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QFrame>
#include <QColorDialog>


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void widgetInit();
    void wheelEvent(QWheelEvent *event);
protected slots:
    void showPenWidth(int);

    void showBrushColor();
    void showBrush(int);

private:
    PaintArea *paintArea;

    QLabel *lab1,*lab2,*lab3,*lab4,*lab5,
            *lab6,*lab7,*lab8,*lab9,*lab10;
    QComboBox *com1,*com2,*com3,*com4,*com5,
                *com6,*com7,*com8,*com9,*com10;

    QPushButton *btn1,*btn2;
    QSpinBox *penWidthSpinbox;

    QFrame *penColorFrame;
    QFrame *brushColorFrame;
    QGradient::Spread spread;
};

#endif // MAINWIDGET_H
