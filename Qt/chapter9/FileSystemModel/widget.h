#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileSystemModel>
#include <QModelIndexList>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void rm();

private:
    Ui::Widget *ui;
    QFileSystemModel *model;
    QModelIndexList list;
};

#endif // WIDGET_H
