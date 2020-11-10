#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QImage>


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
    bool eventFilter(QObject *, QEvent *);
private:
    QLabel *lab1,*stateLab;
    QImage img1;
};

#endif // DIALOG_H
