#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include <QPaintEvent>
#include<qmessagebox.h>
#include <QtSql>
#include<assert.h>

#define no_of_option 5

#define mains_exam

#ifdef mains_exam
#define Reasoning 60
#define Data_Analysis 60
#define General_Awareness 40
#define English_Language 40
#define TOTAL_NO_QUESTIONS 200
#define  NO_OF_SECTIONS 4
#endif

#ifdef prelims_exam
#define Reasoning 35
#define Data_Analysis 35
#define English_Language 30
#define TOTAL_NO_QUESTIONS 100
#define  NO_OF_SECTIONS 3
#endif



#define section_1_questions Reasoning
#define section_2_questions Data_Analysis
#define section_3_questions General_Awareness
#define section_4_questions English_Language

#define cal_score(val1,val2) (val1-(0.25*val2))
#define cal_overall_score(x1,x2,x3,x4) (x1+x2+x3+x4)/4



namespace Ui {
class Result;
}

class Result : public QWidget
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = 0);
    ~Result();

private:
    Ui::Result *ui;

signals:

public slots:
    void setProgress(double Reasoning_marks_,double data_analysis_marks_,double gk_marks_,double english_marks_);


private slots:
    void on_pushButton_clicked();
};


class db_manage :public  QSqlDatabase
{
public:
  explicit db_manage(int question_paper_clicked,QString type_database);
QString path;
QSqlQuery *query;
QSqlDatabase *question_table;
  QSqlDatabase  question_table_;
~db_manage();
};


#endif // RESULT_H
