#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mythread.h"

#include <errno.h>
#include <sys/stat.h>
#include<QFileDialog>
#include<QDebug>
#include<QDesktopWidget>
#include<QMessageBox>
#include<QString>
#include<QSharedMemory>
#include<sys/sendfile.h>
#include"myserver.h"

FILE *fptr1=NULL;
FILE *fptr2=NULL;
FILE *fptr3=NULL;
QSharedMemory qsharedmem;
#define  no_of_questions 60
unsigned int time_duration;
unsigned int total_no_of_questions;
unsigned int total_no_of_stduents;
extern MyServer *server;

//const char *candidates_answer_sheet;
//const char* answer_sheet;
int total_candidate=10;
//const char* result_file;
char* string;
student_database * student[100];//max limit can be changed

QString qstring_candidates_answers_dir;
QString qstring_candidates_results_dir;
 char * candidates_answer_dir;
 char * candidates_result_dir;
 char * answer_file;

bool push_button_clicked=false;


 char * quest_file_path;
 char * options_file_path;
 char * instruction_file_path;
 char * answer_file_path;


QString qstring_time_duration;
QString qstring_total_no_of_questions;
QString qstring_total_no_of_stduents;
QString qstring_quest_file_path;
QString qstring_options_file_path;
QString qstring_instruction_file_path;
QString qstring_answer_file_path;
QString qstring_port_no;

int port_no_to_connect;
//server-----------------------------------------------------------------
  //Server* server_r;
 // QTcpSocket *socketZ;
//  static inline qint32 ArrayToInt(QByteArray source);
//  static inline QByteArray IntToArray(qint32 source);


//  Server::Server(QObject *parent) : QObject(parent)
//  {
//      server = new QTcpServer();
//      connect(server, SIGNAL(newConnection()), SLOT(newConnection()));

//      qDebug() << "Listening:" << server->listen(QHostAddress::Any, 5006);
//  }

//  void Server::newConnection()
//  {
//      while (server->hasPendingConnections())
//      {

//          QTcpSocket *socket = server->nextPendingConnection();
//          connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
//          connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
//          QByteArray *buffer = new QByteArray();
//          qint32 *s = new qint32(0);
//          buffers.insert(socket, buffer);
//          sizes.insert(socket, s);
//      }
//  }

//  void Server::disconnected()
//  {
//      QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
//     QByteArray *buffer = buffers.value(socket);
//      qint32 *s = sizes.value(socket);
//      socket->deleteLater();
//      delete buffer;
//      delete s;
//  }

//  void Server::readyRead()
//  {
//      QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
//      QByteArray *buffer = buffers.value(socket);
//      qint32 *s = sizes.value(socket);
//      qint32 size = *s;
//socketZ=socket;
//      while (socket->bytesAvailable() > 0)
//      {
//          buffer->append(socket->readAll());
//          while ((size == 0 && buffer->size() >= 4) || (size > 0 && buffer->size() >= size)) //While can process data, process it
//          {
//              if (size == 0 && buffer->size() >= 4) //if size of data has received completely, then store it on our global variable
//              {
//                  size = ArrayToInt(buffer->mid(0, 4));
//                  *s = size;
//                  buffer->remove(0, 4);
//              }
//              if (size > 0 && buffer->size() >= size) // If data has received completely, then emit our SIGNAL with the data
//              {
//                  QByteArray data = buffer->mid(0, size);
//                  buffer->remove(0, size);
//                  size = 0;
//                  *s = size;
//                  emit dataReceived(data);

//              }
//          }
//      }
//  }

//  qint32 ArrayToInt(QByteArray source)
//  {
//      qint32 temp;
//      QDataStream data(&source, QIODevice::ReadWrite);
//      data >> temp;
//      return temp;
//  }

//  QByteArray IntToArray(qint32 source) //Use qint32 to ensure that the number have 4 bytes
//  {
//      //Avoid use of cast, this is the Qt way to serialize objects
//      QByteArray temp;
//      QDataStream data(&temp, QIODevice::ReadWrite);
//      data << source;
//      return temp;
//  }

