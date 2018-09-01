#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtSql>
#include <QMainWindow>
#define  quest_file_path_thread  "/home/user/appandroid/questions/question"
#define options_file_path_thread "/home/user/appandroid/options/options"
#define  answer_file_path_thread "/home/user/appandroid/answers/answers"
//char* instruction_file_path_thread="/home/user/appandroid/instructions.txt";
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class DbManager
{
public:
    DbManager(const QString& path);
    bool addPerson(const QString& name);
    bool person_exists(const QString& name);\
    bool delete_person (const QString& name);\
private:
    QSqlDatabase m_db;
};

#endif // MAINWINDOW_H
