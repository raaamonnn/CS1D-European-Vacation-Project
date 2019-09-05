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

void planATrip::on_parisTrip_clicked()
{

}

void planATrip::on_londonTrip_clicked()
{

}

void planATrip::on_customTrip_clicked()
{

}
