#include "loginpage.h"
#include "ui_loginpage.h"
#include "registeroption.h"
#include "mainwindow.h"
#include "aftercompanylogin.h"
#include"ui_loginpage.h"
#include"loginpage.h"
#include<QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QtCore>
#include<QTime>
#include<QPixmap>


extern QSqlDatabase db01;
extern QString username;

void login();

loginpage::loginpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginpage)
{
    ui->setupUi(this);
}

loginpage::~loginpage()
{
    delete ui;
}


void loginpage::on_login_clicked()
{
    username = ui->userName->text();
    QString password = ui->passWord->text();

    if(db01.open())
    {
        QSqlQuery qry;
        int count=0;
        if(qry.exec("select * from USER where username='"+username+"' and password='"+password+"'"))
        {
            while(qry.next())
            {
               // QString user_id="setText(qry.value(0).toString())";
                count++;
            }
            if(count==1)
            {

                this->close();
                    MainWindow *mainWindow = new MainWindow();
                    mainWindow->show();
                    hide();
                     db01.close() ;
            }
           else
            {
                ui->label_6->setText("Username/Password Incorrect");
            }
        }
       if(qry.exec("select * from COMPANY where username='"+username+"' and password='"+password+"'"))
        {
            while(qry.next())
            {
               // QString user_id="setText(qry.value(0).toString())";
                count++;
            }
            if(count==1)
            {

                this->close();
                    AfterCompanyLogin *newPage = new AfterCompanyLogin();
                    newPage->show();
                     db01.close() ;
            }
            else
            {
                ui->label_6->setText("Username/Password Incorrect");
            }
        }
       /*else
       {
          ui->label_6->setText("Username/Password Incorrect");
       }*/




    }
    else
        QMessageBox::information(this,"Connection","Database not connected");
}



void loginpage::on_signUp_clicked()
{
    RegisterOption regOpt ;
    hide();
    regOpt.exec() ;

}



