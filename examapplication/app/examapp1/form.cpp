#include "form.h"
#include "ui_form.h"
#include"mainwindow.h"
#include<QDebug>
#include<QString>
#include<qmessagebox.h>
#include<QTime>
QString IntToQstring(int source) ;
QTime systemtime;
extern Client * socket_client;
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
    this->setFixedSize(x,y);
    //ui->label->setStyleSheet("background-color: yellow;border: 2px solid blue");
   // ui->label->setStyleSheet("border:  red");
    ui->pushButton->setStyleSheet("color: green");
  //  ui->lineEdit->setStyleSheet("background-color: yellow;border: 2px solid blue");
   // ui->lineEdit_2->setStyleSheet("background-color: yellow;border: 2px solid blue");
   // setWindowFlags(Qt::Window|Qt::WindowMaximizeButtonHint);

   // this->setWindowIcon(QIcon("/home/user/examapp1/icon.jpg"));
   // this->setStyleSheet("{background-image: (:/home/user/examapp1/icon.jpg);}");

#if 1
        QPixmap bkgnd(":/new/prefix1/icon2.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

#endif
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

void Form::on_pushButton_clicked()
{
    QTime  curenttime;
    QString ip_addr;
    QString port_no;

       //client
       socket_client=new Client(this);
     //  connect(socket_client, SIGNAL(dataReceived(QByteArray)), SLOT(Print_data(QByteArray)));
   //   qDebug()<<"username is:"<<username;
   //   student1->student_username="divakar";
   //   student1->password="123";
   //   QString user="divakar",pwd="123";
       ip_addr=ui->lineEdit_6->text();
       port_no=ui->lineEdit_7->text();
       strcpy(IP_ADDR,ip_addr.toLatin1());
       PORT_NO=port_no.toInt();
       username = ui->lineEdit_2->text();
       password = ui->lineEdit->text();
       USN_NO=ui->lineEdit_4->text();
       NAME=ui->lineEdit_3->text();
       EMAIL_ID=ui->lineEdit_5->text();
      //creating data packet
      QString data_packet;
      int username_len=username.length();
      int pwd_len=password.length();
      int usn_len=USN_NO.length();
      int name_len=NAME.length();
      int email_id_len=EMAIL_ID.length();
      if(usn_len>20  )
      {
          QMessageBox::information(
              this,
              tr("error!!"),
              tr("usn lenght is larger should be less than 20") );

      }
      if( name_len>20)
      {

          QMessageBox::information(
              this,
              tr("error!!"),
              tr("name  lenght is larger should be less than 20") );


      }
      if(   username_len>20)
      {

          QMessageBox::information(
              this,
              tr("error!!"),
              tr("username  lenght is larger should be less than 20") );


      }

      if(email_id_len>50)
      {

          QMessageBox::information(
              this,
              tr("error!!"),
              tr("email id is very long") );

      }
      QString user_len_array= IntToQstring( username_len);
       QString pwd_len_array= IntToQstring(pwd_len);
        QString usn_len_array= IntToQstring(usn_len);
        QString name_len_array= IntToQstring(name_len);
        QString emailid_len_array= IntToQstring(email_id_len);
data_packet="1";
int data_sent_len=socket_client->write_to_server(data_packet);
if(data_sent_len!=data_packet.length())
{

    if(data_sent_len==false)
    {

           QMessageBox::information(
                this,
                tr("error!!"),
                tr("invalid server IP/port") );
            goto exit;

    }

    else
       QMessageBox::information(
            this,
            tr("error!!"),
            tr("server is not ready ") );
        goto exit;

}

socket_client->wait_for_readyread(-1);
if(buffer_read!="ok")
{
    QMessageBox::information(
        this,
        tr("error!!"),
        tr("connection error") );
    goto exit;
}
 //socket_client->write_to_server("ok");
      data_packet="x"+user_len_array+pwd_len_array+usn_len_array+name_len_array+emailid_len_array+username+password+USN_NO+NAME+EMAIL_ID;
      //send to server
     socket_client->write_to_server(data_packet);

//     socket_client->wait_for_readyread(-1);
   //  if(buffer_read=="ok")
  //{
         socket_client->wait_for_readyread(-1);

     if(buffer_read=="true")
   {

           w=new MainWindow();
           w->show();
           this->close();
                      curenttime=systemtime.currentTime();
    }

     else
     {
          socket_client->write_to_server("terminate");
         QMessageBox::information(
             this,
             tr("error!!"),
             tr("password or the username is incorrect") );
     }

 // }
//      else
//      {
//                 QMessageBox::information(
//                     this,
//                     tr("error!!"),
//                     tr("connection error_2") );

//      }

exit:;
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
