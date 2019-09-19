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

void displayInformation::on_loadData_clicked()
{
    //db.opendb();

        QSqlQuery* query = new QSqlQuery( "DATABASE");

        QSqlQueryModel *modal = new QSqlQueryModel();
        query->prepare("SELECT * FROM Berlin");
        query->exec();

        modal->setQuery(*query);

        ui->table->setModel(modal);

        //db.closedb();
}
