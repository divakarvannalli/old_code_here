#include "ui_result.h"
#include<QPainter>
#include "result.h"
//#include"common.h"
//attended each question
db_manage * result_db;
extern int question_paper_clicked;

extern int attended_section_1_question;
extern int attended_section_2_question;
extern int attended_section_3_question;
extern int attended_section_4_question;

extern int not_answered_resoning,wrong_answered_resoning,
not_answered_data_analysis,wrong_answered_data_analysis,
not_answered_GK,wrong_answered_GK,
not_answered_english,wrong_answered_english;

extern double overall_score;

extern int correct_reasoning;
extern int correct_data_analysis;
extern int correct_GK;
extern int correct_english;


extern float neg_factor;

extern double   Reasoning_marks ;
extern double    data_analysis_marks ;
extern double   gk_marks;
extern double      english_marks;

Result::Result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Result)
{

    ui->setupUi(this);

}

Result::~Result()
{
    delete ui;
}


void Result::setProgress(double Reasoning_marks_,double data_analysis_marks_,double gk_marks_,double english_marks_)
{
#ifdef perc
  double resoning_perc = (Reasoning_marks_/Reasoning)*100;
  double data_analysis_perc = (data_analysis_marks_/Data_Analysis)*100;
   double gk_perc = (gk_marks_/General_Awareness)*100;
   double eng_perc = (english_marks_/English_Language)*100;
   double average = (resoning_perc+data_analysis_perc+gk_perc+eng_perc)/4;
#else
    double resoning_perc  = Reasoning_marks_;
    double data_analysis_perc = data_analysis_marks_;
    double gk_perc = gk_marks_;
     double eng_perc= english_marks_;
     double average = (resoning_perc+data_analysis_perc+gk_perc+eng_perc)/4;
#endif

ui->progressBar_Reasoning->setFormat("Reasoning         "+QString::number(resoning_perc)+"%");
ui->progressBar_Reasoning->setValue((int)resoning_perc);

ui->progressBar_datanalysis->setFormat("Data analysis   "+QString::number(data_analysis_perc)+"%");
ui->progressBar_datanalysis->setValue((int)data_analysis_perc);

ui->progressBar_gk->setFormat("General awareness        "+QString::number(gk_perc)+"%");
ui->progressBar_gk->setValue((int)gk_perc);

ui->progressBar_english->setFormat("English             "+QString::number(eng_perc)+"%");
ui->progressBar_english->setValue((int)eng_perc);

 ui->progressBar_average->setFormat("Average            "+QString::number(average)+"%");
 ui->progressBar_average->setValue((int)average);

QDir dir;
QString result_path=dir.currentPath()+"/result_path";
result_db = new db_manage(question_paper_clicked,result_path);
bool k = result_db->query->exec("create table IF NOT EXISTS result_table "

                                "(section_1_questions double,"
                                "section_2_questions double,"
                                "section_3_questions double,"
                                "section_4_questions double,"
                                "attended_section_1_question double,"
                                 "attended_section_2_question double,"
                                 "attended_section_3_question double,"
                                 "attended_section_4_question double,"
                                "correct_reasoning double,"
                                "correct_data_analysis double,"
                                "correct_GK double ,"
                                "correct_english double ,"
                                "wrong_answered_resoning double,"
                                "wrong_answered_data_analysis double,"
                                "wrong_answered_GK double,"
                                "wrong_answered_english double,"
                                "neg_factor_resoning double,"
                                  "neg_factor_data_analysis double,"
                                  "neg_factor_GK double,"
                                  "neg_factor_english double,"
                                "Reasoning_marks double,"
                                "data_analysis_marks double,"
                                "gk_marks double,"
                                "english_marks double,"
                                "total_question double,"
                                "total_attended_question,"
                                "correct_answers double,"
                                "wrong_answers double,"
                                "negative_marks double,"
                                "total_marks double)");


if(k!=true)
{
    qDebug()<<"failed to create db for answer table error:"<<result_db->query->lastError();
    assert(0);
}

    /*add stuff inside the table view*/
    QString line = "hello" ;
    int row=ui->tableWidget->rowCount();
    int col=ui->tableWidget->columnCount();
    double arr[row][col];
        arr[0][0] = section_1_questions;
        arr[1][0] = section_2_questions;
        arr[2][0] = section_3_questions;
        arr[3][0] = section_4_questions;

        arr[0][1] = attended_section_1_question;
        arr[1][1] = attended_section_2_question;
        arr[2][1] = attended_section_3_question;
        arr[3][1] = attended_section_4_question;

        arr[0][2] = correct_reasoning;
        arr[1][2] = correct_data_analysis;
        arr[2][2] = correct_GK;
        arr[3][2] = correct_english;

        arr[0][3] = wrong_answered_resoning;
        arr[1][3] = wrong_answered_data_analysis;
        arr[2][3] = wrong_answered_GK;
        arr[3][3] = wrong_answered_english;

        arr[0][4] = neg_factor*wrong_answered_resoning;
        arr[1][4] = neg_factor*wrong_answered_data_analysis;
        arr[2][4] = neg_factor*wrong_answered_GK;
        arr[3][4] = neg_factor*wrong_answered_english;

        arr[0][5] = Reasoning_marks;
        arr[1][5] =data_analysis_marks;
        arr[2][5] = gk_marks;
        arr[3][5] =english_marks;

        arr[4][0]=  arr[0][0]+ arr[1][0]+ arr[2][0]+ arr[3][0];
        arr[4][1]=attended_section_1_question+attended_section_2_question+
                attended_section_3_question+attended_section_4_question;
        arr[4][2]=correct_reasoning+correct_data_analysis+
                   correct_GK+correct_english;
        arr[4][3]=wrong_answered_resoning+wrong_answered_data_analysis+
                wrong_answered_GK+wrong_answered_english;
        arr[4][4]=arr[0][4]+arr[1][4]+arr[2][4]+arr[3][4];
        arr[4][5]=overall_score;


    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        for(int j=0; j<ui->tableWidget->columnCount(); j++)
        {
            QTableWidgetItem *pCell = ui->tableWidget->item(i, j);
            if(!pCell)
            {
                pCell = new QTableWidgetItem;
                ui->tableWidget->setItem(i, j, pCell);
            }
            line=QString::number(arr[i][j]);
            pCell->setText(line);
             result_db->query->prepare("INSERT INTO result_table  WHERE rowid =:x");
             result_db->query->bindValue(":x",arr[i][j]);
           bool k =  result_db->query->exec();
           if(k!=true)
           {
               qDebug()<<"failed to create db for answer table error:"<<result_db->query->lastError();
               assert(0);
           }
        }
    }












 this->show();

}



void Result::on_pushButton_clicked()
{
    QMessageBox::StandardButton k;
    k=QMessageBox::question(this, "Test", "Quit?",
               QMessageBox::Yes|QMessageBox::No);
    if(k==QMessageBox::Yes)
    QApplication::quit();


}
