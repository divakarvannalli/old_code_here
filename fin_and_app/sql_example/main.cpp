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

char * radio_button(char * arr ,char * ch)
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

void add_questions(int question_paper_clicked,QString path)
{

    QSqlDatabase *question_table;
  QSqlDatabase  question_table_=QSqlDatabase::addDatabase("QSQLITE");
  question_table=& question_table_;
  question_table->setDatabaseName(path);
    if (!question_table->open())
    {
       qDebug() << "Error: connection with database fail:question table";
    }
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
int i=1;
      while (fgets(line, sizeof line, question_fptr) != NULL) /* read a line */
         {

        query_questions.prepare("INSERT INTO questions(id,question_desc,question) "
                              "VALUES (:id, :question_desc, :question)");

        query_questions.bindValue(":id", i);
        QString qstn ;
        qstn.sprintf("Thad Beaumont");
        query_questions.bindValue(":question_desc", qstn);

        qstn.sprintf(line);
        query_questions.bindValue(":question", qstn);
        bool k =  query_questions.exec();

        qDebug()<<"--------->"<<k+"   "<<query_questions.lastError().text() ;
      i++;

      }
      QSqlQuery query(*question_table);
              query.exec("SELECT * FROM questions");
      int idName = query.record().indexOf("question");
      while (query.next())
      {
         QString name = query.value(idName).toString();
         qDebug() << name;
      }
      fclose(question_fptr);
      int len=strlen(line);
      free(ch);
      free(ch2);
}

