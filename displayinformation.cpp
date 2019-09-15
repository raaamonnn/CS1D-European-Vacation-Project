#include "displayinformation.h"
#include "ui_displayinformation.h"
#include <QtDebug>
#include <QSqlRecord>


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
    databaseManager->connect();

    if (!databaseManager->getDatabase().isOpen()) {
        qDebug() << "Error: connection with database fail";
        return;
    }
        QSqlQuery* query = new QSqlQuery(databaseManager->getPath());

        qDebug() << databaseManager->getPath();
        QSqlQueryModel *modal = new QSqlQueryModel();
        query->prepare("SELECT * From Amsterdam");
        query->exec();

        modal->setQuery(*query);

//        ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
//        modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Place"));
//        modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Food"));

//        int i;
//        QSqlRecord row;
//        for(i = 0, row = modal->record(i); !row.isEmpty(); i++, row = modal->record(i))
//        {
//           modal->insertRow(i);
//           //How do u Do this ???

//            // Get each field using `value` method of variabale 'row'
//            // and insert this fields to its corresponding cell in QTableWidget
//        }
        qDebug() << (modal->rowCount());

        ui->table->setModel(modal);

        //close database conection
}
