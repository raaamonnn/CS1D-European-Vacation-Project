#include "practice.h"
#include "ui_practice.h"

Practice::Practice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Practice)
{
    ui->setupUi(this);
}

Practice::~Practice()
{
    delete ui;
}
