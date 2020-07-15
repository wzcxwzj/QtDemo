#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QDialog>
#include <QLabel>
#include <QImage>
#include <QEvent>

class EventFilter : public QDialog
{
    Q_OBJECT

public:
    EventFilter(QWidget *parent = 0,Qt::WindowFlags f=0);
    ~EventFilter();
  //  void eventInit();
    bool eventFilter(QObject *, QEvent *);


private:
    QLabel *lab1,*lab2,*lab3,*stateLab;
    QImage img1,img2,img3;
};

#endif // EVENTFILTER_H
