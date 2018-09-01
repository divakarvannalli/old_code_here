#include "mythread.h"

extern int student_count_no;
extern char * quest_file_path;
extern char * options_file_path;
extern char * instruction_file_path;
extern char * answer_file_path;

 QByteArray usn;
 QByteArray USN;
 QByteArray NAME;
 QByteArray EMAIL_ID;
MyThread::MyThread(qintptr ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void MyThread::run()
{
    // thread starts here
    qDebug() << " Thread started";

    socket = new QTcpSocket();
    // set the ID
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        // something's wrong, we just emit a signal
        emit error(socket->error());
        return;
    }
    quest_file_path_thread=(char *)malloc(100);//quest_file_path;
   options_file_path_thread= (char *)malloc(100);//options_file_path;
    instruction_file_path_thread=(char *)malloc(100);//instruction_file_path;
    answer_file_path_thread=(char *)malloc(100);//answer_file_path;
    student_count=(char *)malloc(20);
    strcpy(quest_file_path_thread,quest_file_path);
     strcpy(options_file_path_thread,options_file_path);
     strcpy(instruction_file_path_thread,instruction_file_path);
      strcpy(answer_file_path_thread,answer_file_path);
    // connect socket and signal
    // note - Qt::DirectConnection is used because it's multithreaded
    //        This makes the slot to be invoked immediately, when the signal is emitted.

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));


    // make this thread a loop,
    // thread will stay alive so that signal/slot to function properly
    // not dropped out in the middle when thread dies

    exec();
}


void MyThread::readyRead()
{
    // get the information
    bool ok=false;

    QByteArray Data = socket->readAll();
   //QByteArray s= Data.mid(0,1);
   int page_controll=0,status;
   page_controll=Data.toInt(&ok,10);

if(ok== true)
{
   // if(!write_response_to_client()) exit(2);
    switch(page_controll)
    {
    case 1:
        socket->write("ok");
        socket->waitForReadyRead(-1);
       Data=socket->readAll();
       ok=verify_authenticity(Data);

       if(ok==true)
       {
           student_count_no++;
           qDebug()<<"no of student"<<student_count_no;
      instruction_fptr=fopen(instruction_file_path_thread,"r");
      if(instruction_fptr== NULL)
      {
          qDebug()<<"cant open instruction file ";
          break;

      }


      int len=strlen(answer_file_path_thread);
      if(answer_file_path_thread[len-1]!='/')
      sprintf(student_count,"/student%d.txt",student_count_no);
      else
      sprintf(student_count,"student%d.txt",student_count_no);
      strcat(answer_file_path_thread,student_count);
      answer_fptr=fopen(answer_file_path_thread,"w");
      if(answer_fptr== NULL)
      {
          qDebug()<<"cant open instruction file ";
          break;

      }
      usn="USN NO-------->"+USN+"\n";
      fputs(usn,answer_fptr);
      usn="STUDENT NAME-------->"+NAME+"\n";
      fputs(usn,answer_fptr);
      usn="STUDENT EMAIL ID-------->"+EMAIL_ID;
      fputs(usn,answer_fptr);
      socket->write("true");
       }
       else
       {
           socket->write("false");

             socket->waitForReadyRead(-1);
             socket->readAll();
             MyThread::terminate();
            free((char *)quest_file_path_thread);
            free((char *)options_file_path_thread);
            free((char *)instruction_file_path_thread);
            free((char *)answer_file_path_thread);
            free((char *)student_count);
       }
        break;
    case 2:
    {
        socket->write("ok");
        socket->waitForReadyRead(-1);
        if(socket->readAll()=="ok")
        status=read_instruction();
        break;
    }
    case 3:
    {
        socket->write("ok");
        socket->waitForReadyRead(-1);
        QByteArray line=socket->readAll();

        socket->write("ok");
        socket->waitForReadyRead(-1);
        if(socket->readAll()=="ok")
        read_Question(line);

        break;
}
      case 4:
    {
        socket->write("ok");
        socket->waitForReadyRead(-1);
        QByteArray line=socket->readAll();

        socket->write("ok");
        socket->waitForReadyRead(-1);
        if(socket->readAll()=="ok")
        read_options(line);
        break;
    }
     case 5:
    {
        socket->write("ok");
        socket->waitForReadyRead(-1);
        QByteArray answer_packet=socket->readAll();

        socket->write("ok");
        socket->waitForReadyRead(-1);
        if(socket->readAll()=="ok")
        store_answer_to_file(answer_packet);
        break;
    }
        defualt:break;

    }

}
else
  exit(1);



}

