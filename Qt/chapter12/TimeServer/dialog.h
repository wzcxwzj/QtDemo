#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

class TimeServer;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void slotShow();
private:
    QLabel *lab1;
    QLabel *lab2;

    QPushButton *quitBtn;

    TimeServer *timeSever;
    int count;
};

#endif // DIALOG_H
