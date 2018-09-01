
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTime>
#include<QDebug>
#include<qtextedit.h>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/qprinter.h>
#include <QtGui/qpaintdevice.h>
#include <qpushbutton.h>
#include <QPalette>
#include<qfont.h>
#include<QFontComboBox>
#include<QStringListModel>
#include<QListView>
#include"common.h"



void create_store_answers_database();
void verify_answers();
void calculate_score();
void create_questions_button(int x, int y,int initial_val,int boundary_val,
                             QFrame * frame,int distanceX,int distanceY,
                             int size1,int size2,int no_of_button_in_one_line,int distance_between_button);




#define NOT_ANSWERED 'N'

QFrame *frame_resoning;
QFrame *frame_Data_Analysis;
QFrame *frame_General_Awareness;
QFrame *frame_english;

#define db_ver

#ifdef file_ver
#define  answer_file_path_thread "/home/user/appandroid/answers/answers"
#endif
#ifdef db_ver
QString answer_file_path_thread = "/home/user/Desktop/database/correct_answer_table";
#endif
char* instruction_file_path_thread="/home/user/appandroid/instructions.txt";
QString options_file_path_thread = "/home/user/Desktop/database/option_table";
QString  quest_file_path_thread = "/home/user/Desktop/database/question_table";

char* student_count;

QTime currentTime;
char answer;
int question_no;

 int hour ;
 int minute ;
 int second;
 bool stop_sec_timer;
 bool signal_next_clicked;
static answers  q[TOTAL_NO_QUESTIONS];
QTimer * timer ;
QTimer * timer_sec;

char *sptr;
int currect_answers,not_answered,wrong_answers;\
extern int question_paper_clicked;





#ifdef mains_exam
//init boundary values
int section_1_init_val=0;
int section_1_boundary_val=Reasoning;
int section_2_init_val=Reasoning;
int section_2_boundary_val=Reasoning+Data_Analysis;
int section_3_init_val=Reasoning+Data_Analysis;
int section_3_boundary_val=Reasoning+Data_Analysis+General_Awareness;
int section_4_init_val=Reasoning+Data_Analysis+General_Awareness;
int section_4_boundary_val=Reasoning+Data_Analysis+General_Awareness+English_Language;
#endif


#ifdef prelims_exam
//init boundary values
int section_1_init_val=0;
int section_1_boundary_val=Reasoning;
int section_2_init_val=Reasoning;
int section_2_boundary_val=Reasoning+Data_Analysis;
int section_3_init_val=Reasoning+Data_Analysis;
int section_3_boundary_val=Reasoning+Data_Analysis+General_Awareness;
#endif

db_manage *db_manage_question ;
db_manage *db_manage_option;
db_manage * answers_table;


db_manage::db_manage(int question_paper_clicked,QString type_database)
{

           path=QString::number(question_paper_clicked);
           path=type_database+path;
           question_table_=QSqlDatabase::addDatabase("QSQLITE");
           question_table=& question_table_;
           question_table->setDatabaseName(path);
             if (!question_table->open())
             {
                qDebug() << "Error: connection with database fail:question table";
             qDebug()<<question_table->lastError().text() ;
             assert(0);
             }
             query=new QSqlQuery(*question_table);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//windows name anad size setup
    this->setWindowTitle("EXAM APP");
    QDesktopWidget dw;
    int x=dw.width()*1;
    int y=dw.height()*1;
//    this->setFixedSize(x,y);
//    setWindowFlags(Qt::Window|Qt::WindowMaximizeButtonHint);


QStringList stringList;
stringList << "English" << "Hindi";
QStringListModel *mdl = new QStringListModel(stringList);
QFont comboFont("Arial",11,-1,true);
QListView *vw = new QListView;
vw->setFont(comboFont);
ui->fontComboBox->setModel(mdl);
ui->fontComboBox->setView(vw);
ui->radioButton_1->click();

int i,initial_val=0,boundary_val=0;
QFont font8;
font8.setPointSize(10);
font8.setBold(true);
font8.setWeight(50);
sptr=(char *)malloc(20);


frame_resoning=new QFrame(ui->frame_6);
frame_Data_Analysis=new QFrame(ui->frame_6);
frame_General_Awareness=new QFrame(ui->frame_6);
frame_english=new QFrame(ui->frame_6);

//reasoning
x=15,y=10;
initial_val=section_1_init_val;
boundary_val=section_1_boundary_val;
create_questions_button(15,10,initial_val,boundary_val,frame_resoning,
                        50,10,40,40,10,50);

//Data_Analysis
x=15,y=10;
initial_val=section_2_init_val;
boundary_val=section_2_boundary_val;
create_questions_button(15,10,initial_val,boundary_val,frame_Data_Analysis,
                        50,10,40,40,10,50);


//General_Awareness
x=15,y=10;
initial_val=section_3_init_val;
boundary_val=section_3_boundary_val;
create_questions_button(20,10,initial_val,boundary_val,frame_General_Awareness,
                        60,10,50,50,8,60);

//English_Language
x=15,y=10;
initial_val=section_4_init_val;
boundary_val=section_4_boundary_val;
create_questions_button(20,10,initial_val,boundary_val,frame_english,
                        60,10,50,50,8,60);

for(i=0;i<TOTAL_NO_QUESTIONS;i++)
connect(q[i].q_object, SIGNAL(clicked(bool)), this, SLOT(itwasclicked()));

free(sptr);

question_no=1;
timer = new QTimer(this);
connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));



