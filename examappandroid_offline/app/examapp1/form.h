#ifndef FORM_H
#define FORM_H
#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();


private slots:
  //  void Print_data(QByteArray d);
//void Print_data(bool d);
void select_qpaper();
private:
    Ui::Form *ui;
    MainWindow *w;

};

class question
{

public:
    int questionpaper_no;
    char answer;
    bool seen;
 QToolButton * q_object;
 bool checked;
 void create_objects();
 ~question();

};


#endif // FORM_H
