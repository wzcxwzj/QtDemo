//#include "widget.h"
#include <QApplication>
#include "dockwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DockWidget doc;
    doc.show();
//    Widget w;
//    w.show();

    return a.exec();
}