timer_sec=new QTimer(this);
connect(timer_sec, SIGNAL(timeout()), this, SLOT(print_sec()));

run_timer();



db_manage_question =  new db_manage(question_paper_clicked,quest_file_path_thread);
bool k=db_manage_question->query->prepare("SELECT question  FROM questions WHERE rowid =:x");
assert(k!=false);
MainWindow::openfile(1,0);

db_manage_option = new db_manage(question_paper_clicked,options_file_path_thread);
 MainWindow::openfile(2,0);
  Result_window =new Result();
//      Result_window->show();
//      QSlider sl;
//      sl.show();

   QObject::connect(this,SIGNAL(valueChanged(double,double,double,double)),Result_window,SLOT(setProgress(double,double,double,double)));


 q[0].q_object->click();
 ui->radioButton_1->click();
 ui->pushButton_5->click();

}

void MainWindow::run_timer()
{

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

}


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

         currentTime.setHMS(hour,minute,0);
  QString     currentTimeText = currentTime.toString("hh:mm");
        ui->lcdNumber->display(currentTimeText);

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
             verify_answers();
             calculate_score();

             emit MainWindow::valueChanged( Reasoning_marks, data_analysis_marks, gk_marks, english_marks);
             //  QApplication::quit();
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


int MainWindow::openfile(int text_edit,int qa_no)
{

     char *ch,*ch2;
     ch=(char*)malloc(256);
      ch2=(char*)malloc(18);

     char line[256]={0};

  int  lineNumber=qa_no;

     switch(text_edit)
     {
     case 1:  //questions
     {
         bool k;

db_manage_question->query->bindValue(":x",lineNumber);
k=db_manage_question->query->exec();
assert(k!=false);
QString question;
int idName = db_manage_question->query->record().indexOf("question");
db_manage_question->query->next();
question = db_manage_question->query->value(idName).toString();

 qDebug()<<"--------->"<<k+"   "<<db_manage_question->query->lastError().text() ;
#if 0
         char line[256]={0};
         int count=0;
         strcpy(ch,quest_file_path_thread);
         sprintf(ch2,"%d.txt\0",question_paper_clicked);
         strcat(ch,ch2);
         question_fptr=fopen(ch,"r");
         memset(ch,0,sizeof(ch));
          memset(ch2,0,sizeof(ch));

         if(question_fptr== NULL)
         {
             qDebug()<<"cant open question file thus exiting ";
            exit(1);
         }


          if(lineNumber <0)
              exit(-1);

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

#endif
           QByteArray ba;
ba=question.toLatin1();
strcpy(line,ba.data());

   ui->textEdit->setText(QApplication::translate("MainWindow",line , 0));
                break;
}
     case 2:
         {


#if 0
         char line[256]={0};
             int count=0;
             int qa_no;bool ok=false;
             char arr[5][15]={0};


             strcpy(ch,options_file_path_thread);
             sprintf(ch2,"%d.txt\0",question_paper_clicked);
             strcat(ch,ch2);
             option_fptr=fopen(ch,"r");
             memset(ch,0,sizeof(ch));
             memset(ch2,0,sizeof(ch));

           if(option_fptr== NULL)
           {
               qDebug()<<"cant open option file thus exiting";
                exit(2);
           }


            if(lineNumber <0)
                exit(-1);

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

             // return 0;


       //   strcpy(line,packet.toLatin1());

                if(line[0] == '\n')
                {


                    ui->radioButton_1->setText(QApplication::translate("MainWindow",NULL , 0));
                    ui->radioButton_2->setText(QApplication::translate("MainWindow",NULL , 0));
                    ui->radioButton_3->setText(QApplication::translate("MainWindow",NULL , 0));
                    ui->radioButton_4->setText(QApplication::translate("MainWindow",NULL , 0));
                    ui->radioButton_5->setText(QApplication::translate("MainWindow",NULL , 0));
                    break;

                }
//                qDebug()<<line[0];
//                qDebug()<<"count value"<<count;
//                qDebug()<<"line no "<<lineNumber;
        ch=MainWindow::radio_button(arr[0],line+2);


            ui->radioButton_2->setText(QApplication::translate("MainWindow",arr[0] , 0));


   ch=  MainWindow::radio_button(arr[1],ch+1);

             ui->radioButton_1->setText(QApplication::translate("MainWindow",arr[1] , 0));


                 ch=  MainWindow::radio_button(arr[2],ch+1);
                    ui->radioButton_3->setText(QApplication::translate("MainWindow",arr[2] , 0));


                        ch=  MainWindow::radio_button(arr[3],ch+1);

                           ui->radioButton_4->setText(QApplication::translate("MainWindow",arr[3] , 0));

                           ch=  MainWindow::radio_button(arr[4],ch+1);

                              ui->radioButton_5->setText(QApplication::translate("MainWindow",arr[4] , 0));

#endif
bool k=db_manage_option->query->exec("SELECT *  FROM option_table ");
assert(k!=false);
 int idName_[no_of_option];
        for(int c=1;c<=no_of_option;c++)
        {
            char option[15];
            sprintf(option,"option%d",c);
           idName_[c-1]= db_manage_option->query->record().indexOf(option);

        }


           int i=0;
          for(i=0;i<=lineNumber;i++)
           {
           db_manage_option->query->next();
           }
            for(int j=0;j<no_of_option;j++)
            {
          QString question = db_manage_option->query->value(idName_[j]).toString();
           QByteArray ba;
           ba=question.toLatin1();
           strcpy(line,ba.data());
           switch(j)
           {
           case 0:ui->radioButton_1->setText(QApplication::translate("MainWindow",line , 0));break;
           case 1:ui->radioButton_2->setText(QApplication::translate("MainWindow",line , 0));break;
           case 2:ui->radioButton_3->setText(QApplication::translate("MainWindow",line , 0));break;
           case 3:ui->radioButton_4->setText(QApplication::translate("MainWindow",line , 0));break;
           case 4:ui->radioButton_5->setText(QApplication::translate("MainWindow",line , 0));break;
           }
        }
#if 0
 ui->radioButton_1->setText(QApplication::translate("MainWindow",line , 0));


 k=query2.prepare("SELECT *  FROM option_table WHERE rowid =:x");
            query2.bindValue(":x",lineNumber);
            k=query2.exec();
           idName = query2.record().indexOf("option2");
            query2.next();
            question = query2.value(idName).toString();
            ba=question.toLatin1();
            strcpy(line,ba.data());
  ui->radioButton_2->setText(QApplication::translate("MainWindow",line , 0));

  k=query3.prepare("SELECT *  FROM option_table WHERE rowid =:x");
             query3.bindValue(":x",lineNumber);
             k=query3.exec();
             idName = query3.record().indexOf("option3");
             query3.next();
             question = query3.value(idName).toString();
             ba=question.toLatin1();
             strcpy(line,ba.data());
   ui->radioButton_3->setText(QApplication::translate("MainWindow",line , 0));


   k=query4.prepare("SELECT *  FROM option_table WHERE rowid =:x");
              query4.bindValue(":x",lineNumber);
              k=query4.exec();
            idName = query4.record().indexOf("option4");
              query4.next();
              question = query4.value(idName).toString();
              ba=question.toLatin1();
              strcpy(line,ba.data());
    ui->radioButton_4->setText(QApplication::translate("MainWindow",line , 0));


    k=query5.prepare("SELECT *  FROM option_table WHERE rowid =:x");
               query5.bindValue(":x",lineNumber);
               k=query5.exec();
              idName = query5.record().indexOf("option5");
               query5.next();
               question = query5.value(idName).toString();
               ba=question.toLatin1();
               strcpy(line,ba.data());
     ui->radioButton_5->setText(QApplication::translate("MainWindow",line , 0));


   break;

#endif
         }
defualt: break;


     }

   return 0;
}




