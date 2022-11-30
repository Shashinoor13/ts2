#include "registryforcompanies.h"
#include "ui_registryforcompanies.h"
#include "loginpage.h"
#include <QMessageBox>
#include<QString>
#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>

registryForCompanies::registryForCompanies(QWidget *parent) : QDialog(parent),
                                                              ui(new Ui::registryForCompanies)
{
    ui->setupUi(this);
}

registryForCompanies::~registryForCompanies()
{
    delete ui;
}

void registryForCompanies::on_register_PushButton_clicked()
{

    QSqlDatabase db01 = QSqlDatabase::addDatabase("QSQLITE");

    db01.setDatabaseName("C:/Users/PC/OneDrive/Desktop/tryingDB/Companies.db");
   // db01.open() ;
    if (db01.open())
    {
        QDate EstdDate = ui->Established_dateEdit_2->date();
        QString DOE = EstdDate.toString();
        QString CompanyName = ui->CompanyName->text();
        QString location = ui->location->text();
        QString nation = ui->Nation->text();
        QString comEmail = ui->CompanyEmail->text();
        QString username = ui->Company_Username->text();
        QString password = ui->passwordComp->text();
        QString documentationNo = ui->documentNo->text();

        QString docType = ui->comboBox->currentText();
        QString Contact = ui->ContactNo->text();

        if (ui->termsAndConditions->isChecked())
        {
            if (CompanyName != "" && location != "" && DOE != "" && nation != "" && username != "" && comEmail != "" && Contact != "" && password != "")
            {

                int em = 0, contct = 0, pw = 0;
                QRegularExpression re("(\\w+)(\\w*)@(\\w+)(\\.(\\w+))+");
                if (re.match(comEmail).hasMatch())
                    em = 1;

                if (Contact.length() >= 10)
                    contct = 1;
                if (password.length() >= 8)
                    pw = 1;

                if (pw)
                {
                    if (em)
                    {
                        if (contct)
                        {

                            QSqlQuery qry, check , checkUN;
                            int user_id = 0; int checkID = 0 ;
                            if (check.exec("select * from COMPANY where username='" + username + "' "))
                            {
                                while (check.next())
                                {
                                    user_id++;
                                }
                            }

                            if (user_id == 1)
                            {
                                QMessageBox::information(this, "Error", "UserName already taken.");
                            }
                             /*if(checkUN.exec("select * from COMPANY where username ='"+ username+ "' "))
                             {
                                 while(checkUN.next()){
                                     checkID++ ;
                                 }
                             }
                             if(checkID == 1)
                             {
                                 QMessageBox::information(this, "Error", "Username already taken") ;
                             }*/
                            else
                            {
                                QString registerQuery = "INSERT INTO COMPANY([Name],[Address],[Email],[Contact],[username],[password],[DateOfEstd],[Nation],[DocumentNo],[DocumentType])VALUES(:name, :location, :email, :contact,:username,:password,:date,:nation,:DocNum,:DocType)" ;
                                qry.prepare(registerQuery) ;

                                qry.bindValue(":name", CompanyName);
                                qry.bindValue(":location", location);
                                qry.bindValue(":email", comEmail);
                                qry.bindValue(":contact", Contact);
                                qry.bindValue(":username", username);
                                qry.bindValue(":password", password);
                                qry.bindValue(":date", DOE);
                                qry.bindValue(":nation", nation) ;
                                qry.bindValue(":DocType", docType);

                                qry.bindValue(":DocNum", documentationNo);



                               if (qry.exec())
                                {


                                   QMessageBox::information(this, "Information", "Your account is created");
                                }
                                // else QMessageBox::information(this, "information", "Id failed");
                             }

                        }
                        else
                        {
                            ui->ContactNo->setStyleSheet("border:1px solid rgb(144, 10, 18) ");
                             QMessageBox::information(this, "Error", "Please Enter valid Phone number.");
                        }
                    }
                    else
                    {
                        ui->CompanyEmail->setStyleSheet("border: 1px solid rgb(144, 10, 18) ");
                        QMessageBox::critical(this, "Error", "Please Enter valid Email.");
                    }
                }
                else
                {
                    ui->passwordComp->setStyleSheet("border: 1px solid rgb(144, 10, 18)");
                    QMessageBox::critical(this, "Error", "Password must be at least 8 character long.");
                }
            }
            else
            {
                 QMessageBox::critical(this, "Error", "Fill in all the input fields to create account.");
            }
        }
        else
        {
            QMessageBox::critical(this, "Terms and Conditions", "You must agree to our terms and conditions.");
        }
    }
    else
    {
        QMessageBox::critical(this, "DB", "Database not Connected");
    }
        db01.close();
}

/*

*/

void registryForCompanies::on_go_to_loginPage_clicked()
{
    loginpage loginpage02 ;
    hide() ;
    loginpage02.exec() ;
}