bool MyThread::verify_authenticity(QByteArray Data)
{
    bool ok=false;
    QByteArray user_lenght= Data.mid(1,2);
    QByteArray password_lenght= Data.mid(3,2);
    QByteArray usn_len= Data.mid(5,2);
      QByteArray name_len= Data.mid(7,2);
      QByteArray emailid_len=Data.mid(9,2) ;
    int user_len,pwd_len,usn_no_len;
    int usn,name,emailid;

    user_len=user_lenght.toInt(&ok,10);
    if(ok== false)
        return ok;
    pwd_len=password_lenght.toInt(&ok,10);
    if(ok== false)
        return ok;
usn_no_len=usn_len.toInt(&ok,10);
if(ok== false)
    return ok;

    QByteArray user_name=Data.mid(11,user_len);
    QByteArray pwd=Data.mid(11+user_len,pwd_len);
   if(user_name== "divakar" &&  pwd=="123")
   {
       usn=usn_len.toInt(&ok,10);
       if(ok== false)
           return ok;
       name=name_len.toInt(&ok,10);
       if(ok== false)
           return ok;
       emailid=emailid_len.toInt(&ok,10);
       if(ok== false)
           return ok;
       USN=Data.mid(11+user_len+pwd_len,usn);
       NAME=Data.mid(11+user_len+pwd_len+usn,name);
       EMAIL_ID=Data.mid(11+user_len+pwd_len+usn+name,emailid);


       return true;
   }
    else
       return false;
}

int MyThread::read_instruction()
{
char line[256]={0};
QString status;

while (fgets(line, sizeof line, instruction_fptr) != NULL)
     {
        int len=strlen(line);
        QString packet_len=QString::number(len);
        QString packet =QString::fromLatin1(line,len);

        //send lenght of the string to be read
        socket->write(packet_len.toLatin1());
        socket->waitForReadyRead(-1);
        if((status=socket->readAll())!="ok")
        {
            fclose(instruction_fptr);
            qDebug()<<"disconnected from client or data not recieved at client side";
            break;
        }

        //send string to be read
        socket->write(packet.toLatin1());
        socket->waitForReadyRead(-1);
        if((status=socket->readAll())!="ok")
        {
            fclose(instruction_fptr);
            qDebug()<<"disconnected from client or data not recieved at client side";
            break;
        }

     }
      if(status!="ok")
          return -1;
    fclose(instruction_fptr);
     socket->write("EOF") ;
     socket->waitForReadyRead(-1);
     status=socket->readAll();
     if(status!="ok")
    return -1;
     else
         return 0;
}
int MyThread::read_Question( QByteArray data)
{

    char line[256]={0};
    int count=0;
    int qa_no;bool ok=false;

    QByteArray recieved_packet;
    QByteArray status;
//    socket->write("ok") ;
//    socket->waitForReadyRead(10);
  question_fptr=fopen(quest_file_path_thread,"r");
  if(question_fptr== NULL)
  {
      qDebug()<<"cant open instruction file ";

  }
   recieved_packet = data;
//   QString  line_no_len_Qstr=recieved_packet;
   int  lineNumber =recieved_packet.toInt(&ok,10);
   if(lineNumber <0)
       exit(-1);
//   if(ok!=true)
//       return -1;
//   recieved_packet=recieved_packet.mid(3,line_no_len);
//ok=false;
//    int lineNumber=recieved_packet.toInt(&ok,10);
//    if(ok!=true)
//    {

//    return -1;
//    }
    while (fgets(line, sizeof line, question_fptr) != NULL) /* read a line */
       {
           if (count == lineNumber)
           {

             break;
           }
           else
           {
               count++;
           }
       }

    fclose(question_fptr);
    int len=strlen(line);
 //   QString packet_len=QString::number(len);
    QString send_data=QString::fromLatin1(line,len);
    socket->write(send_data.toLatin1());
    socket->waitForReadyRead(-1);
//    if(read_response_from_client()!=true) return -1;
//    QString packet =QString::fromLatin1(line,len);
//    socket->write(packet.toLatin1());
//    socket->waitForReadyRead(-1);
    status=socket->readAll();
 if(status!="ok") return -1;
   socket->write("ok");
    return 0;

}
int MyThread::read_options(QByteArray data)
{

//    char arr[4][15]={0};
//    char line[256]={0};
//    int count=0;
//    int lineNumber=0;
//    bool response;
//    QString recieved_data;
//    qint64 buff_size;
//    int qa_no;bool ok=false;

//    QByteArray recieved_packet;
//    QByteArray status;
//    option_fptr=fopen(options_file_path_thread,"r");
//    if(option_fptr== NULL)
//    {
//        qDebug()<<"cant open instruction file ";

//    }

//    recieved_packet = data;
//    QString  line_no_len_Qstr=recieved_packet.mid(1,2);
//    int  line_no_len =line_no_len_Qstr.toInt(&ok,10);
//    if(ok!=true)
//        return -1;
//    recieved_packet=recieved_packet.mid(3,line_no_len);
// ok=false;
//      lineNumber=recieved_packet.toInt(&ok,10);
//     if(ok!=true)
//     {

//     return -1;
//     }

    char line[256]={0};
    int count=0;
    int qa_no;bool ok=false;

    QByteArray recieved_packet;
    QByteArray status;
//    socket->write("ok") ;
//    socket->waitForReadyRead(10);
  option_fptr=fopen(options_file_path_thread,"r");
  if(option_fptr== NULL)
  {
      qDebug()<<"cant open instruction file ";

  }
   recieved_packet = data;
//   QString  line_no_len_Qstr=recieved_packet;
   int  lineNumber =recieved_packet.toInt(&ok,10);
   if(lineNumber <0)
       exit(-1);
//   if(ok!=true)
//       return -1;
//   recieved_packet=recieved_packet.mid(3,line_no_len);
//ok=false;
//    int lineNumber=recieved_packet.toInt(&ok,10);
//    if(ok!=true)
//    {

//    return -1;
//    }
     while (fgets(line, sizeof line, option_fptr) != NULL) /* read a line */
        {
            if (count == lineNumber)
            {

              break;
            }
            else
            {
                count++;
            }
        }

     fclose(option_fptr);
     int len=strlen(line);
  //   QString packet_len=QString::number(len);
     QString send_data=QString::fromLatin1(line,len);
     socket->write(send_data.toLatin1());
     socket->waitForReadyRead(-1);
 //    if(read_response_from_client()!=true) return -1;
 //    QString packet =QString::fromLatin1(line,len);
 //    socket->write(packet.toLatin1());
 //    socket->waitForReadyRead(-1);
     status=socket->readAll();
  if(status!="ok") return -1;
    socket->write("ok");
     return 0;
}

