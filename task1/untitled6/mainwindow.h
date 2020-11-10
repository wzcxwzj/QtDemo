#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
enum KeyType
{
    SplitServerIp_QString = 0,
    SplitServerIp_int,

};
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void file();
    void readxml();
   void changexmlvalue(KeyType ntype,const QVariant &value);
/*
    1.
*/

    QVariant getxmlkey(KeyType ntype);
     //QVariant getxmlkey(KeyType ntype);
    void writexml();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
