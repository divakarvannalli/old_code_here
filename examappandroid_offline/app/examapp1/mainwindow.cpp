
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"/home/user/verify/setexam_header.h"
#include <QTimer>
#include <QTime>
#include<QDebug>
#include<qtextedit.h>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/qprinter.h>
#include <QtGui/qpaintdevice.h>
#include <qpushbutton.h>
#include <QPalette>
#include<qmessagebox.h>
#include<qfont.h>
#include<QFontComboBox>
#include<QStringListModel>
#include<QListView>
#define TIMEOUT 60
#define TOTAL_MIN 3
//#define h 0
//#define m 1
//#define s 0
int semaphore;
bool push_button_clicked;
extern QByteArray buffer_read;
extern QString IntToQstring(int source);
extern char IP_ADDR[50];
extern int PORT_NO;
QTime currentTime;
char answer;
int question_no;
 answers* store_answers;
 int hour ;
 int minute ;
 int second;
 bool stop_sec_timer;
 bool signal_next_clicked;
static answers  q[no_of_questions];
//char * quest_file_path;
//char * option_file_path;
//char* instruction_file_path;
//char * answer_file_path;

char * quest_file_path;
char * options_file_path;
char * instruction_file_path;
char * answer_file_path;
//static Client * socket_client;
Client * socket_client;

QTimer * timer ;
QTimer * timer_sec;
//QTimer * timer_q;
 //FILE *fptr2;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("EXAM APP");
    QDesktopWidget dw;
    int x=dw.width()*1;
    int y=dw.height()*1;
    this->setFixedSize(x,y);
    setWindowFlags(Qt::Window|Qt::WindowMaximizeButtonHint);

// this->setStyleSheet("background-color: white;");

  /*  QPixmap bkgnd("/home/user/Pictures/l.jpeg");
         bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
         QPalette palette;
         palette.setBrush(QPalette::Background, bkgnd);
         this->setPalette(palette);
*/

//    quest_file_path=(char *)malloc(100);
//   option_file_path=(char *)malloc(100);
//  instruction_file_path=(char *)malloc(100);
//answer_file_path=(char *)malloc(100);
//  quest_file_path="/home/user/examapp1/question.txt";
//  option_file_path="/home/user/examapp1/options.txt";
//  instruction_file_path="/home/user/examapp1/instructions.txt";
answer_file_path="/home/user/examapp1/answer.txt";
quest_file_path="/home/user/examapp1/question.txt";
options_file_path="/home/user/examapp1/options.txt";
instruction_file_path="/home/user/examapp1/instructions.txt";
answer_file_path="/home/user/examapp1/answer.txt";
    qDebug()<<"quest_file_path"<<quest_file_path;
    qDebug()<<"options_file_path"<<options_file_path;
    qDebug()<<"instruction_file_path"<<instruction_file_path;
    qDebug()<<"answer_file_path"<<answer_file_path;
ui->lcdNumber->hide();
ui->lcdNumber_2->hide();
ui->radioButton_1->hide();
ui->radioButton_2->hide();
ui->radioButton_3->hide();
ui->radioButton_4->hide();
ui->label_2->hide();
ui->label_4->hide();
// font combo box
QStringList stringList;
stringList << "English" << "Hindi";
QStringListModel *mdl = new QStringListModel(stringList);

QFont comboFont("Arial",11,-1,true);
QListView *vw = new QListView;
vw->setFont(comboFont);

ui->fontComboBox->setModel(mdl);
ui->fontComboBox->setView(vw);



//QFont comboFont("Arial",16,-1,true);
//for(int i = 0; i< ui->comboBox->count(); i++)
//{
//    ui->fontComboBox->setItemData(i,QVariant(comboFont),Qt::FontRole);
//}
//ui->fontComboBox->setFont(comboFont);



