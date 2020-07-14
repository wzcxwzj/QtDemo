#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeView>
#include <QInputDialog>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QVariant data( const QModelIndex& index, int role) const;
private slots:

    void mkdir();
    void rm();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *model;

};

#endif // MAINWINDOW_H
