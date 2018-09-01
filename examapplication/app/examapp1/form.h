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
void on_pushButton_clicked();
private:
    Ui::Form *ui;
    MainWindow *w;


};




#endif // FORM_H
