#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void drawPix();
    void paintEvent(QPaintEvent *event);

    void keyPressEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;
    QPixmap *pix;
    QImage  img;

    int startX;
    int startY;

    int width;
    int height;
    int step;


};

#endif // MAINWINDOW_H
