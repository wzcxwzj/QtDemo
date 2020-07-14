#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDir>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void sizeFileDir();
    quint64 du(const QString path);
    void fileShow();
    void showFileInfoList(QFileInfoList list);
private slots:
    void showDir(QDir dir);
    void slotDirShow(QListWidgetItem *item);
private:
    QLineEdit *line;
    QListWidget *listWidget;

};

#endif // WIDGET_H
