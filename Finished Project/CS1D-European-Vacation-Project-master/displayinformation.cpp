#include "displayinformation.h"
#include "ui_displayinformation.h"
#include "mainwindow.h"
#include "planning_page.h"
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


void displayInformation::on_pushButton_2_clicked()
{
    displayInformation conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from Amsterdam");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView->setModel(model);

    conn.connClose();
}

void displayInformation::on_pushButton_3_clicked()
{
    displayInformation conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from Berlin");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView_2->setModel(model);

    conn.connClose();
}

void displayInformation::on_pushButton_4_clicked()
{
    displayInformation conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from Brussels");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView_3->setModel(model);

    conn.connClose();
}

void displayInformation::on_pushButton_5_clicked()
{
    displayInformation conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from Budapest");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView_4->setModel(model);

    conn.connClose();
}

void displayInformation::on_pushButton_6_clicked()
{
    displayInformation conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from Hamburg");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView_5->setModel(model);

    conn.connClose();
}

void displayInformation::on_pushButton_7_clicked()
{
    displayInformation conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from Lisbon");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView_6->setModel(model);

    conn.connClose();
}

void displayInformation::on_pushButton_8_clicked()
{
    displayInformation conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from London");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView_7->setModel(model);

    conn.connClose();
}

void displayInformation::on_pushButton_9_clicked()
{
    displayInformation conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from Madrid");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView_8->setModel(model);

    conn.connClose();
}

void displayInformation::on_pushButton_10_clicked()
{
    displayInformation conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from Paris");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView_9->setModel(model);

    conn.connClose();
}

void displayInformation::on_pushButton_11_clicked()
{
    displayInformation conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from Prague");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView_10->setModel(model);

    conn.connClose();
}

void displayInformation::on_pushButton_12_clicked()
{
    displayInformation conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from Rome");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView_11->setModel(model);

    conn.connClose();
}

void displayInformation::on_pushButton_13_clicked()
{
    displayInformation conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from Stockholm");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView_12->setModel(model);

    conn.connClose();
}

void displayInformation::on_pushButton_14_clicked()
{
    displayInformation conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from Vienna");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView_13->setModel(model);

    conn.connClose();
}

void displayInformation::on_pushButton_clicked()
{
    Planning_Page window;
    window.setModal(true);
    window.exec();
}
