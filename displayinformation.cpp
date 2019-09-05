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
    //    if (!getDatabaseManager()->getDatabase().isOpen()) {
    //        qDebug() << "Error: connection with database fail";
    //        return;
    //    }
        QSqlQuery* query = new QSqlQuery( "DATABASE");

        QSqlQueryModel *modal = new QSqlQueryModel();
        query->prepare("SELECT CITIES and DISTANCE and FOOD FROM DATABASE");
        query->exec();

        modal->setQuery(*query);

        ui->table->setModel(modal);

        //close database conection
}
