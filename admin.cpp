#include "admin.h"
#include "ui_admin.h"
#include "qaxobject.h"
#include <cctype>
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

void admin::on_comboBox_activated(const QString &arg1) //changing city
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

    std::string checker = ui->lineEdit->text().toStdString();
    std::string checker2 = ui->lineEdit_2->text().toStdString();
    if(isAlpha(checker)){
        if(isNum(checker2)){
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
        else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Invalid Price Input (only numeric characters allowed)");
            messageBox.setFixedSize(500,200);
        }
    }
    else {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Invalid Name Input (only alphabetic characters allowed)");
        messageBox.setFixedSize(500,200);
        }

}

void admin::on_pushButton_3_clicked() //change price of food item
{
    QString food, new_price, table;
    std::string checker = ui->lineEdit_4->text().toStdString();
    std::string checker2 = ui->lineEdit_5->text().toStdString();
    if(isAlpha(checker)){
        if(isNum(checker2)){


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
        else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Invalid Price Input (only numeric characters allowed)");
            messageBox.setFixedSize(500,200);
        }
    }
    else {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Invalid Name Input (only alphabetic characters allowed)");
        messageBox.setFixedSize(500,200);
        }
}

void admin::on_pushButton_2_clicked() //remove a food item entirely
{
    QString food, table;
    std::string checker = ui->lineEdit_3->text().toStdString();

    if(isAlpha(checker)){
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
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Invalid Input (only alphabetic characters allowed)");
        messageBox.setFixedSize(500,200);
    }
}

void admin::on_pushButton_4_clicked() //add new city
{
    //1)access the file
        //2)insert stuff into distances table in database
        //3)create the 2 new tables for the cities and insert food in database
        //4)refresh the qtableview

        //---------------------------------------------------------
        // ***1)and 2)read the both new cities and their distances***
        //---------------------------------------------------------
        auto excel     = new QAxObject("Excel.Application");
        auto workbooks = excel->querySubObject("Workbooks");
        auto workbook  = workbooks->querySubObject("Open(const QString&)","C:\\Users\\mrpou\\Downloads\\Copy of European Distances and Foods");
        auto sheets    = workbook->querySubObject("Worksheets");
        auto sheet     = sheets->querySubObject("Item(int)", 2);    // use third worksheet


        for (int r = 2; (r <= 47); ++r)
        {
            auto cCell = sheet->querySubObject("Cells(string,string,string)",r,1);
            QString firstCity = cCell->dynamicCall("Value()").toString();
                 cCell = sheet->querySubObject("Cells(string,string,string)",r,2);
            QString secondCity = cCell->dynamicCall("Value()").toString();
                 cCell = sheet->querySubObject("Cells(string,string,string)",r,3);
            QString distance = cCell->dynamicCall("Value()").toString();
            qDebug() << cCell->dynamicCall("Value()").toString();

            admin db;
            db.connOpen();
            QSqlQuery query;
            query.prepare("insert into Distances (Start, End, Distance) values ('"+firstCity+"','"+secondCity+"','"+distance+"')"); //for some reason this does not add to the database

            if(query.exec()){
                qDebug()<<"Changes Made";
                db.connClose();
            }
            else{qDebug()<<"Changes failed";
            query.lastError();}
            db.connClose();
        }

        //---------------------------------------------------------
        //***3)create the 2 new tables for the cities and insert food in database***
        //---------------------------------------------------------

        sheet     = sheets->querySubObject("Item(int)", 1);    // use second worksheet
        if(true)
        {
            admin db;
            db.connOpen();
            QSqlQuery query;
            query.prepare("CREATE TABLE Stockholm (Food TEXT, Price INTEGER)"); //for some reason this does not add to the database IT SHOULD CREATE STOCKHOLLM IN DB
            if(query.exec()){
                qDebug()<<"Changes Made";
                db.connClose();
            }
            else{qDebug()<<"Changes failed";
            query.lastError();}
            db.connClose();

            for (int r = 3; (r <= 5); ++r) //just reads Stockholm stuff from DB
            {
                auto  cCell = sheet->querySubObject("Cells(string,string,Double)",r,2);
                QString food = cCell->dynamicCall("Value()").toString();
                qDebug() << cCell->dynamicCall("Value()").toString();
                     cCell = sheet->querySubObject("Cells(string,string,Double)",r,3);
                double pricex = cCell->dynamicCall("Value()").toDouble();
                pricex = pricex/10000;

                QString price = QString::number(pricex);
                qDebug() << price;

                admin db;
                db.connOpen();
                QSqlQuery query;
                query.prepare("insert into Stockholm (Food, Price) values ('"+food+"','"+price+"')"); //***for some reason this does not add to the database SHOULD INSERT FOOD AND PRICE OF CITY IN THE DB***

                if(query.exec()){
                    qDebug()<<"Changes Made";
                    db.connClose();
                }
                else{qDebug()<<"Changes failed";
                query.lastError();}
                db.connClose();
            }
        }

        admin db;
        db.connOpen();
        QSqlQuery query;
        query.prepare("CREATE TABLE Vienna (Food TEXT, Price INTEGER)"); //for some reason this does not add to the database IT SHOULD CREATE VIENNA IN DB
        if(query.exec()){
            qDebug()<<"Changes Made";
            db.connClose();
        }
        else{qDebug()<<"Changes failed";
        query.lastError();}
        db.connClose();

        for (int r = 7; (r <= 9); ++r) //just reads Vienna stuff
        {
            auto  cCell = sheet->querySubObject("Cells(string,string,Double)",r,2);
            QString food = cCell->dynamicCall("Value()").toString();
                 cCell = sheet->querySubObject("Cells(string,string,Double)",r,3);
                 double pricex = cCell->dynamicCall("Value()").toDouble();
                 pricex = pricex/10000;

                 QString price = QString::number(pricex);
                 qDebug() << price;

            admin db;
            db.connOpen();
            QSqlQuery query;
            query.prepare("insert into Vienna (Food, Price) values ('"+food+"','"+price+"')"); //***for some reason this does not add to the database SHOULD INSERT FOOD AND PRICE OF CITY IN THE DB***

            if(query.exec()){
                qDebug()<<"Changes Made";
                db.connClose();
            }
            else{qDebug()<<"Changes failed";
            query.lastError();}
            db.connClose();
        }

        // don't forget to quit Excel
        excel->dynamicCall("Quit()");
        delete excel;

        //---------------------------------------------------------
        //***4)Refreshes the qtable????***
        //---------------------------------------------------------
        QString table = ui->comboBox->itemText(ui->comboBox->currentIndex());
        admin conn;
        QSqlQueryModel* model = new QSqlQueryModel();
        conn.connOpen();
        QSqlQuery* qry = new QSqlQuery(conn.mydb);

        qry->prepare("select * from '"+table+"'");
        qry->exec();

        model->setQuery(*qry);
        ui->tableView->setModel(model);

        conn.connClose();
        //---------------------------------------------------------
        ui->pushButton_4->disconnect();
    }


