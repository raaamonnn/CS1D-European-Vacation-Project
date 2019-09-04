#include "displayinformation.h"
#include "ui_displayinformation.h"

displayInformation::displayInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayInformation)
{
    ui->setupUi(this);
}

displayInformation::~displayInformation()
{
    delete ui;
}

void displayInformation::on_loadCities_clicked()
{
    //1.	Display the list of European cities and their distances from Paris.
}

void displayInformation::on_loadFood_clicked()
{
    //2.	Display all the traditional food items for any given city.
}
