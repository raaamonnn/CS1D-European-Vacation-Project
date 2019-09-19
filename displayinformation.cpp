#include "displayinformation.h"
#include "ui_displayinformation.h"


displayInformation::displayInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayInformation)
{
    ui->setupUi(this);
}

displayInformation::~displayInformation()
{
    delete ui;
}

void displayInformation::on_loadData_clicked()
{
        opendb();

        QSqlQuery* query = new QSqlQuery(mydb);

        QSqlQueryModel *model = new QSqlQueryModel();

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("City"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Food"));

        query->prepare("SELECT * FROM Berlin");
        query->exec();

        int i = 1;
        while (query->next()) {
            qDebug() << i++;
            QString City = query->value(0).toString();
            QString Food = query->value(1).toString();
            qDebug() << City << " " << Food << "\n";
        }

//        model->setQuery(*query);

        ui->table->setModel(model);

        closedb();

        qDebug() << (model->rowCount());
}
