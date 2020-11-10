#ifndef FILEVIEW_H
#define FILEVIEW_H

#include <QDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>
#include <QDir>
#include <QListWidget>
#include <QFileInfoList>

class FileView : public QDialog
{
    Q_OBJECT

public:
    FileView(QDialog *parent = 0);
    ~FileView();
    void showFileInfoList(QFileInfoList list);

private slots:
    void slotShow(QDir dir);
    void slotDirShow(QListWidgetItem *item);
private:

    QLineEdit *fileLineEdit;
    QListWidget *fileListWidget;
    QVBoxLayout *mainlayout;


};

#endif // FILEVIEW_H
