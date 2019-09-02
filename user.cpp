#include "user.h"
#include "ui_user.h"
#include "mainwindow.h"
#include "addlanguage.h"
#include "QListWidgetItem"
User::User(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
}

User::~User()
{
    delete ui;
}

void User::on_practice_clicked()
{

}

void User::on_editLanguages_clicked()
{
    QSqlQueryModel *queryModel = new QSqlQueryModel;
    queryModel->setQuery(QString("SELECT * FROM [User Database] WHERE Username = '%1' AND Password = '%2'").arg(username).arg(password)); //select the row of where the Username == username
//    queryModel->query().exec(); //execute it (not really sure why or what this does
    AddLanguage *newScreen = new AddLanguage;
    newScreen->showNormal();

//    QListWidgetItem * item = new QListWidgetItem("New Item");
//    item->setFlags(item->flags() | Qt::ItemIsEditable);
//    ui->listWidget->addItem(item);
}
