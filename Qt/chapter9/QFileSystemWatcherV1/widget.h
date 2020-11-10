#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QFileSystemWatcher>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void changeDirectory(QString);
private:
    QLabel *lab1;
    QFileSystemWatcher fsWatcher;

};

#endif // WIDGET_H
