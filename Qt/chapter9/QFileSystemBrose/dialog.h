#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDir>
#include <QFile>
#include <QFileInfo>


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void slotShow(QDir);
    void showFileInfoList(QFileInfoList );
    void slotDirShow(QListWidgetItem *);
private:
    QLineEdit *line;
    QListWidget *listWidget;



};

#endif // DIALOG_H
