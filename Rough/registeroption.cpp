#include "registeroption.h"
#include "ui_registeroption.h"
#include "registerpage.h"
#include "registryforcompanies.h"
#include "loginpage.h"
RegisterOption::RegisterOption(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterOption)
{
    ui->setupUi(this);
}

RegisterOption::~RegisterOption()
{
    delete ui;
}


void RegisterOption::on_as_a_Company_clicked()
{

    registryForCompanies regForComp ;
    hide() ;
    regForComp.exec() ;
}


void RegisterOption::on_as_a_User_clicked()
{
    registerpage regPage ;
    hide() ;
    regPage.exec() ;

}


void RegisterOption::on_Home_Icon_clicked()
{
    loginpage home ;
    hide() ;
    home.exec() ;
}

