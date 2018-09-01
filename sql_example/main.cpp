#include "mainwindow.h"
#include <QApplication>
QSqlDatabase * create_table(QString,int select);
QSqlDatabase *question_table;
QSqlDatabase *options_table;
QSqlDatabase *answers_table;
QSqlDatabase *entered_answres_table;

void add_questions();
void add_options();
void add_answers();

void add_questions(int question_paper_clicked)
{
     QSqlQuery query_questions(*question_table);
    FILE *question_fptr;
   // int lineNumber=0;
 char* ch,*ch2;
         ch=(char*)malloc(256);
     ch2=(char*)malloc(18);
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


//     if(lineNumber <0)
//         exit(-1);
int i=0;
      while (fgets(line, sizeof line, question_fptr) != NULL) /* read a line */
         {

        query_questions.prepare("INSERT INTO questions (id, question_desc, question) "
                              "VALUES (:id, :question_desc, :question)");

        query_questions.bindValue(":id", i);
          query_questions.bindValue(":question_desc", "Thad Beaumont");
          query_questions.bindValue(":question", line);
        bool k =  query_questions.exec();
        qDebug()<<"--------->"<<k+"   "<<query_questions.lastError().text() ;
      i++;

      }

      fclose(question_fptr);
      int len=strlen(line);
      free(ch);
      free(ch2);
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

#if 0
  DbManager database("/home/user/Desktop/database/people.db");


  bool ret;

 ret = database.addPerson("divakar");

ret = database.person_exists("divakar");
ret = database.delete_person("divakar");
#endif


QString path="/home/user/Desktop/database/question_table";
question_table=create_table(path,1);

path="/home/user/Desktop/database/option_table";
options_table=create_table(path,2);

path="/home/user/Desktop/database/answer_table";
answers_table=create_table(path,2);

path="/home/user/Desktop/database/entered_answer_table";
entered_answres_table=create_table(path,2);


add_questions(1);
  return app.exec();
}


QSqlDatabase *  create_table(QString path_1 ,int select)
{
    QString path=path_1;

    QSqlDatabase *question_table;
  QSqlDatabase  question_table_=QSqlDatabase::addDatabase("QSQLITE");
  question_table=& question_table_;
  question_table->setDatabaseName(path);
    if (!question_table->open())
    {
       qDebug() << "Error: connection with database fail:question table";
    }
    QSqlQuery query_questions(*question_table);

    switch (select)
    {
    bool k;
    case 1:
    {
         k=query_questions.exec("create table IF NOT EXISTS questions  "
                   "(id integer primary key, "
                   "question_desc varchar(1000), "
                   "question varchar(300))");
         qDebug() <<k;
        break;
    }
    case 2:
    {
        k=query_questions.exec("create table IF NOT EXISTS option_table "
                      "(id integer primary key, "
                      "option1 varchar(20), "
                      "option2 varchar(20),"
                      "option3 varchar(20),"
                      "option4 varchar(20),"
                      "option5 varchar(20), "
                      "option6 varchar(20))");
           qDebug() <<k;
        break;
    }
    case 3:
    {
            k=query_questions.exec("create table IF NOT EXISTS  answer_table"
                       "(id integer primary key, "
                       "answers varchar(1000))");
            qDebug() <<k;
        break;
    }
    case 4:
    {
            k=query_questions.exec("create table IF NOT EXISTS entered_answer_table"
                       "(id integer primary key, "
                       "answer_entered varchar(1000))");
            qDebug() <<k;
        break;
    }
    default:
        break;
    }


qDebug()<<"--------->"<<query_questions.lastError().text() ;
     return question_table;


//question_table->close();
//query_questions.finish();

//    QSqlDatabase option_table;
//    option_table=QSqlDatabase::addDatabase("QSQLITE");
//    path="/home/user/Desktop/database/option table";
//    option_table.setDatabaseName(path);
//    if (!option_table.open())
//    {
//       qDebug() << "Error: connection with database fail:option_table";
//    }
//    QSqlQuery query_option(option_table);

//    k=query_option.exec("create table  option_table"
//               "(id integer primary key, "
//               "option1 varchar(1000), "
//               "option2 varchar(300),"
//               "option3 varchar(300),"
//               "option4 varchar(300),"
//               "option5 varchar(300), "
//               "option6 varchar(300), )");
//    qDebug() <<k;



//    QSqlDatabase answer_table;
//    answer_table=QSqlDatabase::addDatabase("QSQLITE");
//     path="/home/user/Desktop/database/answers table";
//    answer_table.setDatabaseName(path);
//    if (!answer_table.open())
//    {
//       qDebug() << "Error: connection with database fail:answers table";
//    }
//      QSqlQuery query_answers(answer_table);

//    k=query_answers.exec("create table  answer_table"
//               "(id integer primary key, "
//               "answers varchar(1000), )");
//    qDebug() <<k;


//    QSqlDatabase entered_answer_table;
//    entered_answer_table=QSqlDatabase::addDatabase("QSQLITE");
//    path="/home/user/Desktop/database/entered_answer_table";
//    entered_answer_table.setDatabaseName(path);
//    if (!answer_table.open())
//    {
//       qDebug() << "Error: connection with database fail:entered_answer_table";
//    }
//        QSqlQuery query_enteredanswers(entered_answer_table);

//    k=query_enteredanswers.exec("create table  entered_answer_table"
//               "(id integer primary key, "
//               "answer_entered varchar(1000), )");
//    qDebug() <<k;

}