ui->label_3->hide();
ui->textEdit->hide();
ui->label->hide();
ui->pushButton_3->hide();
ui->pushButton_4->hide();
ui->pushButton_2->hide();
ui->textEdit_2->hide();
ui->pushButton->setStyleSheet("color : 5px solid green");
// ui->textEdit_2->setStyleSheet("border: 5px solid red");
int i;
//int limit=no_of_questions/3;
x=10,y=10;
QFont font8;
font8.setPointSize(10);
font8.setBold(true);
font8.setWeight(50);
char *sptr=(char *)malloc(20);
for( i=0;i<60;i++)
{

q[i].q_object = new QToolButton(ui->scrollArea);
q[i].q_object->setCheckable(true);
if(i==15 || i==30 || i==45 )
{
    x=x+80;y=10;
}
q[i].q_object->setGeometry(QRect(x,y , 117, 22));
q[i].q_object->setFixedSize(50,50);
y=y+70;
// q[i].q_object->setObjectName(QStringLiteral("radiobuttion_"));
// q[i].q_object->addWidget(q[i]);
//  q[i].q_object->setFont(font8);
//   q[i].q_object->setAutoFillBackground(true);

//     q[i].q_object->raise();
    sprintf(sptr,"%d",i+1);
     q[i].q_object->setText(sptr);
  //   sprintf(sptr,"radiobuttonq_%d",i+1);
//q[i].q_object->setObjectName(sptr);
     connect(q[i].q_object, SIGNAL(clicked(bool)), this, SLOT(itwasclicked()));

}
free(sptr);
q[0].q_object->click();
question_no=1;
timer = new QTimer(this);
connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));

//timer_q = new QTimer(this);
//connect(timer_q, SIGNAL(timeout()), this, SLOT(read_qno()));

timer_sec=new QTimer(this);
connect(timer_sec, SIGNAL(timeout()), this, SLOT(print_sec()));

//FILE *fptr=NULL;
//instruction_file_path="/home/user/examapp1/instructions.txt";
//fptr = fopen(instruction_file_path, "r");
//if(fptr == NULL)
//{
//    qDebug()<<"not able to open instruction file";
//}

 //MainWindow::openfile(3,0);
// QString data_packet="2";
//write_to_server(data_packet);
//ui->textEdit_3->setStyleSheet("border: 5px solid red");
on_pushButton_clicked();
 store_answers = new answers();




}
//client--------------------------------------------
static inline QByteArray IntToArray(qint32 source);
static inline qint32 ArrayToInt(QByteArray source);

Client::Client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    //connect(socket, SIGNAL(readyRead()), SLOT(readyRead_temp()));
}
void Client::disconnected()
{

  qDebug()<<"disconnected";

}

bool Client::connectToHost(QString host)
{
    int port=PORT_NO;
    socket->connectToHost(host, port);
    return socket->waitForConnected();
}


bool Client::writeData(QByteArray data)
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        //conversion error here
//        int k=data.size();
//        QByteArray z=IntToArray(k);
//        socket->write(z); //write size of data
//        socket->write(data); //write the data itself
//        return socket->waitForBytesWritten();
         socket->write(data);
    }
    else
        return false;
}
QByteArray IntToArray(qint32 source) //Use qint32 to ensure that the number have 4 bytes
{
    //Avoid use of cast, this is the Qt way to serialize objects
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << source;
    return temp;
}

//void Client::readyRead_temp()
//{

//QByteArray d=  socket_client->socket->readAll();
//qDebug()<<d;
//    read_same_socket();
//}

//bool Client::read_same_socket()
//{
 /*QHash<QTcpSocket*, QByteArray*> buffers;
 QHash<QTcpSocket*, qint32*> sizes;
 QByteArray *buffer2 = new QByteArray();
 qint32 *s = new qint32(0);
 buffers.insert(socket, buffer2);
 sizes.insert(socket, s);
 QByteArray *buffer = buffers.value(socket);
   s = sizes.value(socket);
    qint32 size = *s;
    while (socket->bytesAvailable() > 0)
    {
        buffer->append(socket->readAll());
        while ((size == 0 && buffer->size() >= 4) || (size > 0 && buffer->size() >= size)) //While can process data, process it
        {
            if (size == 0 && buffer->size() >= 4) //if size of data has received completely, then store it on our global variable
            {
                size = ArrayToInt(buffer->mid(0, 4));
                *s = size;
                buffer->remove(0, 4);
            }
            if (size > 0 && buffer->size() >= size) // If data has received completely, then emit our SIGNAL with the data
            {
                QByteArray data = buffer->mid(0, size);
                buffer->remove(0, size);
                size = 0;
                *s = size;

                emit dataReceived(data);
              //  qDebug()<<data;


            }
        }
    }
*/
//QByteArray data=socket->readAll();
//emit dataReceived(data);
//}
qint32 ArrayToInt(QByteArray source)
{
    qint32 temp;
    QDataStream data(&source, QIODevice::ReadWrite);
    data >> temp;
    return temp;
}

