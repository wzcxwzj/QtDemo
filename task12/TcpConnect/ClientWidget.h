#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H
#include <QTcpSocket>
#include <QWidget>
#include <QString>
namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = 0);
    ~ClientWidget();

private slots:
    void on_connectbutton_clicked();

    void on_closebutton_clicked();

    void on_sendbutton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ClientWidget *ui;
    QTcpSocket* st2;
    QByteArray arr2;
};

#endif // CLIENTWIDGET_H