// bool Server::write_to_same_socket( QTcpSocket *socket,QString data)
//  {
 // QByteArray data = "hiiiiiii";
//      if(socket->state() == QAbstractSocket::ConnectedState)
//      {
//          //conversion error here
//          int k=data.size();
//          QByteArray z=IntToArray(k);
//          socket->write(z); //write size of data
//          socket->write(data.toLatin1()); //write the data itself
//          return socket->waitForBytesWritten();
//      }
//      else
//          return false;


//  }

//-------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("setting exam and verify answers");

    QDesktopWidget mw;
    int x=mw.width()*.7;
    int y=mw.height()*.7;
    this->setFixedSize(x,y);

   candidates_answer_dir= (char *)malloc(100);
    candidates_result_dir= (char *)malloc(100);
    answer_file= ( char *)malloc(100);
  string= (char*)malloc(100);


  quest_file_path= (char *)malloc(100);
   options_file_path= (char *)malloc(100);
   instruction_file_path= ( char *)malloc(100);
answer_file_path=( char *)malloc(100);

connect(this, SIGNAL(forced_quit_app()), SLOT(forced_quit_app_slot()));
//server

//server_r=new Server();
//connect(server_r, SIGNAL(dataReceived(QByteArray)), SLOT(Print_data(QByteArray)));




//connect(ui->pushButton_2,SIGNAL(clicked()), SLOT(write_to_shared_mem()));
}

//void MainWindow::Print_data(QByteArray d)
//{
//QString text;
//qDebug()<<"recieved data"<<d;
//if(d=="divakar" || d=="123")
//{
// text="ok";
// server_r->write_to_same_socket(socketZ,text);
//}
//else
//  text="fail";
//}

MainWindow::~MainWindow()
{

    free((char *)candidates_answer_dir);
    free((char *)candidates_result_dir);
    free((char *)answer_file);
    free((char *)string);


    free((char *)quest_file_path);
    free((char *)options_file_path);
    free((char *)instruction_file_path);
    free((char *)answer_file_path);
    emit forced_quit_app();
    delete ui;

}

void MainWindow::forced_quit_app_slot()
{
    if(server)
  server->forced_quit_app();
    else
      ;
}


