#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void loadPixmap();

private:
    Ui::MainWindow *ui;
     QGraphicsScene* m_pMyScene;
};

#endif // MAINWINDOW_H
