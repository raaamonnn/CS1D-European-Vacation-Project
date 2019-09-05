#ifndef DISPLAYINFORMATION_H
#define DISPLAYINFORMATION_H

#include <QDialog>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

namespace Ui {
class displayInformation;
}

class displayInformation : public QDialog
{
    Q_OBJECT

public:
    explicit displayInformation(QWidget *parent = nullptr);
    ~displayInformation();

private slots:
    void on_loadCities_clicked();

    void on_loadFood_clicked();

    void on_loadData_clicked();

private:
    Ui::displayInformation *ui;
};

#endif // DISPLAYINFORMATION_H