char * MainWindow::radio_button(char * arr ,char * ch)
{


          int  i=0;
if(ch[i] == '\n')
{
 arr[i]=ch[i];

}
else
{
             while(ch[i]!=';')
             {

                 arr[i]=ch[i];
                 i++;

             }
 }
             arr[i+1]='\0';
            ch=ch+i;

            return ch;
}


void MainWindow::on_radioButton_1_clicked()
{
    answer='a';

    qDebug()<<"answer is :"<<answer;

}

void MainWindow::on_radioButton_2_clicked()
{
    answer='b';
     qDebug()<<"answer is :"<<answer;

}

void MainWindow::on_radioButton_3_clicked()
{
    answer='c';
     qDebug()<<"answer is :"<<answer;

}

void MainWindow::on_radioButton_4_clicked()
{
    answer='d';
     qDebug()<<"answer is :"<<answer;
}

void MainWindow::on_pushButton_2_clicked()
{


 //   if(answer)
    {
    q[question_no-1].question_no=question_no;
    q[question_no-1].answer=answer;
    q[question_no-1].answer_saved=true;
    qDebug()<<"q and a is :"<<question_no<<answer;
    q[question_no-1].q_object->setStyleSheet("background-color: rgb(85, 170, 0);");
    QPalette palette;
     palette.setBrush(QPalette::ButtonText,Qt::white );
     q[question_no-1].q_object->setPalette(palette);
    answer=0;
    }
MainWindow::on_pushButton_4_clicked();
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
       verify_answers();
       calculate_score();


        emit MainWindow::valueChanged( Reasoning_marks, data_analysis_marks, gk_marks, english_marks);

    //QApplication::quit();
  } else {

    qDebug() << "Yes was *not* clicked";
  }
}

