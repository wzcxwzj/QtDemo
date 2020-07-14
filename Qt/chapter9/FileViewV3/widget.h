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
    void showFileinfoList(QFileInfoList list);


private slots:
    void showSlotDir(QDir);
    void slotDirShow(QListWidgetItem *item);
    void showir();
private:
    QLineEdit *line;
    QListWidget *listWidget;

};

#endif // WIDGET_H
