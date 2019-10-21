#include "displayinformation.h"
#include "ui_displayinformation.h"
#include "mainwindow.h"
displayInformation::displayInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayInformation)
{
    ui->setupUi(this);

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:\\Users\\mrpou\\Desktop\\European Vacation.db");    //connects to the database

    if(mydb.open()) qDebug("DB connection succesful");
    else{qDebug("Failed to connect to DB");}
}

displayInformation::~displayInformation()
{
    delete ui;
}

//Button for refreshing the table_view
void displayInformation::on_pushButton_clicked()
{
    displayInformation conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from Paris");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView->setModel(model);

    conn.connClose();
}