void MainWindow::itwasclicked()
{
//if(push_button_clicked)
//{
    qDebug() << "question clicked";
 QPalette palette;
  palette.setBrush(QPalette::ButtonText,Qt::white );
  //previous visited question for question no =0
if (question_no==0)
{
    if(  q[question_no].answer_saved == false && q[question_no].review_next == false)
    {//red
        q[question_no].q_object->setStyleSheet("background-color: rgb(255, 0, 0);");
    q[question_no].q_object->setPalette(palette);
    }
    else if(  q[question_no].answer_saved == true)
    {//green
        q[question_no].q_object->setStyleSheet("background-color: rgb(85, 170, 0);");
        q[question_no].q_object->setPalette(palette);
    }
        else if(q[question_no].review_next == true)
    {//blue
        q[question_no].q_object->setStyleSheet("background-color: rgb(85, 85, 255);");
        q[question_no].q_object->setPalette(palette);
    }
    else ;

}
 else  //previous visited question for question no >0
  {
    if(  q[question_no-1].answer_saved == false && q[question_no-1].review_next == false)
    {
      q[question_no-1].q_object->setStyleSheet("background-color: rgb(255, 0, 0);");
      q[question_no-1].q_object->setPalette(palette);
    }

    else if(  q[question_no-1].answer_saved == true)
    {
        q[question_no-1].q_object->setStyleSheet("background-color: rgb(85, 170, 0);");
        q[question_no-1].q_object->setPalette(palette);
    }
        else if(q[question_no-1].review_next == true)
    {
        q[question_no-1].q_object->setStyleSheet("background-color: rgb(85, 85, 255);");
        q[question_no-1].q_object->setPalette(palette);
    }
    else;
  }


    for(int i=0;i<TOTAL_NO_QUESTIONS;i++)
    {

  // bool checked =false;
   //q[i].q_object->clicked(checked);
   if(q[i].q_object->isChecked())
   {
      // FILE *fptr=NULL;
       question_no=i+1;

    q[i].q_object->setStyleSheet("background-color: rgb(170, 170, 127);");
    q[i].q_object->setPalette(palette);

q[i].q_object->setChecked(false);
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
              case 'e': ui->radioButton_5->click();break;
         default: ui->radioButton_1->click();break;
         }

   }

    }
