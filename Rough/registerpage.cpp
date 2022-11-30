#include "registerpage.h"
#include "ui_registerpage.h"
#include "loginpage.h"
#include <QMessageBox>
#include <QRadioButton>


registerpage::registerpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerpage)
{
    ui->setupUi(this);
}

registerpage::~registerpage()
{
    delete ui;
}



void registerpage::on_pushButton_clicked()
{
    QSqlDatabase db01 = QSqlDatabase::addDatabase("QSQLITE");

     db01.setDatabaseName("C:/Users/PC/OneDrive/Desktop/tryingDB/Companies.db");

     QDate DOB = ui->dateEdit->date();
     QString date_of_birth = DOB.toString();

     QString firstname = ui->lineEdit_6->text();
     QString lastname = ui->lineEdit_5->text();
     QString fullName = firstname + lastname ;

     QString email = ui->lineEdit_7->text();

     QString username = ui->lineEdit_8->text();


     QString password = ui->lineEdit_4->text();


     QString gender = ui->comboBox->currentText();

     QString nationality = ui->lineEdit_2->text();

     //opening databsaae
       db01.open();
       QSqlQuery aa;
         //preparing and binding the values
      QString registerQuery = "INSERT INTO USER([FullName],[Email],[username],[password],[nationality],[DOB],[gender])VALUES(:fullName,:email,:username,:password, :nationality, :dob, :gender)" ;
         aa.prepare(registerQuery);
      //  aa.bindValue(":id",  );
        aa.bindValue(":fullName",fullName);
        aa.bindValue(":email",email);
        aa.bindValue(":username", username);
        aa.bindValue(":password", password);
        aa.bindValue(":nationality", nationality);
        aa.bindValue(":dob", date_of_birth);
        aa.bindValue(":gender", gender);



if (ui->radioButton->isChecked()){
     if(firstname != "" && lastname != "" && email != "" && username != "" && password != "" && date_of_birth != "" && gender != "" && nationality != "" && ui->radioButton->isChecked())
     {
         //executing the commands after checking all the criterias.
        if( aa.exec()){
         QMessageBox::information(this,"","account created sucessfully");  }
         db01.close();
         loginpage login;
         hide();
         login.exec();
         }
         else if(firstname == "" || lastname == "" || email == "" || username == "" || password == "" || date_of_birth == "" || gender == "" || nationality == "" || ui->radioButton->isChecked()){
         QMessageBox::information(this,"Missing","All the fields are mandatory");
        registerpage reg;
        hide();
        reg.exec();
     }
     }
   else  QMessageBox::warning(this,"Warnning!","You have not aggred to out terms and conditions.");

}
void registerpage::on_pushButton_2_clicked()
{

    loginpage login;
    hide();
    login.exec();
}

