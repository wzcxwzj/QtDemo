#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QListWidgetItem>

#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createFileModel();
    void createSplitter();
    void createQListVew();


    void createQListWidget();
    void leftAndRightSync();

private slots:
    void  on_listView_doubleClicked(const QModelIndex &index);
    void  onItemClicked(QListWidgetItem *item);
private:
    Ui::MainWindow *ui;
    QFileSystemModel *m_pFileModel;
    QListWidgetItem *m_pItem;
    QString m_sCurPath;     //当前路径
};

#endif // MAINWINDOW_H