//}
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

   if(question_no<TOTAL_NO_QUESTIONS)
    {

    if(question_no==Reasoning)
    {
    ui->pushButton_7->click();
    }
   else if(question_no==Reasoning+Data_Analysis)
    {
        ui->pushButton_8->click();

    }
  else  if(question_no==Reasoning+Data_Analysis+General_Awareness)
    {
        ui->pushButton_6->click();

    }
    else
   q[question_no].q_object->click();
    qDebug()<<"question_no"<<question_no;
   }

else
   {
 ui->pushButton_5->click();
question_no=0;
q[question_no].q_object->click();

   }

   for(int i=0;i<TOTAL_NO_QUESTIONS;i++)
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
 db_manage::~db_manage()
 {


 }

student::~student()
{

}
void MainWindow::print_attended_question(int attended_question)
{
    char ch[200]={0};
    timer->stop();
   //timer_q->start(100);
   timer_sec->stop();
    sprintf(ch,"attended question %d \nsection1 %d \nsection2 %d \nsection3 %d \nsection4 %d ",
            attended_question,
            attended_section_1_question,attended_section_2_question,
            attended_section_3_question,attended_section_4_question);
    QMessageBox::information(
        this,
        tr("attended question"),
        tr(ch) );



}
void create_store_answers_database()
{
    QDir dir;
    QString entered_answer_path=dir.currentPath()+"/entered_answers";
    answers_table = new db_manage(question_paper_clicked,entered_answer_path);
  bool k = answers_table->query->exec("create table IF NOT EXISTS entered_answer "
                                                  "(id integer primary key, "
                                                  "all_answers varchar,"
                                                  " section1 varchar, "
                                                  "section2 varchar,"
                                                  "section3 varchar,"
                                                   "section4 varchar,"

                                                     "attended_all_questions integer,"
                                                     "attended_section_1_question integer,"
                                                     "attended_section_2_question integer,"
                                                     "attended_section_3_question integer,"
                                                     "attended_section_4_question integer,"
                                                     "attended_section_5_question integer,"
                                                     "correct_all integer,"
                                                      "correct_section1 integer,"
                                                      "correct_section2 integer,"
                                                      "correct_section3 integer,"
                                                        "database_filled bool,"
                                                      "correct_section4 integer)");
  if(!k)
  {
      qDebug()<<"failed to create db for entered answers error:"<<answers_table->query->lastError();
      assert(0);
  }
}

bool answer_saved;

 char *ALL_answers;
int MainWindow::store_answers_to_file()
{
    int attended_question=0;

if(!answer_saved)
{

    ALL_answers=(char*)malloc(TOTAL_NO_QUESTIONS);

    int j;
    int answer_section_init_val[NO_OF_SECTIONS];
    int answer_section_bound_val[NO_OF_SECTIONS];

    answer_section_init_val[0]=section_1_init_val;\
    answer_section_init_val[1]=section_2_init_val;
    answer_section_init_val[2]=section_3_init_val;
    answer_section_init_val[3]=section_4_init_val;

    answer_section_bound_val[0]=section_1_boundary_val;
    answer_section_bound_val[1]=section_2_boundary_val;
    answer_section_bound_val[2]=section_3_boundary_val;
    answer_section_bound_val[3]=section_4_boundary_val;

    for(j = 0;j < NO_OF_SECTIONS;j++)
    {
        int init=answer_section_init_val[j];
        int boundary=answer_section_bound_val[j];
        int i;
        for(i=init;i<boundary;i++)
        {
        char c=q[i].answer;
        if(c !=0)
        {
            attended_question++;
            if(init >= section_1_init_val && init < section_2_init_val)
            attended_section_1_question ++;
            else if (init >= section_2_init_val && init < section_3_init_val)
            attended_section_2_question ++;
            else if (init >= section_3_init_val && init < section_4_init_val)
            attended_section_3_question ++;
            else if (init >= section_4_init_val && init<TOTAL_NO_QUESTIONS )
            attended_section_4_question ++;
     ALL_answers[i]=c;
        }
        else
        ALL_answers[i]=NOT_ANSWERED;


        }
    }


  answer_saved=true;

create_store_answers_database();
QSqlQuery query(*answers_table->question_table);
QString all_answers_qstring,section1_answer,section2_answer,
        section3_answer,section4_answer ;
all_answers_qstring.sprintf(ALL_answers);
section1_answer = all_answers_qstring.mid(1,section_1_boundary_val);
section2_answer = all_answers_qstring.mid(section_1_boundary_val+1,section_2_boundary_val);
section3_answer = all_answers_qstring.mid(section_2_boundary_val+1,section_3_boundary_val);
section4_answer = all_answers_qstring.mid(section_3_boundary_val+1,section_4_boundary_val);


//all answers
    bool k = query.prepare("INSERT INTO entered_answer(all_answers,section1,section2,section3,section4,"
                           "attended_all_questions,attended_section_1_question,"
                           "attended_section_2_question,attended_section_3_question,database_filled,"
                           "attended_section_4_question)"
                             "VALUES (:all_answers,:section1,:section2,:section3,:section4,"
                           ":attended_all_questions,:attended_section_1_question,"
                           ":attended_section_2_question,:attended_section_3_question,:database_filled,"
                           ":attended_section_4_question)");
     qDebug()<<"error"<<query.lastError().text();
    assert(k!=false);

 query.bindValue(":all_answers",all_answers_qstring);
 query.bindValue(":section1",section1_answer);
 query.bindValue(":section2",section2_answer);
 query.bindValue(":section3",section3_answer);
 query.bindValue(":section4",section4_answer);
 query.bindValue(":attended_all_questions",attended_question);
query.bindValue(":attended_section_1_question",attended_section_1_question);
query.bindValue(":attended_section_2_question",attended_section_2_question);
query.bindValue(":attended_section_3_question",attended_section_3_question);
query.bindValue(":attended_section_4_question",attended_section_4_question);
query.bindValue(":database_filled",true);
    k=query.exec();
    if(!k)
    {
     qDebug()<<  query.lastError().text()<<"TOTAL_NO_QUESTIONS" ;
     assert(0);
    }
}

return attended_question;

}

