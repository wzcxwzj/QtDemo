#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include <QStandardPaths>
#include <QTreeWidgetItem>
#include <QFileSystemModel>
#include <QDir>
#include <QMenu>
#include <QMessageBox>
#include <QProgressBar>
#include <QStack>

#include "basewindow.h"
#include "threadOpation.h"
#include "myqfilemodel.h"

namespace Ui {
class Widget;
}

class Widget : public BaseWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void initTitleBar();
    void initThread();
    void createFileModel();
    void createSplitter();//对分割窗口QSplitter进行设置

    void createQTreeWidget();
    void createQTableVew();//创建右侧的列表窗口视图.
    void createQListVew();//创建右侧的列表窗口视图.
    void loadFile(QString sPath,QTreeWidgetItem *item);

    void leftAndRightSync();
    QTreeWidgetItem *getChildItemByPath(QTreeWidgetItem *parent,QString sPath);
    void getAllLastpath(QString sCurPath);
    QString getDesktopPath();//获取系统的桌面路径
    void prepareCopyAndCutPath();
    QString getPathName(QString sPath);
    void showChildRenCombox(QTreeWidgetItem *);
    void freeListTreeWidgetItem();
    void updateTreeWidgetData();
    void createDirOrFile(bool bFile);
    bool dirIsExistsCurrentPath(QString dirName, QString sCurPath);
    bool stringIsNumber(QString str);
    int dirOrFileConflict(bool bDir, QString sNameSrc);


private slots:
    void  on_tableView_doubleClicked(const QModelIndex &index);
    void  on_listView_doubleClicked(const QModelIndex &index);
    void  onItemClicked(QTreeWidgetItem*,int);
    void on_tbList_clicked();
    void on_tbIcon_clicked();

    void on_tableView_customContextMenuRequested(const QPoint &pos);
    void on_listView_customContextMenuRequested(const QPoint &pos);

    void onActionOpen();
    void onActionCopy();
    void onActionCut();
    void onActionRename();
    void onActionNewDir();
    void onActionNewFile();

    void onActionPaste();
    void onCopyAndCutFinished();


    void onChooseCoverFileOrDir(bool bDir, QString sNameSrc);//选择是否覆盖冲突文件或文件夹
    void onActionDelete();
    void onDebug();
    void onBackBtn();
signals:
    void chooseCoverFinished(int bCover);

private:
     void customContextMenuRequested(const QPoint &pos, bool bListView);
private:
    Ui::Widget *ui;
    QTreeWidgetItem *m_pItem;

    QList<QTreeWidgetItem *>m_items;
    MyqFileModel *m_pFileModel;

    QStringList m_allPathList;
    QString m_sCurPath;     //当前路径
    QStringList m_sSourcePath;
    bool m_bViewState;               //当前右侧窗口是 列表视图 还是图标视图 true:列表 false:图标

    QPoint m_ptPress;
    int m_iActionState;
    int m_iOperation;
    QProgressBar* m_pProgressBar;
    FileThread* m_pThread;

    QStack<QString>stack;
    QStack<QString>stack1;

};

#endif // WIDGET_H
