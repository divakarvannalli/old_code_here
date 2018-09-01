#include "form.h"
#include "ui_form.h"
//#include"mainwindow.h"
#include<QDebug>
#include<QString>
#include<qmessagebox.h>
#include<QTime>
#include <qpushbutton.h>

#define total_Q_paper 10
int question_paper_clicked;
question question_paper[total_Q_paper] ;


QString IntToQstring(int source) ;
QTime systemtime;
//extern Client * socket_client;
QByteArray buffer_read;
bool buffer_read_bool;
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setWindowTitle("login window");
    QDesktopWidget dw;
    int x=dw.width()*1;
    int y=dw.height()*1;
    char *sptr=(char *)malloc(20);

//    ui->frame->move(QApplication::desktop()->screen()->rect().center() - ui->frame->rect().center());
x=320;
y=220;int w,z;
x=QApplication::desktop()->screen()->rect().left();
y=QApplication::desktop()->screen()->rect().top();
w=QApplication::desktop()->screen()->rect().right();
z=QApplication::desktop()->screen()->rect().bottom();
int i;
    for( i=0;i<total_Q_paper;i++)
    {
     question_paper[i].q_object = new QToolButton(this);
     question_paper[i].q_object->setCheckable(true);
     if(i%3== 0 )
     {
         x=x+200;y=150;

     }
     question_paper[i].q_object->setGeometry(x,y,w,z);
     question_paper[i].q_object->setFixedSize(150,100);
     question_paper[i].q_object->setCheckable(true);
     y=y+200;

         sprintf(sptr,"MOCK TEST %d",i+1);
          question_paper[i].q_object->setText(sptr);

          connect(question_paper[i].q_object, SIGNAL(clicked(bool)), this, SLOT(select_qpaper()));
    }

//for( i=0;i<total_Q_paper;i++)
{

 // question_paper[i].q_object->move(QApplication::desktop()->screen()->rect().center() -  question_paper[i].q_object->rect().center());

}

free(sptr);

}
question::~question()
{

}
Form::~Form()
{
    delete ui;
}
char IP_ADDR[50];
int PORT_NO;
QString USN_NO;
QString NAME;
QString EMAIL_ID;
QString username;
QString password;

void Form::select_qpaper()
{
//    QString ip_addr;
//    QString port_no;

     //  Client socket_client=new Client(this);
     //  connect(socket_client, SIGNAL(dataReceived(QByteArray)), SLOT(Print_data(QByteArray)));
   //   qDebug()<<"username is:"<<username;
   //   student1->student_username="divakar";
   //   student1->password="123";
   //   QString user="divakar",pwd="123";
//       ip_addr=ui->lineEdit_6->text();
//       port_no=ui->lineEdit_7->text();
//       strcpy(IP_ADDR,ip_addr.toLatin1());
//       PORT_NO=port_no.toInt();
//       username = ui->lineEdit_2->text();
//       password = ui->lineEdit->text();
//       USN_NO=ui->lineEdit_4->text();
//       NAME=ui->lineEdit_3->text();
//       EMAIL_ID=ui->lineEdit_5->text();
      //creating data packet
//      QString data_packet;
//      int username_len=username.length();
//      int pwd_len=password.length();
//      int usn_len=USN_NO.length();
//      int name_len=NAME.length();
//      int email_id_len=EMAIL_ID.length();
//      if(usn_len>20  )
//      {
//          QMessageBox::information(
//              this,
//              tr("error!!"),
//              tr("usn lenght is larger should be less than 20") );

//      }
//      if( name_len>20)
//      {

//          QMessageBox::information(
//              this,
//              tr("error!!"),
//              tr("name  lenght is larger should be less than 20") );


//      }
//      if(   username_len>20)
//      {

//          QMessageBox::information(
//              this,
//              tr("error!!"),
//              tr("username  lenght is larger should be less than 20") );


//      }

//      if(email_id_len>50)
//      {

//          QMessageBox::information(
//              this,
//              tr("error!!"),
//              tr("email id is very long") );

//      }
//      QString user_len_array= IntToQstring( username_len);
//       QString pwd_len_array= IntToQstring(pwd_len);
//        QString usn_len_array= IntToQstring(usn_len);
//        QString name_len_array= IntToQstring(name_len);
//        QString emailid_len_array= IntToQstring(email_id_len);
//data_packet="1";
//int data_sent_len=socket_client->write_to_server(data_packet);
//if(data_sent_len!=data_packet.length())
//{

//    if(data_sent_len==false)
//    {

//           QMessageBox::information(
//                this,
//                tr("error!!"),
//                tr("invalid server IP/port") );
//            goto exit;

//    }

//    else
//       QMessageBox::information(
//            this,
//            tr("error!!"),
//            tr("server is not ready ") );
//        goto exit;

//}

//socket_client->wait_for_readyread(-1);
//if(buffer_read!="ok")
//{
//    QMessageBox::information(
//        this,
//        tr("error!!"),
//        tr("connection error") );
//    goto exit;
//}
// //socket_client->write_to_server("ok");
//      data_packet="x"+user_len_array+pwd_len_array+usn_len_array+name_len_array+emailid_len_array+username+password+USN_NO+NAME+EMAIL_ID;
//      //send to server
//     socket_client->write_to_server(data_packet);

////     socket_client->wait_for_readyread(-1);
//   //  if(buffer_read=="ok")
//  //{
//         socket_client->wait_for_readyread(-1);

//     if(buffer_read=="true")
   //{


    for(int i=0;i<total_Q_paper;i++)
    {


   if( question_paper[i].q_object->isChecked())
   {
    question_paper_clicked=i+1;
    question_paper[i].q_object->setChecked(false);
    break;
   }

    }
//     question_paper[question_paper_clicked-1].q_object->setStyleSheet("background-color: rgb(85, 170, 0);");
//      question_paper[question_paper_clicked-1].seen=true;
     w=new MainWindow();
           w->show();
        //   this->close();

 //   }

//     else
//     {
//          socket_client->write_to_server("terminate");
//         QMessageBox::information(
//             this,
//             tr("error!!"),
//             tr("password or the username is incorrect") );
//     }

 // }
//      else
//      {
//                 QMessageBox::information(
//                     this,
//                     tr("error!!"),
//                     tr("connection error_2") );

//      }

//exit:;
}




QString IntToQstring(int source) //Use qint32 to ensure that the number have 4 bytes
{
      QString s;
    //Avoid use of cast, this is the Qt way to serialize objects
    if(source>9)
  s = QString::number(source);
    else
    {
        s = QString::number(source);
        s="0"+s;

    }
    return s;
}