int MainWindow::check_directries()
{
 int status;
QByteArray qbyte;
QByteArray qbyte2;

struct stat st_buf,st_buf_2;


//check for answer folder

qbyte=qstring_candidates_answers_dir.toLatin1();
candidates_answer_dir = qbyte.data();
status = stat (candidates_answer_dir, &st_buf);
   if (status != 0) {
       qDebug()<<"Error, errno = %d\n"<<errno;
       return -1;
   }

   if (S_ISDIR (st_buf.st_mode)) {
         qDebug()<<candidates_answer_dir<<"%s is a directory.\n";
     }
else
   {
          return -1;
   }

  //check for result folder

   qbyte=qstring_candidates_results_dir.toLatin1();
   candidates_result_dir = qbyte.data();
   status = stat (candidates_result_dir, &st_buf_2);
      if (status != 0) {
          qDebug()<<"Error, errno = %d\n"<<errno;
          return -1;
      }

      if (S_ISDIR (st_buf_2.st_mode)) {
            qDebug()<<candidates_result_dir<<"is a directory.\n";
        }
   else
      {
             return -1;
      }



}
void MainWindow::on_pushButton_5_clicked()
{
    QByteArray qbyte;
 int status = MainWindow::check_directries();

 if( (status<0) || (fptr2==NULL) )
 {
    if(status<0)
    {
     QMessageBox::information(
                     this,
                     tr("warning"),
                     tr("load the proper directory") );
    }

    if( ( fptr2==NULL))
    {

        QMessageBox::information(
                        this,
                        tr("warning"),
                        tr("load the proper answer file") );
    }
 }


    else
 {
for(int i=1;i<=total_candidate;i++)
{
    QString num;
    QString temp_answer_dir;
     QString temp_result_dir;
    num.sprintf("/student%d.txt",i);
    temp_result_dir=qstring_candidates_answers_dir;
    temp_result_dir=qstring_candidates_answers_dir+num;

    qbyte=temp_result_dir.toLatin1();
    candidates_answer_dir = qbyte.data();
    qDebug()<<"candidates_answer_dir  "<<candidates_answer_dir;
fptr1 = fopen(candidates_answer_dir, "r");
if(fptr1 == NULL)
   {
     qDebug()<<"candidates_answers_sheet failed to open";
     exit(1);
   }


if(fptr1 != NULL && fptr2!=NULL)
{
  unsigned  int currect_answers=0;
 unsigned   int wrong_answers=0;
 unsigned   int not_answered=0;

 num.sprintf("/student%d_result.txt",i);
 temp_result_dir=qstring_candidates_results_dir+num;

 qbyte=temp_result_dir.toLatin1();
 candidates_result_dir = qbyte.data();

 fptr3 = fopen(candidates_result_dir, "w");
if(fptr3 == NULL)
{
qDebug()<<"candidates_result_dir failed to open";
exit(1);


}



        char line1 [5]={0};
        char line2 [5]={0};

        while((fgets(line1, sizeof line1, fptr1) !=NULL ) && ( fgets(line2, sizeof line2, fptr2) !=NULL ) )
        {
            if(line1[0]==line2[0])
                currect_answers++;
            else if(line1[0] == 'e')
                not_answered++;
            else
               wrong_answers++ ;
        }
        qDebug()<<"currect_answers value "<<currect_answers;
        qDebug()<<"wrong_answers   value "<<wrong_answers;
        qDebug()<<"not_answered    value "<<not_answered;

    fputs("--------------------------result-----------------------------------------\n",fptr3);
        sprintf(string,"currect answers--------->  %d\n",currect_answers);
        fputs(string,fptr3);
qDebug()<<"----------"<<string;
        sprintf(string,"wrong   answers--------->  %d\n",wrong_answers);
        fputs(string,fptr3);
        qDebug()<<"----------"<<string;
        sprintf(string,"not    answered--------->  %d\n",not_answered);
        fputs(string,fptr3);
        qDebug()<<"----------"<<string;



         fclose(fptr1);
         fclose(fptr2);
         fclose(fptr3);
    fptr1=NULL;
    fptr3=NULL;

     QString m = ui->lineEdit_1->text();
      QByteArray qbyte;
      qbyte=m.toLatin1();
        answer_file = qbyte.data();
       qDebug()<<"------answer_sheet----"<<answer_file;
       fptr2 = fopen(answer_file, "r");

    }

}

}

}





#if 0

void MainWindow::on_pushButton_released()
{
    if(fptr1 != NULL)
        fclose(fptr1);


    QByteArray qbyte;

        QString fileName;

    fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open candidates answer file"), "/home/", tr(" text files(*.txt )"));
    ui->lineEdit->setText(fileName);
    qbyte=fileName.toLatin1();
    candidates_answer_sheet = qbyte.data();

     qDebug()<<"candidates_answer_sheet path---"<<candidates_answer_sheet;
    fptr1 = fopen(candidates_answer_sheet, "r");
    if(fptr1 == NULL)
       {
          qDebug()<<"candidates_answer_sheet file failed";
          QMessageBox::information(
                          this,
                          tr("file"),
                          tr("load the proper file") );
          ui->lineEdit->setText("please load the proper file");
       }


}

#endif


