#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

    void createControLFrame();
public slots:
    void slotRotate(int);
    void slotScale(int);
private:
    int angel;
    qreal scaleValue;
    qreal shearValue;
    qreal translateValue;
    QFrame *ctlFrame;

    QGraphicsView *view;

};

#endif // MAINWIDGET_H
