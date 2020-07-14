#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QImage>
#include <QEvent>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0,Qt::WindowFlags f=0);
    ~Dialog();

    bool eventFilter(QObject *, QEvent *);
private:
    QLabel *lab1,*lab2,*lab3,*stateLab;
    QImage img1,img2,img3;
};

#endif // DIALOG_H
