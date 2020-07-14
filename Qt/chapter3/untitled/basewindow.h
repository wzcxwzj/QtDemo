#ifndef BASEWINDOW_H
#define BASEWINDOW_H


#include <QWidget>
#include <QFileInfo>
#include "mytitlebar.h"

class BaseWindow : public QWidget
{
    Q_OBJECT

public:
    BaseWindow(QWidget *parent = 0);
    ~BaseWindow();

private:
    void initTitleBar();
    void paintEvent(QPaintEvent *event);
    void loadStyleSheet(const QString &sheetName);
signals:
    void advanceModelIndex();

private slots:
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();
    void onButtonAdvanceClicked();
    void onButtonBackClicked(QModelIndex);
protected:
    MyTitleBar* m_titleBar;

public:

    QFileInfo info;

};

#endif // BASEWINDOW_H
