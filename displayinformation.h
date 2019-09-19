#ifndef DISPLAYINFORMATION_H
#define DISPLAYINFORMATION_H

#include <QDialog>
#include <QtSql>
namespace Ui {
class displayInformation;
}

class displayInformation : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

    bool opendb(){
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("//put database name here");

    if(!mydb.open()){
        qDebug() << "error opening database\n";
        return false;
    }

    else{
        qDebug() << "database opened\n";
        return true;
    }

    }

    void closedb(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    explicit displayInformation(QWidget *parent = nullptr);
    ~displayInformation();

private slots:
    void on_loadData_clicked();

private:
    Ui::displayInformation *ui;
};

#endif // DISPLAYINFORMATION_H
