#include "mainwindow.h"
#include <string>
#include <iostream>
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <QSqlRecord>
#include <QMessageBox>
#include "addtasks.h"
using namespace std;


void connectTask()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//mysql的地址
    db.setPort(3306);
    db.setDatabaseName("todolist");//连接的数据库名称
    db.setUserName("root");//mysql登录名
    db.setPassword("");//mysql密码
    if(db.open())
     {
         qDebug()<<"success!";
         qDebug()<<db.driverName();
     }
}



void search()
{
    QSqlQuery query;
    bool success = query.exec("select * from information");
    if (!success){
        qDebug()<<"error";
        return ;
    }
    QSqlRecord rec = query.record();
    qDebug()<<rec.count();
    qDebug()<<rec;


}

int main(int argc, char *argv[])
{

    connectTask();
    //search();


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