bool Client::write_to_server(QString data)
{
            bool k=  socket_client->connectToHost(IP_ADDR);
            if(k==true)
        return socket_client->writeData(data.toLatin1());
            else
            return false;

}

bool Client::wait_for_readyread(int k)
{

    socket->waitForReadyRead(k);
    buffer_read=socket->readAll();
    return true;
}

//---------------------------------------------------------

void MainWindow::updateTime()
{

#ifdef realtime_clock
  QTime currentTime = QTime::currentTime();
  QString currentTimeText = currentTime.toString("hh:mm");
  if (currentTime.second() % 2 == 0) {
    currentTimeText[2] = ' ';
  }

  ui->lcdNumber->display(currentTimeText);



  QTime currentTime = QTime::currentTime();
   QString currentTimeText = currentTime.toString("hh:mm");
  ui->lcdNumber->display(currentTimeText);
#endif



//     static int time = (60*60*h + 60*m + s);


      // decrement counter

     /*else // re-start counter
     {
         time->start(1000);
     }*/

//        hour=0;
//        minute=time;
         currentTime.setHMS(hour,minute,0);
  QString     currentTimeText = currentTime.toString("hh:mm");
        ui->lcdNumber->display(currentTimeText);

//        if (time==0) // countdown has finished
//        {
//            QMessageBox::information(
//                this,
//                tr("expired"),
//                tr("your session expired!!") );
//           //  fclose(fptr2);
//            QApplication::quit();
//        }

//        time--;



        if(minute<=0 && hour>0)
        {
            hour--;
            minute=59;
        }
        else
        {
            if(hour==0 && (minute==0 || minute<0))
            {
                currentTimeText = currentTime.toString("00:00");
                ui->lcdNumber->display(currentTimeText);
                stop_sec_timer=true;
                QMessageBox::information(
                    this,
                    tr("expired"),
                    tr("your session expired!!") );
               //  fclose(fptr2);
             int k= store_answers_to_file();
             print_attended_question(k);
                QApplication::quit();
            }
        }
minute--;
}

void MainWindow::text_edit()
{

 delete ui;

}

MainWindow::~MainWindow()
{
    delete ui;
//    free(quest_file_path);
//    free(option_file_path);
//    free(instruction_file_path);
//    free(answer_file_path);
}

void MainWindow::push_button()

{
#if 0
      QLCDNumber  *lcdNumber= new QLCDNumber(this);
       QTimer *timer2 = new QTimer(this);



       lcdNumber->move(250,250);
       lcdNumber->setMinimumWidth(200);
       lcdNumber->setMinimumHeight(50);


    //   qDebug()<<"return value of connect:"<<connect(timer2, &QTimer::timeout, this, &MainWindow::updateTime);
   timer2->start(1000*60);
   abc.setHMS(1,0,0);
    QString currentTimeText = abc.toString("hh:mm");
      ui->lcdNumber->display(currentTimeText);

      QPlainTextEdit *plainTextEdit= new QPlainTextEdit();
 //  qDebug()<<"return value of connect:"<<connect(plainTextEdit, &QPlainTextEdit::cursorPositionChanged, this, &MainWindow::text_edit);



#endif

}


