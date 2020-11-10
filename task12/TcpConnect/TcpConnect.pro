#-------------------------------------------------
#
# Project created by QtCreator 2018-12-04T16:16:42
#
#-------------------------------------------------

QT       += core gui
QT       +=  network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpConnect
TEMPLATE = app


SOURCES += main.cpp\
    ClientWidget.cpp\

HEADERS  += ClientWidget.h \


FORMS    += ClientWidget.ui \

CONFIG +=C++11
