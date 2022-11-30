#include "booknow.h"
#include "ui_booknow.h"
#include "contactus.h"
#include "mainwindow.h"
#include<QSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>

extern QString username ;



BookNow::BookNow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookNow)
{
    ui->setupUi(this);
 ui->tableView->hide();
    ui->UserName->setText(username);
}

BookNow::~BookNow()
{
    delete ui;
}

void BookNow::on_ContactUs_PushButton_clicked()
{
    ContactUs developersInfo ;
    developersInfo.setModal(true);
    developersInfo.exec() ;


}


void BookNow::on_home_clicked()
{
    this->close();
      MainWindow *home = new MainWindow();
      home->show();

}





void BookNow::on_see_Companies_clicked()
{
    QSqlDatabase db01=QSqlDatabase::addDatabase("QSQLITE");
    db01.setDatabaseName("C:/Users/PC/OneDrive/Desktop/tryingDB/Companies.db");
    ui->tableView->show();

   /* QSqlDatabase db01=QSqlDatabase::addDatabase("QSQLITE");
    db01.setDatabaseName("C:/Users/PC/OneDrive/Desktop/tryingDB/Companies.db");*/

    db01.open() ;
    QSqlQueryModel *modal =new QSqlQueryModel();

            QSqlQuery * qry=new QSqlQuery();
            qry->prepare("select companyID,username,Name, Address, Email, Contact from COMPANY");
            qry->exec();
            modal->setQuery(*qry);
            ui->tableView->setModel(modal);
            qDebug()<<(modal->rowCount());

            db01.close() ;


}


void BookNow::on_book_button_clicked()
{
    QSqlDatabase db01 = QSqlDatabase::addDatabase("QSQLITE");

     db01.setDatabaseName("C:/Users/PC/OneDrive/Desktop/tryingDB/Companies.db");



     QString userID ;
     QString from = ui->From->text();
     QString to = ui->destination->currentText();

     QDate depart = ui->departDate->date();
     QDate arrive = ui->returnDate->date();

     QString departDate = depart.toString();
     QString arriveDate = arrive.toString();




    QString  company_username = ui->companyName->text();








     //opening databsaae
       db01.open();
       QSqlQuery aa , update;
         //preparing and binding the values
      QString registerQuery = "INSERT INTO BOOKINGS([Customers_Name],[From],[To],[Departure_Date],[Arrival_Date],[Company_Username])VALUES(:name,:from,:to,:depart, :arrive, :companyusername)" ;
         aa.prepare(registerQuery);

        aa.bindValue(":name", username);
        aa.bindValue(":from",from);
        aa.bindValue(":to", to);
        aa.bindValue(":depart", departDate);
        aa.bindValue(":arrive", arriveDate);

        aa.bindValue(":companyusername", company_username);
      // aa.exec() ;
        if( aa.exec())
        {
            update.prepare("UPDATE USER SET company_username='"+company_username+"' WHERE username = '"+username+"' ");
            update.exec() ;



         QMessageBox::information(this,"","Booking confirmed");
        }
/*
        {
            QMessageBox:: information(this, "", "Booking failed");
        }*/
         db01.close();

}







