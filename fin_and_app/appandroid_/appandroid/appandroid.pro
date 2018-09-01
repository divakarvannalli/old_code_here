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
QT += sql


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp \
    result.cpp

HEADERS  += mainwindow.h \
    form.h \
    result.h \
    common.h

FORMS    += mainwindow.ui \
    form.ui \
    result.ui


RESOURCES += \
    resources.qrc
addFiles.source =/home/user/appandroid/questions/question_table1.db
OTHER_FILES += \
    questions/question_table1

