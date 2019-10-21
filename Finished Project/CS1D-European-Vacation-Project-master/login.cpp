#include "login.h"
#include "ui_login.h"
#include"admin.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    if(ui->lineEdit->text() != "password") ui->label_2->setText("INCORRECT PASSWORD");
    else
    {
        admin window;
        window.setModal(true);
        window.exec();
    }
}
