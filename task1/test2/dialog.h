#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVariant>

enum KeyType
{
    SplitServerIp_QString = 0,
    SplitServerPort_int,
    Uid_int,
    Sid_int,
    ServerUrl_QString,
    User_QString,
    Pwd_int,
    Rember_bool,
    OtherControl_bool,
    UpScreen_bool,
    Colunm_int,
    Row_int,
    MaxFrame_int,
    MaxWinCount_int,
    MaxFullFrameWinCount_int,
    UpScreenIsConfig_bool,
    ScreenTransfer_bool,
    CameraSpeed
};
typedef unsigned char BYTE;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

    const char *str[18];
    QVariant v;
    void changexmlvalue(KeyType ntype,const QVariant &value);
    QVariant getxmlkey(KeyType ntype);
    void writeXml();


//        void RecvMsg(const BYTE *data,int len);


};

#endif // DIALOG_H
