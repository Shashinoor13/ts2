#include "namobuddha.h"
#include "ui_namobuddha.h"

Namobuddha::Namobuddha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Namobuddha)
{
    ui->setupUi(this);
}

Namobuddha::~Namobuddha()
{
    delete ui;
}
