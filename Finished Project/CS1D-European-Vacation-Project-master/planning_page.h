#ifndef PLANNING_PAGE_H
#define PLANNING_PAGE_H

#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
const int TOTAL_CITY_COUNT = 10;

namespace Ui {
class Planning_Page;
}

class Planning_Page : public QDialog
{
    Q_OBJECT

public:
    explicit Planning_Page(QWidget *parent = nullptr);
    ~Planning_Page();

    bool isOpen() const { return connStatus; }

    void ConnOpen()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/zackj/Desktop/European Vacation Project/European Vacation.db");

        if(!mydb.open())
        {
            qDebug() << ("Disconnected...");

        } else {

            qDebug() << ("Connected.");
            connStatus = true;
        }
    }

    void ConnClose() { mydb.close(); connStatus = false; }



private slots:
    void on_ChoosePath_pushButton_released();

    void on_Save_Route_pushButton_released();

    void FindClosestCity(const QString&, std::vector<QString>&, std::vector<QString>&);

    bool CheckIfCityWasVisited(const QString&, std::vector<QString>&);

    void on_EndCityList_doubleClicked(const QModelIndex &index);

    void on_London_PushButton_released();

    void on_Paris_PushButton_clicked();

    void on_From_ComboBox_currentTextChanged(const QString &arg1);

    void on_To_ComboBox_currentIndexChanged(const QString &arg1);

    void on_ClearPath_PushButton_released();

    void on_BuyFood_PushButton_released();

private:
    Ui::Planning_Page *ui;
    QSqlDatabase mydb;
    bool connStatus{false};
    double totalCost{0};
};

#endif // PLANNING_PAGE_H