void MainWindow::on_pushButton_clicked()
{
push_button_clicked=true;
//FILE *fptr=NULL;
//char line[256];
ui->radioButton_1->show();
ui->radioButton_1->click();

ui->radioButton_2->show();

ui->radioButton_3->show();

ui->radioButton_4->show();
ui->textEdit_2->show();
ui->lcdNumber->show();
ui->lcdNumber_2->show();
//option_file_path="/home/user/examapp1/options.txt";
//fptr = fopen(option_file_path, "r");


ui->label_2->show();
ui->label->show();
ui->label_4->show();

ui->label_3->show();
ui->textEdit->show();
//quest_file_path="/home/user/examapp1/question.txt";
//fptr = fopen(quest_file_path, "r");
//if(fptr == NULL)
//{
//    qDebug()<<"not able to open question.txt";
//}
 MainWindow::openfile(1,0);

// fptr = fopen(options_file_path, "r");

// if(fptr == NULL)
// {
//     qDebug()<<"not able to open options.txt";
// }
  MainWindow::openfile(2,0);


 qDebug()<<"on_pushButton_clicked";

ui->pushButton_3->show();
//ui->pushButton_3->setStyleSheet("color: red");
ui->pushButton_4->show();
ui->pushButton_4->setStyleSheet("color: green");
ui->pushButton_2->show();
//ui->pushButton_2->setStyleSheet("color: green");
ui->pushButton->close();
ui->textEdit_3->close();

// ui->pushButton->setGeometry(QRect(290, 550, 99, 27));


 //run the timer

 hour = TOTAL_MIN/60;
 minute = TOTAL_MIN%60;
currentTime = QTime::currentTime();
 currentTime.setHMS(hour,minute,0);
 QString currentTimeText = currentTime.toString("hh:mm");
minute--;
ui->lcdNumber->display(currentTimeText);

second=59;
currentTimeText = currentTime.toString("00");
ui->lcdNumber_2->display(currentTimeText);

//char *string=(char*)malloc(4);
//sprintf(string,"%d ",second);
//currentTimeText = currentTime.toString(second);
//ui->lcdNumber_2->display(string);
//free(string);
 timer->start(1000*60);
//timer_q->start(100);
timer_sec->start(1000);
 //ui->lcdNumber->display(currentTimeText);

    QPalette p = ui->textEdit->palette();
      // p.setColor(QPalette::Base, Qt::darkYellow);
        ui->textEdit->setPalette(p);
       ui->textEdit->setStyleSheet("border: 4px solid blue");

     ui->textEdit->setStyleSheet("background: yellow");






        ui->label_2->setStyleSheet("color:green");
         ui->label_3->setStyleSheet("color:green");
         ui->label_4->setStyleSheet("color:green");
         ui->label_4->setStyleSheet("color:green");
          ui->label->setStyleSheet("color:green");
         ui->lcdNumber->setStyleSheet("background-color: white;color: blue;");
          ui->lcdNumber_2->setStyleSheet("background-color: white;color: blue;");
         ui->radioButton_2->setStyleSheet("background-color: white;color : black; ");
          ui->radioButton_3->setStyleSheet("background-color: white;color : black; ");
           ui->radioButton_4->setStyleSheet("background-color: white;color : black; ");
            ui->radioButton_1->setStyleSheet("background-color: white;color : black; ");


            qDebug()<<"at the end";
}



