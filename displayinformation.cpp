#include "displayinformation.h"
#include "ui_displayinformation.h"
#include <QtDebug>


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

    DatabaseManager database("C:/Users/annea/OneDrive/Desktop/CS1D-European-Vacation-Project-master/European Vacation");
    database.connect();

    if (!database.getDatabase().isOpen()) {
        qDebug() << "Error: connection with database fail";
        return;
    }
        QSqlQuery* query = new QSqlQuery("C:/Users/annea/OneDrive/Desktop/CS1D-European-Vacation-Project-master/European Vacation");

        QSqlQueryModel *modal = new QSqlQueryModel();
        query->prepare("SELECT * From Amsterdam");
        query->exec();

        modal->setQuery(*query);

        ui->table->setModel(modal);
        //close database conection
}

//void displayInformation::connectDatabase()
//{
//    QSqlDatabase Database;

//        Database.addDatabase("European Vacation");
//        Database.setDatabaseName("C:/Users/annea/OneDrive/Desktop/CS1D-European-Vacation-Project-master");

//}