void add_options(int question_paper_clicked,QString path)
{
    char line[256]={0};
    int count=0;
    int qa_no;bool ok=false;
    char arr[5][15]={0};
    char* ch,*ch2;
            ch=(char*)malloc(256);
        ch2=(char*)malloc(18);


        strcpy(ch,options_file_path_thread);
        sprintf(ch2,"%d.txt\0",question_paper_clicked);
        strcat(ch,ch2);
    FILE *    option_fptr=fopen(ch,"r");
        memset(ch,0,sizeof(ch));
        memset(ch2,0,sizeof(ch));

      if(option_fptr== NULL)
      {
          qDebug()<<"cant open option file thus exiting";
           exit(2);
      }


      QSqlDatabase *question_table;
    QSqlDatabase  question_table_=QSqlDatabase::addDatabase("QSQLITE");
    question_table=& question_table_;
    question_table->setDatabaseName(path);
      if (!question_table->open())
      {
         qDebug() << "Error: connection with database fail:question table";
      }
       QSqlQuery query_questions(*question_table);
int i=1;
QString qstn ;

         while (fgets(line, sizeof line, option_fptr) != NULL) /* read a line */
            {
             i++;
             query_questions.prepare("INSERT INTO option_table(id,option1,option2,option3,option4,option5) "
                                   "VALUES (:id,:option1, :option2, :option3,:option4,:option5)");

             query_questions.bindValue(":id", i);

             ch=radio_button(arr[0],line+2);
             qstn.sprintf(arr[0]);
              query_questions.bindValue(":option1",qstn);

              ch=radio_button(arr[1],ch+1);
              qstn.sprintf(arr[1]);
               query_questions.bindValue(":option2",qstn);

               ch=radio_button(arr[2],ch+1);
               qstn.sprintf(arr[2]);
                query_questions.bindValue(":option3",qstn);

                ch=radio_button(arr[3],ch+1);
                qstn.sprintf(arr[3]);
                 query_questions.bindValue(":option4",qstn);

                 ch=radio_button(arr[4],ch+1);
                 qstn.sprintf(arr[4]);
                  query_questions.bindValue(":option5",qstn);

                  bool k =  query_questions.exec();

                  qDebug()<<"--------->"<<k+"   "<<query_questions.lastError().text() ;
                i++;
            }
         QSqlQuery query(*question_table);
         QSqlQuery query1(*question_table);
         QSqlQuery query2(*question_table);
         QSqlQuery query3(*question_table);
         QSqlQuery query4(*question_table);
         query3.exec("SELECT * FROM option_table");
         query4.exec("SELECT * FROM option_table");

                  query.prepare("SELECT * FROM option_table WHERE rowid =:x");
                 query.bindValue(":x",1);
  int idName = query.record().indexOf("option_table");
      if (query.exec())
         {
           idName = query.record().indexOf("option1");
                 //while(query.next())
                   {
                        query.next();
                     QString name = query.value(idName).toString();
                     qDebug() << name<<"\n";
                   }

               //      QString name= query.seek(1,0);
         }
         query1.exec("SELECT * FROM option_table");
         idName = query1.record().indexOf("option2");
                  while (query1.next())
                  {
                     QString name = query1.value(idName).toString();
                     qDebug() << name<<"\n";
                  }
                  query2.exec("SELECT * FROM option_table");

                  idName = query2.record().indexOf("option3");
                           while (query2.next())
                           {
                              QString name = query2.value(idName).toString();
                              qDebug() << name<<"\n";
                           }
                           idName = query3.record().indexOf("option4");
                                    while (query3.next())
                                    {
                                       QString name = query3.value(idName).toString();
                                       qDebug() << name<<"\n";
                                    }
              idName = query4.record().indexOf("option5");
                 while (query4.next())
                  {
                    QString name = query4.value(idName).toString();
                     qDebug() << name<<"\n";
                   }
         fclose(option_fptr);
         int len=strlen(line);
//free(ch);
//free(ch2);
}
void add_answers(int question_paper_clicked,QString path)
{
    char line[256]={0};
    int count=0;
    int qa_no;bool ok=false;
    char arr[5][15]={0};
    char* ch,*ch2;
            ch=(char*)malloc(256);
        ch2=(char*)malloc(18);


        strcpy(ch,answer_file_path_thread);
        sprintf(ch2,"%d.txt\0",question_paper_clicked);
        strcat(ch,ch2);
    FILE *    option_fptr=fopen(ch,"r");
        memset(ch,0,sizeof(ch));
        memset(ch2,0,sizeof(ch));
        if(option_fptr== NULL)
        {
            qDebug()<<"cant open option file thus exiting";
             exit(2);
        }


      QSqlDatabase *question_table;
      QSqlDatabase  question_table_=QSqlDatabase::addDatabase("QSQLITE");
      question_table=& question_table_;
      question_table->setDatabaseName(path);
        if (!question_table->open())
        {
           qDebug() << "Error: connection with database fail:question table";
        }
         QSqlQuery query_questions(*question_table);
  int i=0;
  QString qstn ;

  while (fgets(line, sizeof line, option_fptr) != NULL) /* read a line */
 {
      i++;
  bool  k=   query_questions.prepare("INSERT INTO answer_table(id,answers) "
                            "VALUES (:id,:answers)");

      query_questions.bindValue(":id", i);
 query_questions.bindValue(":answers", line);
  k = query_questions.exec();
  qDebug()<<"--------->"<<k+"   "<<query_questions.lastError().text() ;
}
  FILE *  fptr=fopen("/home/user/Desktop/database/all_answers.txt","w");
  QSqlQuery query(*question_table);
 if(query.exec("SELECT * FROM answer_table"))
{
int idName =query.record().indexOf("answers");
     while(query.next())
     {
         QString name = query.value(idName).toString();
         QByteArray ba = name.toLatin1();
     char *c_str2 = ba.data();
         fputs(c_str2,fptr);
          qDebug() << name<<"\n";

     }
 }
fclose(fptr);


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
//add_questions(1,path);

path="/home/user/Desktop/database/option_table";
//options_table=create_table(path,2);
//add_options(1,path);
path="/home/user/Desktop/database/answer_table";
answers_table=create_table(path,3);
add_answers(1,path);
path="/home/user/Desktop/database/entered_answer_table";
entered_answres_table=create_table(path,2);


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
//         query_questions.prepare("INSERT INTO questions(id,question_desc,question) "
//                               "VALUES (:id, :question_desc, :question)");

//         query_questions.bindValue(":id", 1);
//         QString qstn ;
//         qstn.sprintf("Thad Beaumont");
//         query_questions.bindValue(":question_desc", qstn);
//         query_questions.bindValue(":question", qstn);
//           k= query_questions.exec();
//           qDebug()<<"--------->"<<k+"   "<<query_questions.lastError().text() ;
        qDebug()<<k;
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