int MainWindow::openfile(int text_edit,int qa_no)
{

     char *ch;
     ch=(char*)malloc(256);

     int i=0;






     switch(text_edit)
     {
     case 1:  //questions
     {
         char line[256]={0};
         int count=0;
         int lineNumber=qa_no;


         QString data_packet;

         QString line_no=QString::number(lineNumber);

         //this is for questions
          data_packet="3";
          buffer_read="\0";
          socket_client->write_to_server(data_packet);

          //response from server side
          qDebug()<<"\n 552";
          socket_client->wait_for_readyread(-1);
          if(buffer_read!="ok")
          {
              exit(1);
          }

      //this is to send line no as qstring
          data_packet=line_no;
          buffer_read="\0";
          socket_client->write_to_server(data_packet);

          //response from server side

          socket_client->wait_for_readyread(-1);
          if(buffer_read!="ok")
          {

              exit(2);
          }
             socket_client->write_to_server("ok");

           socket_client->wait_for_readyread(-1);

           //question string
           QString packet=buffer_read;
           socket_client->write_to_server("ok");
           socket_client->wait_for_readyread(-1);
           if(buffer_read!="ok")
           {

               exit(1);
           }
           strcpy(line,packet.toLatin1());


         ui->textEdit->setText(QApplication::translate("MainWindow",line , 0));


                break;
}
     case 2:
         {
         char line[256]={0};
        char arr[4][15]={0};
       //  QString data_packet;
         bool ok=false;
        int lineNumber=qa_no;

//         QString line_no=IntToQstring(lineNumber);
//         int line_no_len=line_no.length();
//         QString line_no_len_qstring=IntToQstring(line_no_len);
//          data_packet="4"+line_no_len_qstring+line_no;
//          socket_client->write_to_server(data_packet);
//           socket_client->wait_for_readyread(10);


//           QString packet_len=buffer_read;
//           int len_to_read=packet_len.toInt(&ok,10);
//           if(ok!=true)
//               return -1;
//           buffer_read="\0";
//         data_packet="04";
//         data_packet=data_packet+"ok";
//         socket_client->write_to_server(data_packet);
//        socket_client->wait_for_readyread(10);
//           data_packet=buffer_read.mid(0,len_to_read);
//           strcpy(line,data_packet.toLatin1());

        QString data_packet;

        QString line_no=QString::number(lineNumber);

        //this is for questions
         data_packet="4";
         socket_client->write_to_server(data_packet);

         //response from server side
         qDebug()<<"\n 552";
         socket_client->wait_for_readyread(-1);
         if(buffer_read!="ok")
         {
             exit(1);
         }

     //this is to send line no as qstring
         data_packet=line_no;
         socket_client->write_to_server(data_packet);

         //response from server side

         socket_client->wait_for_readyread(-1);
         if(buffer_read!="ok")
         {

             exit(2);
         }
            socket_client->write_to_server("ok");

          socket_client->wait_for_readyread(-1);

          //question string
          QString packet=buffer_read;
          socket_client->write_to_server("ok");
          socket_client->wait_for_readyread(-1);
          if(buffer_read!="ok")
          {

              exit(1);
          }
          strcpy(line,packet.toLatin1());

                if(line[0] == '\n')
                {


                    ui->radioButton_1->setText(QApplication::translate("MainWindow",NULL , 0));
                    ui->radioButton_2->setText(QApplication::translate("MainWindow",NULL , 0));
                    ui->radioButton_3->setText(QApplication::translate("MainWindow",NULL , 0));
                    ui->radioButton_4->setText(QApplication::translate("MainWindow",NULL , 0));

                    break;

                }
//                qDebug()<<line[0];
//                qDebug()<<"count value"<<count;
//                qDebug()<<"line no "<<lineNumber;
        ch=MainWindow::radio_button(arr[0],line+2);


            ui->radioButton_2->setText(QApplication::translate("MainWindow",arr[0] , 0));


# if 1
   ch=  MainWindow::radio_button(arr[1],ch+1);

             ui->radioButton_1->setText(QApplication::translate("MainWindow",arr[1] , 0));


                 ch=  MainWindow::radio_button(arr[2],ch+1);
                    ui->radioButton_3->setText(QApplication::translate("MainWindow",arr[2] , 0));


                        ch=  MainWindow::radio_button(arr[3],ch+1);

                           ui->radioButton_4->setText(QApplication::translate("MainWindow",arr[3] , 0));
#endif


             break;


         }


     case 3:
          char *str,*instruction;
          str=(char*)malloc(500);
          instruction=str;
          QString data_packet="2";
         bool ok=false;
         socket_client->write_to_server(data_packet);
         socket_client->wait_for_readyread(-1);
   if(buffer_read=="ok")
  {
        buffer_read="\0";
        socket_client->write_to_server("ok");
        socket_client->wait_for_readyread(-1);
         while(buffer_read != "EOF")
         {
             //recieve length of packet
         QString packet=buffer_read;
          buffer_read="\0";
         int len_to_read=packet.toInt(&ok,10);
          if(ok!=true ||len_to_read<0)
           exit(-1);

          //response to server
          data_packet="ok";
          socket_client->write_to_server(data_packet);
         socket_client->wait_for_readyread(-1);

         packet=buffer_read;
         if(packet=="-1")
         {

          qDebug()<<"disconnected from server";
          exit(-1);
         }

          strcpy(str,packet.toLatin1());
         str=str+len_to_read;

         //response to server
         data_packet="ok";
         socket_client->write_to_server(data_packet);
        socket_client->wait_for_readyread(-1);
         }
         data_packet="ok";
         socket_client->write_to_server(data_packet);

   }
         ui->textEdit_3->setText(QApplication::translate("MainWindow",instruction, 0));
         free((char*)instruction);
         buffer_read="\0";

         break;
     }

   return 0;
}