bool MyThread::read_response_from_client()
{
    QByteArray status;
    bool ok=false;
status=socket->readAll();
QString len_to_read_qstring=status.mid(0,2);
int len_to_read=len_to_read_qstring.toInt(&ok,10);
if(ok!=true)
{
    return false;
}
status=status.mid(2,len_to_read);
if(status!="ok")
{

return false;
}
return true;
}
//if data correctly recieved call this
bool MyThread::read_response_to_client()
{
    QByteArray data="02ok";

            int k= socket->write(data);
            if(k==4)
            {
//                 if(socket->waitForReadyRead(50))
//                 {
//                     data=socket->readAll();
//                     if(data=="02ok")
                         return true;
//                     else
//                         return false;
                // }
//                 else
//                      return false;
            }
            else
             return false;

}
//give response to client after reading a message posted
bool MyThread::read_response_from_client_2()
{
    QByteArray data;
//    bool ok=false;

//    int k= socket->write(data);
//    if(k==4)
//        return socket->waitForReadyRead(50);
//    else
//     return false;
 if(socket->waitForReadyRead(50))
 {
    data=socket->readAll();
    if(data=="02ok")
    {
       int k= socket->write(data);
       if(k==4) return true;
       else return false;
    }
    else
      return false;

 }
}
extern unsigned int total_no_of_questions;
void MyThread::store_answer_to_file(QByteArray data)
{
char *str=(char *)malloc(total_no_of_questions);
 QByteArray ba=data;
 strcpy(str,ba.data());
 fputc('\n',answer_fptr);
  for(int i=0;i<total_no_of_questions;i++)
  {

      fputc(str[i],answer_fptr);
       fputc('\n',answer_fptr);

  }
  fclose(answer_fptr);
  free((char *)str);
  socket->write("ok");

}

void MyThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";


    socket->deleteLater();
    free((char *)quest_file_path_thread);
    free((char *)options_file_path_thread);
    free((char *)instruction_file_path_thread);
    free((char *)answer_file_path_thread);
    free((char *)student_count);
}
QString MyThread::IntToArray(int source) //Use qint32 to ensure that the number have 4 bytes
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

void  MyThread::forced_quit_app()
{
    if(socket)
    {
  //   socket->write("-1");
    }
}
