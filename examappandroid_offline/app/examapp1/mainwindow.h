#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLCDNumber>
#include<qradiobutton.h>
#include <QDesktopWidget>
#include<QTcpSocket>
#include<QTcpServer>
#include<QToolButton>
#define  no_of_questions 60

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
private slots:
    void updateTime();
    //void read_qno();
    void print_sec();
void text_edit();
void itwasclicked();
void push_button();
void on_pushButton_clicked();

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

bool read_response_from_server();
bool read_response_to_server();
private:
    Ui::MainWindow *ui;

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
 bool checked;
 void create_objects();
 ~answers();

};


//client
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
//bool read_same_socket();
bool write_to_server(QString data);
bool wait_for_readyread(int );
signals:
void dataReceived(QByteArray);
void dataReceived(bool);
bool wait_for_response(int);
public slots:
    bool connectToHost(QString host);
    bool writeData(QByteArray data);
    //void readyRead_temp();
    void disconnected();
private:
    QTcpSocket *socket;
};

//class DigitalClock : public QLCDNumber
//{
//    Q_OBJECT

//public:
//    DigitalClock(QWidget *parent = 0);

//private slots:
//    void showTime();
//};

#endif // MAINWINDOW_H
