#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QDir>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void slotShow(QDir);
    void slotShowDir(QListWidgetItem*);

private:
    QLineEdit *line1;
    QListWidget *listWidget;
    QVBoxLayout *qvb;
};

#endif // DIALOG_H
