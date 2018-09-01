#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLCDNumber>
#include<qradiobutton.h>
#include <QDesktopWidget>
#include<QTcpSocket>
#include<QTcpServer>
#include<QToolButton>
#include"result.h"
#include <QtSql>

#define TIMEOUT 60
#define TOTAL_MIN 3

#define no_of_option 5






namespace Ui {
class MainWindow;
//class DigitalClock;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
void update_qa();
void run_timer();
void create_toolbutton();
private slots:
    void updateTime();
    //void read_qno();
    void print_sec();
void text_edit();
void itwasclicked();
void push_button();
//void on_pushButton_clicked();

void on_radioButton_1_clicked();

void on_radioButton_3_clicked();

void on_radioButton_2_clicked();

void on_radioButton_4_clicked();

 char *radio_button(char * arr ,char * ch);
int openfile(int text_edit,int qa_no);



void on_pushButton_2_clicked();
void on_pushButton_3_clicked();
void someSlot() ;
int store_answers_to_file();
void print_attended_question(int attended_question);
void on_pushButton_4_clicked();


void on_pushButton_13_clicked();

void on_pushButton_11_clicked();

void on_radioButton_5_clicked();

void on_pushButton_clicked();

void on_pushButton_5_clicked();

void on_pushButton_7_clicked();

void on_pushButton_8_clicked();

void on_pushButton_6_clicked();
signals:
     void valueChanged(double Reasoning_marks,double data_analysis_marks,double gk_marks,double english_marks);
private:
    Ui::MainWindow *ui;
   Result * Result_window;
    //Form form;
};
class student
{

public:
    QString student_username;
    QString password;
~student();

};
class answers
{

public:
    int question_no;
    char answer;
 QToolButton * q_object;
 bool checked;\
 bool answer_saved;
 bool review_next;
 void create_objects();
 ~answers();

};

class db_manage :public  QSqlDatabase
{
public:
  explicit db_manage(int question_paper_clicked,QString type_database);
QString path;
QSqlQuery *query;
QSqlDatabase *question_table;
  QSqlDatabase  question_table_;
~db_manage();
};

#endif // MAINWINDOW_H
