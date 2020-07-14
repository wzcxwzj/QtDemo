#include "mainwindow.h"
#include <QItemSelectionModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//     createAction();
//     createMenu();
//     setupModel();
     setupView();
     setWindowTitle("View Example");
     resize(600,600);
}

MainWindow::~MainWindow()
{

}

void MainWindow::setupView()
{
    splitter=new QSplitter;
    splitter->setOrientation(Qt::Vertical);
   // histogram=new HistogramView();
   // histogram->setModel(model);
}
