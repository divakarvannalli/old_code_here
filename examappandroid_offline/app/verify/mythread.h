#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>


class MyThread : public QThread
{
    Q_OBJECT
    public:
        explicit MyThread(qintptr ID, QObject *parent = 0);
QString IntToArray(int source);
        void run();
        bool write_to_same_socket( QTcpSocket *,QString);
        void forced_quit_app();
     char*   quest_file_path_thread;
      char* options_file_path_thread;
       char* instruction_file_path_thread;
      char*  answer_file_path_thread;
       char* student_count;

       FILE *instruction_fptr;
       FILE *option_fptr;
       FILE *question_fptr;
       FILE *answer_fptr;

    signals:
        void error(QTcpSocket::SocketError socketerror);
        void dataReceived(QByteArray);

    public slots:
        void readyRead();
        void disconnected();
    private:
        QTcpSocket *socket;
        qintptr socketDescriptor;
bool verify_authenticity(QByteArray);
int  read_instruction();
int read_Question(QByteArray);
void  store_answer_to_file(QByteArray data);
int read_options(QByteArray Data);
bool read_response_from_client();
bool read_response_from_client_2();
bool read_response_to_client();
};

#endif // MYTHREAD_H
