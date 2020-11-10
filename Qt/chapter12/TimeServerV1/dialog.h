#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include "timeserver.h"


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    void slotShow();
private:
    QLabel *lab1,*lab2;
    QPushButton *btn;

    TimeServer *timeServer;
    int count;

};

#endif // DIALOG_H
