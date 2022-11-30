#include "login2.h"
#include "QtSql/qsqldatabase.h"
#include "QtSql/qsqlquery.h"
#include "registeroption.h"
#include "ui_login2.h"
#include"mainwindow.h"
#include"aftercompanylogin.h"
#include<QMessageBox>


QString username;
extern QSqlDatabase db01;
login2::login2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login2)
{
    ui->setupUi(this);
}

login2::~login2()
{
    delete ui;
}

void login2::on_Login_clicked()
{
    RegisterOption regOpt ;
    hide();
    regOpt.exec() ;

}



void login2::on_Register_clicked()
{
    username = ui->username->text();
    QString password = ui->password->text();

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
                ui->label->setText("Username/Password Incorrect");
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
                ui->label->setText("Username/Password Incorrect");
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

