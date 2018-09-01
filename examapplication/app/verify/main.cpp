#include "mainwindow.h"
#include <QApplication>
#include"myserver.h"

MyServer *server;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