char * MainWindow::radio_button(char * arr ,char * ch)
{


          int  i=0;


             while(ch[i]!=';')
             {

                 arr[i]=ch[i];
                 i++;

             }
             arr[i+1]='\0';
            ch=ch+i;

            return ch;
}


void MainWindow::on_radioButton_1_clicked()
{
    answer='a';

    qDebug()<<"answer is :"<<answer;
    semaphore=1;
}

void MainWindow::on_radioButton_2_clicked()
{
    answer='b';
     qDebug()<<"answer is :"<<answer;
     semaphore=1;
}

void MainWindow::on_radioButton_3_clicked()
{
    answer='c';
     qDebug()<<"answer is :"<<answer;
     semaphore=1;
}

void MainWindow::on_radioButton_4_clicked()
{
    answer='d';
     qDebug()<<"answer is :"<<answer;
     semaphore=1;
}


void MainWindow::on_pushButton_2_clicked()
{

/*if(fptr2 != NULL)
{
  fputc(answer,fptr2);

}*/
    if(answer)
    {
    q[question_no-1].question_no=question_no;
    q[question_no-1].answer=answer;
    qDebug()<<"q and a is :"<<question_no<<answer;
    answer=0;
    }
MainWindow::on_pushButton_4_clicked();
}

void answers::create_objects()
{

}



void MainWindow::on_pushButton_3_clicked()
{


MainWindow::someSlot() ;

}
void MainWindow::someSlot() {
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this, "Test", "Quit?",
                                QMessageBox::Yes|QMessageBox::No);
  if (reply == QMessageBox::Yes) {
    qDebug() << "Yes was clicked";
    // fclose(fptr2);
       int k= store_answers_to_file();
       print_attended_question(k);
    QApplication::quit();
  } else {
    qDebug() << "Yes was *not* clicked";
  }
}

void MainWindow::itwasclicked()
{
if(push_button_clicked)
{
    qDebug() << "radiobutton clicked";

    for(int i=0;i<no_of_questions;i++)
    {

   bool checked =false;
   //q[i].q_object->clicked(checked);
   if(q[i].q_object->isChecked())
   {
      // FILE *fptr=NULL;
       question_no=i+1;



       // fptr = fopen("/home/user/examapp1/question.txt", "r");
         MainWindow::openfile(1,i);
       //  fptr = fopen("/home/user/examapp1/options.txt", "r");
          MainWindow::openfile(2,i);
     //   qDebug()<<"question_no is:"<<question_no;

         switch(q[i].answer)
         {
         case 'a': ui->radioButton_1->click();break;
          case 'b': ui->radioButton_2->click();break;
               case 'c': ui->radioButton_3->click();break;
           case 'd': ui->radioButton_4->click();break;
         default: ui->radioButton_1->click();break;
            semaphore=0;
         }
   }

    }
}
}


void MainWindow::print_sec()
{

char *string=(char*)malloc(4);


//QString     currentTimeText = currentTime.toString(second);
//if(second >0)
{
    sprintf(string,"%d ",second);
ui->lcdNumber_2->display(string);
}

 if (second==0 && stop_sec_timer==false) // countdown has finished
   {
second =59;
sprintf(string,"%d ",second);
ui->lcdNumber_2->display(string);
   }
   else if(second<0 || stop_sec_timer==true)
   {
       QString     currentTimeText = currentTime.toString("00");
       ui->lcdNumber_2->display(currentTimeText);


   }

  second--;
free(string);
}

