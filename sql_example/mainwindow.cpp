#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>


DbManager::DbManager(const QString& path)
{
   m_db = QSqlDatabase::addDatabase("QSQLITE");
   m_db.setDatabaseName(path);
//CREATE TABLE people(ids integer primary key, name text);
   if (!m_db.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }
}
bool DbManager::addPerson(const QString& name)
{
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;
   query.prepare("INSERT INTO people (name) VALUES (:name)");
   query.bindValue(":name", name);
   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "addPerson error:  "
                 << query.lastError();
   }

   return success;
}

bool DbManager::delete_person(const QString& name)
{
       bool   success;
    if (person_exists(name))
    {
       QSqlQuery query;
       query.prepare("DELETE FROM people WHERE name = (:name)");
       query.bindValue(":name", name);
     success = query.exec();

       if(!success)
       {
           qDebug() << "removePerson error: "
                    << query.lastError();
       }
    }

return success;
}

bool DbManager::person_exists(const QString&  name)
{
QSqlQuery query;
query.prepare("SELECT name FROM people WHERE name = (:name)");
query.bindValue(":name", name);

if (query.exec())
{
    return true;
   if (query.next())
   {
    return true;
   }

}
 return false;
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{





   ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
