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
    QByteArray getFileMd5(QString filePath);
    bool FindFile(const QString &path);
private slots:
    void getText();
private:
    Ui::Widget *ui;
    QString currentTime;
    QStringList titleList;
    QStringList md5List;
    QStringList md5FileList;
    QStringList dirPathParse;
    QStringList fileList;  //文件


     QStringList pDir;   //目录
    int m_nFilesCount;
    int m_nDirCount;


};

#endif // WIDGET_H
