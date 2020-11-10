#ifndef XMLCONFIG_H
#define XMLCONFIG_H

#include <QObject>
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
class xmlConfig : public QObject
{
    Q_OBJECT
public:
    explicit xmlConfig(QObject *parent = nullptr);

    void writeXml();
    void changeXmlValue(KeyType ntype,const QVariant &value);
    QVariant getXmlValue(KeyType ntype);


signals:

public slots:
private:

    const char *str[18];
    QVariant v;
    QString XmlPathFileName;
};

#endif // XMLCONFIG_H
