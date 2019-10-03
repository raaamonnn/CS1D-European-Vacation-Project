#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);

}

admin::~admin()
{
    delete ui;
}

void admin::on_comboBox_activated(const QString &arg1)
{

   QString city = arg1;

   admin conn;
   QSqlQueryModel* model = new QSqlQueryModel();
   conn.connOpen();
   QSqlQuery* qry = new QSqlQuery(conn.mydb);

   qry->prepare("select * from '"+city+"'");
   qry->exec();

   model->setQuery(*qry);
   ui->tableView->setModel(model);

   conn.connClose();
}

void admin::on_pushButton_clicked() //adding a new food item
{
    QString food, price, table;
    table = ui->comboBox->itemText(ui->comboBox->currentIndex());
    food = ui->lineEdit->text();
    price = ui->lineEdit_2->text();

    admin db;
    db.connOpen();
    QSqlQuery query;
    query.prepare("insert into '"+table+"' (Food, Price) values ('"+food+"','"+price+"')");

    if(query.exec()){
        qDebug()<<"Changes Made";
        db.connClose();
    }
    else{qDebug()<<"Changes failed";
    query.lastError();}

    db.connClose();

    admin conn;
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from '"+table+"'");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView->setModel(model);

    conn.connClose();

}

void admin::on_pushButton_3_clicked() //change price of food item
{
    QString food, new_price, table;
    food = ui->lineEdit_4->text();
    new_price = ui->lineEdit_5->text();
    table = ui->comboBox->itemText(ui->comboBox->currentIndex());

    admin db;
    db.connOpen();
    QSqlQuery query;
    query.prepare("update '"+table+"' set Price='"+new_price+"' where Food = '"+food+"'");
    query.exec();
    db.connClose();

    admin conn;     //refreshing the table
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from '"+table+"'");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView->setModel(model);

    conn.connClose();
}

void admin::on_pushButton_2_clicked() //remove a food item entirely
{
    QString food, table;
    food = ui->lineEdit_3->text();
    table = ui->comboBox->itemText(ui->comboBox->currentIndex());

    admin db;
    db.connOpen();
    QSqlQuery query;
    query.prepare("delete from '"+table+"' where Food = '"+food+"'");
    if (query.exec())
    {
        std::cout << "query success";
    }
    else {
        std::cout << "query failed";
    }
    db.connClose();

    admin conn;     //refreshing the table
    QSqlQueryModel* model = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from '"+table+"'");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView->setModel(model);
}
