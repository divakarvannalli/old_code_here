#include "myserver.h"
#include "mythread.h"
extern bool push_button_clicked;
extern int port_no_to_connect;
int student_count_no;
MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
}

void MyServer::startServer()
{
    int port = port_no_to_connect;
    if(port>=5000)
    {
    if(!this->listen(QHostAddress::Any, port))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening to port " << port << "...";
    }
    }
}
MyThread *thread_global;
// This function is called by QTcpServer when a new connection is available.
void MyServer::incomingConnection(qintptr socketDescriptor)
{


    // We have a new connection
    qDebug() << socketDescriptor << " Connecting...";

    // Every new connection will be run in a newly created thread
    MyThread *thread = new MyThread(socketDescriptor, this);
thread_global=thread;
    // connect signal/slot
    // once a thread is not needed, it will be beleted later

    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));


    thread->start();

}
void MyServer::forced_quit_app()
{
   if(thread_global)
   thread_global->forced_quit_app();
}

//
