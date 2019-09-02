#include "addlanguage.h"
#include "ui_addlanguage.h"

AddLanguage::AddLanguage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddLanguage)
{
    ui->setupUi(this);
}

AddLanguage::~AddLanguage()
{
    delete ui;
}
