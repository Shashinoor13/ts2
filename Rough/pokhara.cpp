#include "pokhara.h"
#include "ui_pokhara.h"

Pokhara::Pokhara(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pokhara)
{
    ui->setupUi(this);
}

Pokhara::~Pokhara()
{
    delete ui;
}
