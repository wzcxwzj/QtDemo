#ifndef TIMECLIENT_H
#define TIMECLIENT_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QTcpSocket>
#include <QAbstractSocket>

class TimeClient : public QDialog
{
    Q_OBJECT

public:
    TimeClient(QWidget *parent = 0);
    ~TimeClient();


public slots:
    void enableGetbtn();
    void getTime();
    void readTime();
    void showError(QAbstractSocket::SocketError socketError);

private:
    QLabel *serverName;
    QLabel *serverportName;
    QLineEdit *serverNameLine;
    QLineEdit *serverportNameLine;

    QDateTimeEdit *dateLineEdit;
    QLabel *stateLabel;
    QPushButton *getBtn,*quitBtn;

    QTcpSocket *tcpSocket;
    uint time2u;
};

#endif // TIMECLIENT_H
