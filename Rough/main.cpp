#include "loginpage.h"
#include<mainwindow.h>
#include"aftercompanylogin.h"
#include"profile.h"
#include"login2.h"
#include"aftercompanylogin.h"

#include <QApplication>
#include<QMessageBox>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlRelationalTableModel>

QSqlDatabase db01;

int main(int argc, char *argv[])
{
    db01=QSqlDatabase::addDatabase("QSQLITE");
    db01.setDatabaseName("/Users/shashinoorghimire/Desktop/Companies.db");
    QApplication a(argc, argv);
    login2 l2;
    l2.show();
    return a.exec();
}
