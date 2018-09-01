#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include<stdio.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void forced_quit_app();
private slots:
void forced_quit_app_slot();
    void on_pushButton_5_clicked();

 //   void Print_data(QByteArray);



    void on_lineEdit_2_editingFinished();

//    void send_fail_connection_to_client();

    void on_lineEdit_editingFinished();

int check_directries();
    void on_pushButton_3_released();



    void on_pushButton_2_clicked();

   // void write_to_shared_mem();

private:
    Ui::MainWindow *ui;

};


//class Server :  public QObject
//{
//    Q_OBJECT
//public:
//    explicit Server(QObject *parent = 0);
//bool write_to_same_socket( QTcpSocket *,QString);
//signals:
//    void dataReceived(QByteArray);

//private slots:
//    void newConnection();
//    void disconnected();
//    void readyRead();
//private:
//    QTcpServer *server;
//    QHash<QTcpSocket*, QByteArray*> buffers; //We need a buffer to store data until block has completely received
//    QHash<QTcpSocket*, qint32*> sizes; //We need to store the size to verify if a block has received completely
//};

class student_database
{


private:
QString user_name;
QString password;
QTcpServer *server;
FILE * Answer_file;
QString name;
QString mail_id;
QString USN;

};

#endif // MAINWINDOW_H
