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

    void writeXML();
    QByteArray getFileMd5(QString filePath);
    bool FindFile(const QString &path);
    QString createMD5(QString filename);

private slots:
    void getText();
private:
    Ui::Widget *ui;
    QString currentTime;

    //目录
    QStringList pDir;
    QStringList dirPathParse;
    QStringList md5List;
    QString relativePath;

    //文件
    QStringList fileList;
    QStringList titleList;
    QStringList md5FileList;

    int m_nFilesCount;
    int m_nDirCount;


};

#endif // WIDGET_H
