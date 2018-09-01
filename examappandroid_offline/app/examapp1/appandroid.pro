#-------------------------------------------------
#
# Project created by QtCreator 2017-06-14T13:37:11
#
#-------------------------------------------------

QT       += core gui
QT        += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = appandroid
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp

HEADERS  += mainwindow.h \
    form.h

FORMS    += mainwindow.ui \
    form.ui


RESOURCES += \
    ../examapp1/images/red.qrc

