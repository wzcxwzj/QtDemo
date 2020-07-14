#ifndef TIMECLIENT_H
#define TIMECLIENT_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateTimeEdit>
#include <QTcpSocket>



class TimeClient : public QDialog
{
    Q_OBJECT

public:
    TimeClient(QWidget *parent = 0);
    ~TimeClient();


private slots:
    void enableGetbtn();
    void getTime();
    void readTime();
    void showError(QAbstractSocket::SocketError);
private:
    QLabel *lab1,*lab2,*lab3;
    QLineEdit *line1,*line2;
    QPushButton *btn1,*btn2;
    QDateTimeEdit *dataEdit;

    uint time2u;
    QTcpSocket *tcpScoket;

};

#endif // TIMECLIENT_H
