#ifndef IMGPROCESSOR_H
#define IMGPROCESSOR_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>

class ImgProcessor : public QMainWindow
{
    Q_OBJECT

public:
    ImgProcessor(QWidget *parent = 0);
    ~ImgProcessor();

    void createAction();    //创建动作
    void createMenus();     //创建菜单
    void createToolBar();   //创建工具栏

private:
    QMenu *fileMenu;
    QMenu *zoomMenu;
    QMenu *rotateMenu;

    QToolBar *fileTool;

    QAction *openFileAction;
    QAction *NewFileAction;
    QAction *printTextAction;

    QAction *zoomInAction;      //缩放
    QAction *zoomOutAction;     //缩小
    QAction *rotate90Action;    //旋转90
    QAction *rotate180Action;    //旋转90
    QAction *rotate270Action;    //旋转90
    QAction *mirrorVerticalAction;       //横向镜像
    QAction *mirrorHorizontalAtion;       //纵向镜像

protected slots:
    void ShowZoomIn();      //实现缩放
    void ShowRotate90();    //实现旋转
    void ShowRotate180();    //实现旋转
    void ShowRotate270();    //实现旋转

};

#endif // IMGPROCESSOR_H
