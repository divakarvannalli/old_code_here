
#include <QApplication>
#include"form.h"
#include<ui_form.h>
#include<QDebug>
bool checked;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 Form *f1=new Form();
    f1->show();

qDebug()<<"username is:";




    return a.exec();
}

