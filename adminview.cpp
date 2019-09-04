#include "adminview.h"
#include "ui_adminview.h"

adminView::adminView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminView)
{
    ui->setupUi(this);
}

adminView::~adminView()
{
    delete ui;
}

void adminView::on_loadData_clicked()
{
    // USED TO GET DATA FROM DATABASE TO FILL UP THE TABLE
//    Login conn;
//    QSqlQueryModel * modal = new QSqlQueryModel();

//    conn.connOpen();
//    QSqlQuery *qry = new QSqlQuery(conn.mydb);

//    qry->prepare("select * from employeeinfo");

//    qry->exec();
//    modal->setQuery(*qry);
//    ui->tableView->setModel(modal);

//    conn.connClose();
//    qDebug >> (modal->rowCount());
}



void adminView::on_new_2_clicked()
{
    //a.	Provide the capability to add new European cities and their corresponding food items by having your program read from the input file given to the class
}

void adminView::on_changePrice_clicked()
{
    //b.	Provide the capability to change the prices of the traditional food items
}

void adminView::on_addFood_clicked()
{
    //c.	Provide the capability to add new traditional food items
}

void adminView::on_deleteFood_clicked()
{
    //d.	Provide the capability to delete traditional food items
}
