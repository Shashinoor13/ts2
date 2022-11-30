#include "profile.h"
#include "QtSql/qsqldatabase.h"
#include "QtSql/qsqlquery.h"
#include "ui_profile.h"
#include<QMessageBox>

extern QString username;
extern QSqlDatabase db01;

profile::profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
    ui-> Pwd->hide();
    ui-> Uinfo->hide();
    db01.open();
}

profile::~profile()
{
    delete ui;
}

void profile::on_ChangePassword_clicked()
{
    ui-> Pwd->show();
}


void profile::on_UpdateInfo_clicked()
{
    ui-> Uinfo->show();
}


void profile::on_PwdChange_clicked()
{
    QString password1=ui->NewPassword->text();
    QString password2=ui->ConfNewPassword->text();
    QSqlQuery qry01;
    QMessageBox::information(this,"",username);
    qry01.prepare("Update USER set password='"+password1+"' where username=:x");
    qry01.bindValue(":x",username);
    qry01.exec();
}