void verify_answers()
{
#ifdef file_ver
    char *ch,*ch2;
    ch=(char*)malloc(200);
    ch2=(char*)malloc(20);
    strcpy(ch,answer_file_path_thread);
    sprintf(ch2,"%d.db",question_paper_clicked);
    strcat(ch,ch2);
    sprintf(ch2,"%d.txt\0",question_paper_clicked);
    strcat(ch,ch2);
    FILE *fptr_answers=NULL;
    fptr_answers=fopen(ch,"r");
    memset(ch,0,sizeof(ch));
    memset(ch2,0,sizeof(ch));
//    char line1 [3]={0};
          // fptr_answers =fopen(answer_file_path_thread,"r");
    if(fptr_answers != NULL)
    {
        int init=0;
        while((fgets(line1, sizeof line1, fptr_answers) !=NULL ))// && ( fgets(line2, sizeof line2, fptr2) !=NULL ) )
        {
#endif


#ifdef db_ver
db_manage* correct_answer_table =new db_manage(question_paper_clicked,answer_file_path_thread);
bool k=correct_answer_table->query->prepare("SELECT answers  FROM answer_table WHERE rowid =:x");
assert(k!=false);
int init=0;
char c[3]={0};
char * line1;
line1=&c[0];
for(int i=1;i<=TOTAL_NO_QUESTIONS;i++)
{
    correct_answer_table->query->bindValue(":x",i);
    k=correct_answer_table->query->exec();
    assert(k!=false);
    QString answer;
    int idName = correct_answer_table->query->record().indexOf("answers");
    correct_answer_table->query->next();
    answer = correct_answer_table->query->value(idName).toString();

     qDebug()<<"--------->"<<k+"   "<<db_manage_question->query->lastError().text() ;

     QByteArray ba = answer.toLatin1();
    line1 = ba.data();
#endif
    if(init==0 || init == 50 || init==100 || init==150 || init==199)
     qDebug()<<"init val "<<line1<<"\n";

            if(init >= section_1_init_val && init < section_2_init_val)
            {
            if(line1[0]==ALL_answers[init])
             correct_reasoning++;
            else if(ALL_answers[init] == NOT_ANSWERED)
                not_answered_resoning++;
            else
               wrong_answered_resoning++ ;

            }
            else if (init >= section_2_init_val && init < section_3_init_val)
            {
            if(line1[0]==ALL_answers[init])
                correct_data_analysis++;

            else if(ALL_answers[init] == NOT_ANSWERED)
                not_answered_data_analysis++;
            else
               wrong_answered_data_analysis++ ;
            }
            else if (init >= section_3_init_val && init < section_4_init_val)
            {
            if(line1[0]==ALL_answers[init])
                correct_GK++;

            else if(ALL_answers[init] == NOT_ANSWERED)
                not_answered_GK++;
            else
               wrong_answered_GK++ ;
            }

            else if (init >= section_4_init_val && init<TOTAL_NO_QUESTIONS)
            {
           if(line1[0]==ALL_answers[init])
               correct_english++;

           else if(ALL_answers[init] == NOT_ANSWERED)
               not_answered_english++;
           else
              wrong_answered_english++ ;
            }


            init++;
        }

        currect_answers=correct_reasoning+correct_data_analysis+
                        correct_GK+correct_english;
        not_answered=not_answered_resoning+not_answered_data_analysis+
                      not_answered_GK+not_answered_english;
        wrong_answers=wrong_answered_resoning+wrong_answered_data_analysis+
                       wrong_answered_GK+wrong_answered_english;


#ifdef file_ver
        fclose(fptr_answers);
    }
#endif
        free(ALL_answers);
#ifdef file_ver
free(ch);
free(ch2);
if(!fptr_answers)
{
 qDebug()<<"fptr_answers NULL";
}
#endif

}

void calculate_score()
{
    Reasoning_marks=cal_score(correct_reasoning,wrong_answered_resoning);
    data_analysis_marks  =cal_score(correct_data_analysis,wrong_answered_data_analysis);
    gk_marks =cal_score(correct_GK,wrong_answered_GK);
    english_marks =cal_score(correct_english,wrong_answered_english);
    overall_score = cal_overall_score(Reasoning_marks,data_analysis_marks,
                                      gk_marks,english_marks);
}

void MainWindow::on_pushButton_13_clicked()
{
    //review and next
    if( q[question_no-1].answer==0)
    {
    q[question_no-1].answer=0;
    q[question_no-1].answer_saved=false;
    q[question_no-1].q_object->setStyleSheet("background-color: rgb(85, 85, 255);");
    QPalette palette;
     palette.setBrush(QPalette::ButtonText,Qt::white );
     q[question_no-1].q_object->setPalette(palette);
    answer=0;
      q[question_no-1].review_next=true;
     }
    MainWindow::on_pushButton_4_clicked();

}

void MainWindow::on_pushButton_11_clicked()
{
    //clear response
    if( q[question_no-1].answer_saved ||  q[question_no-1].review_next== true)
    {
    q[question_no-1].answer=0;
    q[question_no-1].answer_saved=false;
    q[question_no-1].review_next=false;
//    q[question_no-1].q_object->setStyleSheet("background-color: rgb(255, 0, 0);");
//    QPalette palette;
//     palette.setBrush(QPalette::ButtonText,Qt::white );
    // q[question_no-1].q_object->setPalette(palette);
    answer=0;
//    MainWindow::on_pushButton_4_clicked();

    }
}

void MainWindow::on_radioButton_5_clicked()
{
    answer='e';
     qDebug()<<"answer is :"<<answer;
}




void MainWindow::on_pushButton_clicked()
{
    timer->stop();
   timer_sec->stop();
   QMessageBox::StandardButton resume;

   resume = QMessageBox::warning(this, "Paused", "Resume",
                                 QMessageBox::Ok);
   if (resume == QMessageBox::Close) {

        int k= store_answers_to_file();
        print_attended_question(k);
        verify_answers();
        calculate_score();

         emit MainWindow::valueChanged( Reasoning_marks, data_analysis_marks, gk_marks, english_marks);
     //QApplication::quit();
   }
   else

   {
     timer->start();
    timer_sec->start();
   }


}


void MainWindow::on_pushButton_5_clicked()
{


    frame_resoning->show();
    frame_Data_Analysis->hide();
    frame_General_Awareness->hide();
    frame_english->hide();

    q[0].q_object->click();
    ui->radioButton_1->click();

    ui->pushButton_5->setStyleSheet("background-color: rgb(85, 170, 0);");
    ui->pushButton_6->setStyleSheet("background-color: rgb(170, 170, 255);");
    ui->pushButton_7->setStyleSheet("background-color: rgb(170, 170, 255);");
    ui->pushButton_8->setStyleSheet("background-color: rgb(170, 170, 255);");
     ui->label_4->setText("you are seeing Reasoning sections");
}

void MainWindow::on_pushButton_7_clicked()
{

    frame_resoning->hide();
    frame_Data_Analysis->show();
    frame_General_Awareness->hide();
    frame_english->hide();

    q[Reasoning].q_object->click();
    ui->radioButton_1->click();

    ui->pushButton_7->setStyleSheet("background-color: rgb(85, 170, 0);");
     ui->pushButton_5->setStyleSheet("background-color: rgb(170, 170, 255);");
     ui->pushButton_6->setStyleSheet("background-color: rgb(170, 170, 255);");
     ui->pushButton_8->setStyleSheet("background-color: rgb(170, 170, 255);");
     ui->label_4->setText("you are seeing Data Analysis sections");
}

void MainWindow::on_pushButton_8_clicked()
{


    frame_resoning->hide();
    frame_Data_Analysis->hide();
    frame_General_Awareness->show();
    frame_english->hide();

    q[Reasoning+Data_Analysis].q_object->click();
    ui->radioButton_1->click();

     ui->pushButton_8->setStyleSheet("background-color: rgb(85, 170, 0);");
     ui->pushButton_5->setStyleSheet("background-color: rgb(170, 170, 255);");
     ui->pushButton_7->setStyleSheet("background-color: rgb(170, 170, 255);");
     ui->pushButton_6->setStyleSheet("background-color: rgb(170, 170, 255);");

 ui->label_4->setText("you are seeing General Awareness sections");
}
void MainWindow::on_pushButton_6_clicked()
{


    frame_resoning->hide();
    frame_Data_Analysis->hide();
    frame_General_Awareness->hide();
    frame_english->show();

    q[Reasoning+Data_Analysis+General_Awareness].q_object->click();
    ui->radioButton_1->click();


    ui->pushButton_6->setStyleSheet("background-color: rgb(85, 170, 0);");
    ui->pushButton_5->setStyleSheet("background-color: rgb(170, 170, 255);");
    ui->pushButton_7->setStyleSheet("background-color: rgb(170, 170, 255);");
    ui->pushButton_8->setStyleSheet("background-color: rgb(170, 170, 255);");

 ui->label_4->setText("you are seeing English Language sections");
}
void create_questions_button(int x, int y,int initial_val,int boundary_val,
                             QFrame * frame,int distanceX,int distanceY,
                             int size1,int size2,int no_of_button_in_one_line,int distance_between_button)
{
    int i,x2=117,y2=22;
    for( i=initial_val;i<boundary_val;i++)
    {

    q[i].q_object = new QToolButton(frame);
    q[i].q_object->setCheckable(true);

    //allignement
    if(i%no_of_button_in_one_line == 0  && i>initial_val)
    {
        x=x+distanceX;y=distanceY;
    }
    q[i].q_object->setGeometry(QRect(x,y , x2, y2));
    q[i].q_object->setFixedSize(size1,size2);
    y=y+distance_between_button;

        sprintf(sptr,"%d",i+1);
         q[i].q_object->setText(sptr);

    }

}
//void create_question_query()
//{

//           QString path=QString::number(question_paper_clicked);
//           path=quest_file_path_thread+path;
//           //QSqlDatabase *question_table;
//           question_table_=QSqlDatabase::addDatabase("QSQLITE");
//           question_table=& question_table_;
//           question_table->setDatabaseName(path);
//             if (!question_table->open())
//             {
//                qDebug() << "Error: connection with database fail:question table";
//             qDebug()<<question_table->lastError().text() ;
//             }
////query_question =query ;

//}
#if 0
void verify_answers_with_db()
{

    db_manage* correct_answer_table =new db_manage(question_paper_clicked,answer_file_path_thread);
    bool k=correct_answer_table->query->prepare("SELECT answers  FROM answer_table WHERE rowid =:x");
    assert(k!=false);

    db_manage* correct_answer_table =new db_manage(question_paper_clicked,answer_file_path_thread);
    bool k=correct_answer_table->query->prepare("SELECT answers  FROM answer_table WHERE rowid =:x");
    assert(k!=false);



    int init=0;
    char c[3]={0};
    char * line1;
    line1=&c[0];
    for(int i=1;i<=TOTAL_NO_QUESTIONS;i++)
    {
        correct_answer_table->query->bindValue(":x",i);
        k=correct_answer_table->query->exec();
        assert(k!=false);
        QString answer;
        int idName = correct_answer_table->query->record().indexOf("answers");
        correct_answer_table->query->next();
        answer = correct_answer_table->query->value(idName).toString();

         qDebug()<<"--------->"<<k+"   "<<db_manage_question->query->lastError().text() ;

         QByteArray ba = answer.toLatin1();
        line1 = ba.data();



}
#endif