void MainWindow::on_pushButton_4_clicked()
{
    signal_next_clicked=true;

    ui->radioButton_1->click();

   if(question_no<no_of_questions)
    {
    q[question_no].q_object->click();
    }

else
   {
question_no=0;
q[question_no].q_object->click();
   }

   for(int i=0;i<no_of_questions;i++)
   {


  if(q[i].q_object->isChecked() )
  {

  question_no=i+1;
  qDebug()<<"on_pushButton_4_clicked"<<question_no;

  }

   }

}
 answers::~answers()
 {

 }
student::~student()
{

}
void MainWindow::print_attended_question(int attended_question)
{
    char ch[30]={0};
    sprintf(ch,"attended question %d",attended_question);
    QMessageBox::information(
        this,
        tr("attended question"),
        tr(ch) );



}
bool answer_saved;
int MainWindow::store_answers_to_file()
{
if(!answer_saved)
{
  //  FILE *fptr=NULL;
    int attended_question=0;
 //   char answers[no_of_questions]={0};
    char *answers=(char*)malloc(no_of_questions);
   // fptr = fopen("/home/user/examapp1/answer.txt", "w");
 //   fptr = fopen(answer_file_path, "w");
//    if(fptr == NULL)
//    {
//        qDebug()<<"not able to open answer file";
//    }
    int i;
    for(i=0;i<no_of_questions;i++)
    {
        char c=q[i].answer;
        if(c !=0)
        {
            attended_question++;
     //   fputc(c,fptr);
        answers[i]=c;
        }
        else
        {
         // fputc('e',fptr);
            answers[i]='e';
      //  fputc('\n',fptr);

        }
    }
  //  fclose(fptr);
    //
    int len=strlen(answers);
    bool ok=false;
    QString packet_send =QString::fromLatin1(answers,len);
    free(answers);
//    packet="5"+packet;
//     socket_client->write_to_server(packet.toLatin1());
//    socket_client->wait_for_readyread(10);
//     QString status=buffer_read;
//     buffer_read="\0";
//   QString len_to_read_qstring=status.mid(0,2);
//    int len_to_read=len_to_read_qstring.toInt(&ok,10);
//    if(ok!=true)
//    {
//    return -1;
//    }
//    status=status.mid(2,len_to_read);
//    if(status!="ok")
//    {
//        return -1;

//    }
     QString packet="5";
socket_client->write_to_server(packet.toLatin1());
socket_client->wait_for_readyread(-1);
if(buffer_read!="ok")
{
    exit(5);
}
socket_client->write_to_server(packet_send.toLatin1());
socket_client->wait_for_readyread(-1);
if(buffer_read!="ok")
{
    exit(5);
}
socket_client->write_to_server("ok");
socket_client->wait_for_readyread(-1);
if(buffer_read!="ok")
{
    qDebug()<<"answers not stored correctly";
    exit(5);
}
answer_saved=true;
    return attended_question;
}
}

bool MainWindow::read_response_to_server()
{
    QByteArray data="02ok";

            int k=  socket_client->write_to_server(data);
            if(k==4)
            {
                 if(socket_client->wait_for_readyread(50))
                 {
                     data=buffer_read;
                     buffer_read="\0";
                     if(data=="02ok")
                         return true;
                     else
                         return false;
                 }
                 else
                      return false;
            }
            else
             return false;

}

bool MainWindow::read_response_from_server()
{
    QByteArray data;
//    bool ok=false;

//    int k= socket->write(data);
//    if(k==4)
//        return socket->waitForReadyRead(50);
//    else
//     return false;
 if(socket_client->wait_for_readyread(50))
 {
     data=buffer_read;
     buffer_read="\0";
    if(data=="02ok")
    {
//       int k= socket_client->write_to_server(data);
//       if(k==4)
           return true;

//       else return false;
    }
    else
      return false;

 }
}
