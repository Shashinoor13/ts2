#include "hazarsidi.h"
#include "ui_hazarsidi.h"

hazarsidi::hazarsidi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hazarsidi)
{
    ui->setupUi(this);
}

hazarsidi::~hazarsidi()
{
    delete ui;
}
