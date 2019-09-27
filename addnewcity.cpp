#include "addnewcity.h"
#include "ui_addnewcity.h"
#include "QVector"

AddNewCity::AddNewCity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewCity)
{
    ui->setupUi(this);
}

AddNewCity::~AddNewCity()
{
    delete ui;
}

void AddNewCity::on_addFood_clicked()
{
    foodArray.push_front(ui->enterFood->text());
    priceArray.push_front(ui->price->text());

    ui->enterFood->clear();
    ui->enterFood->insert("Enter Food");
}

void AddNewCity::on_pushData_clicked()
{

}
