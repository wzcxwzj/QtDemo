#ifndef DOCKWIDGET_H
#define DOCKWIDGET_H

#include <QMainWindow>

class DockWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit DockWidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // DOCKWIDGET_H