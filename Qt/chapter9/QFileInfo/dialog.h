#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void slotFile();
    void slotGetfileInfo();
private:
    QLabel *fileName,*fileSize,*fileCreateTime,
            *fileChangeTime,*fileLastTime,
    *fileAttribute;
    QLineEdit *line1,*line2,*line3,*line4,*line5;
    QPushButton *fileBtn,*fileInfoBtn;
    QCheckBox *dirCheck,*fileCheck,*symbolicLink,
            *hideCheck,*readCheck,*writeCheck,
            *perFormCheck;


};

#endif // DIALOG_H
