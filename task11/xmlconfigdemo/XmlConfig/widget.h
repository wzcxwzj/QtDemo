#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void writeXml();
    QByteArray getFileMd5(QString filePath) ;
private slots:
    void getText();
private:
    Ui::Widget *ui;
    QString currentTime;
    int versionNum=0;
    QString versionInformation;
    QStringList titleList;
    QStringList md5List;

};

#endif // WIDGET_H
