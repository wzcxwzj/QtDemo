#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::Widget *ui;
    QImage img;
};

#endif // WIDGET_H
