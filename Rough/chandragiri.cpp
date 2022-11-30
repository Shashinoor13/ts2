#include "chandragiri.h"
#include "ui_chandragiri.h"
#include<QDesktopServices>

chandragiri::chandragiri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chandragiri)
{
    ui->setupUi(this);
}

chandragiri::~chandragiri()
{
    delete ui;
}

void chandragiri::on_SeeMore_clicked()
{
     QDesktopServices::openUrl(QUrl("", QUrl::TolerantMode));

}

