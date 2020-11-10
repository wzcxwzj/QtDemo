#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>
#include <QMenuBar>
#include <QAction>
#include <QSplitter>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    void createAction();
//    void createMenu();
//    void setupModel();
    void setupView();
private:
//    QMenu *fileMenu;
//    QAction *openAct;
//    QStandardItemModel *model;
//    QTableView *table;
    QSplitter *splitter;

    //HistogramView *histogram;
};

#endif // MAINWINDOW_H
