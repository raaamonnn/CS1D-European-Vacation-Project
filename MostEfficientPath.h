#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

const int TOTAL_CITY_COUNT = 10;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

    void ConnClose()
    {
        mydb.close();
        connStatus = false;
    }
    void FindClosestCity(const QString& Start, std::vector<QString>& VisitedCities);

private slots:
    void on_ChoosePath_pushButton_released();

    void on_From_ComboBox_currentIndexChanged(const QString &arg1);

    void on_Paris_PushButton_released();

    void on_To_ComboBox_currentIndexChanged(const QString &arg1);

    void on_Save_Route_pushButton_released();

    void on_EndCityList_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    bool connStatus{false};
};

#endif // MAINWINDOW_H
