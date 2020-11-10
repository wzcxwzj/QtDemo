#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void showCustDlg();
private:
    QLabel *lab;
    QPushButton *btn;
    QGridLayout *mainLayout;
};

#endif // WIDGET_H
