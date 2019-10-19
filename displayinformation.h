#ifndef DISPLAYINFORMATION_H
#define DISPLAYINFORMATION_H


#include <QDialog>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>

namespace Ui {
class displayInformation;
}

class displayInformation : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen(){
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:\\Users\\mrpou\\Desktop\\European Vacation.db");    //connects to the database

        if(mydb.open()){
            qDebug("DB connection succesful");
            return true;
        }
        else{
            qDebug("Failed to connect to DB");
            return false;}
        }
    explicit displayInformation(QWidget *parent = nullptr);
    ~displayInformation();

private slots:




    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_clicked();

private:
    Ui::displayInformation *ui;
};

#endif // DISPLAYINFORMATION_H