void MainWindow::on_lineEdit_2_editingFinished()
{
#if 0
    QByteArray qbyte;
    QString fileName;
//    fileName = QFileDialog::getOpenFileName(this,
//                                            tr("Open answer file"), "/home/", tr(" text files(*.txt )"));

//    ui->lineEdit_2->setText(fileName);
    fileName=ui->lineEdit_2->text();
    qbyte=fileName.toLatin1();
    result_file = qbyte.data();
    qDebug()<<"result_file path---"<<result_file;
    fptr3 = fopen(result_file, "w");
    if(fptr3 == NULL)
       {
         qDebug()<<"result_file failed ";
         QMessageBox::information(
                         this,
                         tr("file"),
                         tr("on_pushButton_2_releasedload the proper file") );
      ui->lineEdit_2->setText("please load the proper file");
       }
#endif
             qstring_candidates_results_dir=ui->lineEdit_2->text();
}
#if 0
void MainWindow::on_lineEdit_1_editingFinished()
{
//    if(fptr2 != NULL)
//        fclose(fptr2);

    QByteArray qbyte;
    QString fileName;
//    fileName = QFileDialog::getOpenFileName(this,
//                                            tr("Open answer file"), "/home/", tr(" text files(*.txt )"));

   fileName = ui->lineEdit_1->text();
    qbyte=fileName.toLatin1();
   answer_sheet = qbyte.data();
    qDebug()<<"answer_sheet path---"<<answer_sheet;
    fptr2 = fopen(answer_sheet, "r");
    qDebug()<<"answer_sheet path---"<<answer_sheet;
    if(fptr2 == NULL)
       {
         qDebug()<<"answer_sheet failed to open";
          ui->lineEdit_1->setText("please load the proper file");
       }
}
#endif
void MainWindow::on_lineEdit_editingFinished()
{
    qstring_candidates_answers_dir=ui->lineEdit->text();
}


void MainWindow::on_pushButton_3_released()
{
    QByteArray qbyte;
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open answer file"), "/home/", tr(" text files(*.txt )"));

    ui->lineEdit_1->setText(fileName);
    fileName=ui->lineEdit_1->text();
    qbyte=fileName.toLatin1();
    answer_file = qbyte.data();
    qDebug()<<"result_file path---"<<answer_file;
    fptr2 = fopen(answer_file, "r");
    if(fptr2 == NULL)
       {
         qDebug()<<"answer_file failed ";

       }
}


QByteArray qbyte1;
QByteArray qbyte2;
QByteArray qbyte3;
QByteArray qbyte4;


//void MainWindow::send_fail_connection_to_client()
//{

//qDebug()<<"inside  slot";
//}

void MainWindow::on_pushButton_2_clicked()
{
    push_button_clicked=true;
    qstring_port_no=ui->lineEdit_11->text();
    port_no_to_connect=qstring_port_no.toInt();

qstring_time_duration=ui->lineEdit_3->text();
qstring_total_no_of_questions=ui->lineEdit_4->text();
qstring_total_no_of_stduents=ui->lineEdit_5->text();
 qstring_quest_file_path=ui->lineEdit_8->text();
qstring_options_file_path=ui->lineEdit_6->text();
qstring_instruction_file_path=ui->lineEdit_7->text();
qstring_answer_file_path=ui->lineEdit_9->text();


    time_duration=qstring_time_duration.toUInt();
    total_no_of_questions=qstring_total_no_of_questions.toUInt();
    total_no_of_stduents=qstring_total_no_of_stduents.toUInt();

    qbyte1=qstring_quest_file_path.toLatin1();
    // quest_file_path=qbyte1.data();
strcpy(quest_file_path,qbyte1.data());
     qbyte2=qstring_options_file_path.toLatin1();
    // options_file_path=qbyte2.data();
strcpy(options_file_path,qbyte2.data());
     qbyte3=qstring_instruction_file_path.toLatin1();
   //  instruction_file_path=qbyte3.data();
     strcpy(instruction_file_path,qbyte3.data());


     qbyte4=qstring_answer_file_path.toLatin1();
    // answer_file_path=qbyte4.data();
 strcpy(answer_file_path,qbyte4.data());



 server=new MyServer();
 server->startServer();



qDebug()<<"inside ok pushbutton";
qDebug()<<"time_duration"<<time_duration;
qDebug()<<"total_no_of_questions"<<total_no_of_questions;
qDebug()<<"total_no_of_stduents"<<total_no_of_stduents;
qDebug()<<"quest_file_path"<<quest_file_path;
qDebug()<<"options_file_path"<<options_file_path;
qDebug()<<"instruction_file_path"<<instruction_file_path;
qDebug()<<"answer_file_path"<<answer_file_path;





}
