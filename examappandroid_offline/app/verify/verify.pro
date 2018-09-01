#-------------------------------------------------
#
# Project created by QtCreator 2017-04-21T09:48:28
#
#-------------------------------------------------

QT       += core gui
QT        += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = verify
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myserver.cpp \
    mythread.cpp

HEADERS  += mainwindow.h \
    setexam_header.h \
    myserver.h \
    mythread.h

FORMS    += mainwindow.ui

OTHER_FILES +=
