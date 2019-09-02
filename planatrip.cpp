#include "planatrip.h"
#include "ui_planatrip.h"

planATrip::planATrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::planATrip)
{
    ui->setupUi(this);
}

planATrip::~planATrip()
{
    delete ui;
}
