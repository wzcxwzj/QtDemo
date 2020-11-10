#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QFile>
#include <QDir>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
    void showFileInfoList(QFileInfoList list);
   void showDir(QDir);
private slots:
    void sloShowDir(QListWidgetItem *);
private:
    QLineEdit *line;
    QListWidget *listWidget;

};

#endif // DIALOG_H
