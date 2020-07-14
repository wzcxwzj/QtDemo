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
public slots:
        void dealWithWatcher(QString);

private:

    QLabel *pathLabel;
    QFileSystemWatcher fsWatcher;
};

#endif // WIDGET_H
