#include "mainwindow.h"
#include <QApplication>
#include "mapwidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MapWidget map;
    map.show();

    return a.exec();
}
