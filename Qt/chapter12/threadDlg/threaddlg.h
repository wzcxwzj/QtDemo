#ifndef THREADDLG_H
#define THREADDLG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include "workthread.h"

#define MaxSize 5
class ThreadDlg : public QDialog
{
    Q_OBJECT

public:
    ThreadDlg(QWidget *parent = 0);
    ~ThreadDlg();
private slots:
    void slotStart();
    void slotStop();

private:
    QPushButton *btn1,*btn2,*btn3;
    WorkThread *workThread[MaxSize];

};

#endif // THREADDLG_H
