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

void admin::on_login_clicked()
{
    //database stuff
    //if login correct then show next screen
    destroy();
    adminView.show();
}
