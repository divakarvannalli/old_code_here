#-------------------------------------------------
#
# Project created by QtCreator 2017-04-12T16:53:00
#
#-------------------------------------------------

QT       += core gui
QT        += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = examapp1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp

HEADERS  += mainwindow.h \
    form.h

FORMS    += mainwindow.ui \
    form.ui

OTHER_FILES +=

RESOURCES += \
    images.qrc
