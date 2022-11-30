#include "aftercompanylogin.h"
#include "ui_aftercompanylogin.h"
#include<QtSql>
#include<QMessageBox>
#include"loginpage.h"
#include<QSqlDatabase>
extern QString username ;
extern QSqlDatabase db01;

AfterCompanyLogin::AfterCompanyLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AfterCompanyLogin)
{
    ui->setupUi(this);
    ui->companyUsername->setText(username);
    ui->frame->hide();
    QSqlQueryModel * modal=new QSqlQueryModel () ;
        if(db01.open()){
            QSqlQuery* qry = new QSqlQuery(db01);
            qry->prepare("select * from BOOKINGS");
            if (qry->exec()){
                 modal->setQuery(*qry);
                 ui->tableView->setModel(modal);
            }
        }


}


AfterCompanyLogin::~AfterCompanyLogin()
{
    delete ui;
}









void AfterCompanyLogin::on_signout_clicked()
{
    loginpage log ;
    hide() ;
    log.exec();
}


/*
void donor_request::on_search_textChanged(const QString &arg1)
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/user/OneDrive/Documents/Final/Databases/final.db");
    if(db.open())
    {
        QString search=ui->search->text();
        QSqlQueryModel *modal =new QSqlQueryModel();

        QSqlQuery * qry=new QSqlQuery();
        qry->prepare("select * from donor_details where donor_name like '"+search+"%"+"'");
        qry->bindValue(":search", search);
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
        qDebug()<<(modal->rowCount());
    }
}
 */






void AfterCompanyLogin::on_customers_clicked()
{
ui->frame->show();

}


void AfterCompanyLogin::on_lineEdit_textChanged(const QString &arg1)
{
    if(db01.open())
    {
        QString search=ui->lineEdit->text();
        QSqlQueryModel *modal =new QSqlQueryModel();

        QSqlQuery * qry=new QSqlQuery();
        qry->prepare("select * from BOOKINGS where username like '"+search+"%"+"'");
        qry->bindValue(":search", search);
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
        qDebug()<<(modal->rowCount());
    }
}

