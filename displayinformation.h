#ifndef DISPLAYINFORMATION_H
#define DISPLAYINFORMATION_H

#include <QDialog>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <databasemanager.h>

namespace Ui {
class displayInformation;
}

class displayInformation : public QDialog
{
    Q_OBJECT

public:
    explicit displayInformation(QWidget *parent = nullptr);
    displayInformation(DatabaseManager *databaseManager)
    {
        this->databaseManager = databaseManager;
    }

    ~displayInformation();

private slots:

    void on_loadData_clicked();

private:
    Ui::displayInformation *ui;
    DatabaseManager *databaseManager;
};

#endif // DISPLAYINFORMATION_H
