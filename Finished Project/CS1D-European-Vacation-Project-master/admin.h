#ifndef ADMIN_H
#define ADMIN_H

#include <QMessageBox>
#include <cctype>
#include <QDialog>
#include <string>
#include <QtSql>
#include <iostream>

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/zackj/Desktop/European Vacation Project/European Vacation.db");    //connects to the database

        if(mydb.open())
        {
            qDebug("DB connection succesful");
            return true;

        } else {

            qDebug("Failed to connect to DB");
            return false;
        }
    }

    bool isAlpha(std::string checker)
    {
        checker.erase(remove(checker.begin(), checker.end(), ' ' ), checker.end());
        for(int i = 0; i < checker.size(); i++)
        {
            if(!isalpha(checker[i]))
                return false;
            else
                i++;
        }
        return true;
    }

    bool isNum(std::string checker)
    {
        checker.erase( remove(checker.begin(), checker.end(), '.'),checker.end());
        for(int i = 0; i < checker.size(); i++)
        {
            if(!isdigit(checker[i]))
                return false;
            else
                i++;
        }
        return true;
    }

    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::admin *ui;
};

#endif // ADMIN_H
