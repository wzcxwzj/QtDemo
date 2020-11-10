#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileSystemWatcher>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void fileOperation();
    void textStreamOpation();
    void fileRun();
    void fileWatcher();

private slots:
    void slotShowWidget();
private:
    QLabel *pathLabel;
    QFileSystemWatcher fileWatcher1;

};

#endif // WIDGET_H
