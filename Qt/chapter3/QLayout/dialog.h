#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QComboBox *combox;
    QLabel *userName,*Name,*age,*departMent,
        *note,*headPortrait,*personElucidation,
        *headIconLabel;

    QLineEdit *line1,*line2,*line3;
    QTextEdit *edit1,*edit2;
    QPushButton *btn1,*btn2,*btn3;




};

#endif // DIALOG_H
