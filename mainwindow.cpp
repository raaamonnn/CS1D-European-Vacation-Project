#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userdbmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    QSqlDatabase m_db;
    QString path = "C:/Users/annea/Summer2019Database.db";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);
    m_db.open();

    if (!m_db.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }

    QString username = ui->username->text();
    QString password = ui->password->text();

    QSqlQueryModel *queryModel = new QSqlQueryModel;
    queryModel->setQuery(QString("SELECT * FROM [User Database] WHERE Username = '%1' AND Password = '%2'").arg(username).arg(password)); //select the row of where the Username == username
//    queryModel->query().exec(); //execute it (not really sure why or what this does
    destroy(); //destroy current window
    if(queryModel->record(0).value(3).toString()== '1') //if id is equal to one log in as user
    {
         user.showMaximized();
         user.setUsername(username);
         user.setPassword(password);
    }
    else if(queryModel->record(0).value(3).toString()== '2')
    {
         dbManager.showMaximized();
    }
    else
    {
         qWarning("Wrong Password or Username");
    }



}
