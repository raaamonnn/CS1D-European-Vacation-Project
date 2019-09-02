#include "dbmanager.h"
#include "ui_dbmanager.h"
#include "mainwindow.h"

dbManager::dbManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dbManager)
{
    ui->setupUi(this);
}

dbManager::~dbManager()
{
    delete ui;
}

void dbManager::on_getData_clicked()
{
    QString path = "C:/Users/annea/Summer2019Database.db";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }
}

void dbManager::on_updateData_clicked()
{

}

void dbManager::on_addLanguage_clicked()
{
}

void dbManager::on_editLanguage_clicked()
{

}

void dbManager::on_deleteLanguage_clicked()
{

}

