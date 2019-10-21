#include "planning2.h"
#include "ui_planning2.h"

planning2::planning2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::planning2)
{
    ui->setupUi(this);
}

planning2::~planning2()
{
    delete ui;
}


