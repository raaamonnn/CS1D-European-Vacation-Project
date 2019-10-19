#include "planning_page.h"
#include "ui_planning_page.h"
#include<vector>
#include<iostream>

Planning_Page::Planning_Page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Planning_Page)
{
    ui->setupUi(this);
}

Planning_Page::~Planning_Page()
{
    delete ui;
}


void Planning_Page::on_ChoosePath_pushButton_released()
{
    QString start;
    Planning_Page connection;

    if(connection.isOpen())
        connection.ConnClose();

    connection.ConnOpen();

    QSqlQueryModel * startModel = new QSqlQueryModel();
    QSqlQuery * startQuery = new QSqlQuery(connection.mydb);
    startQuery->prepare("Select DISTINCT Start FROM Distances");
    startQuery->exec();
    startModel->setQuery(*startQuery);

    ui->From_ComboBox->setModel(startModel);

    connection.ConnClose();
}

void Planning_Page::on_Save_Route_pushButton_released()
{
    ui->Route_TextEdit->setText(ui->Route_TextEdit->toPlainText() +
                                "From " + ui->From_ComboBox->currentText() +
                                " to\t" + ui->To_ComboBox->currentText() + '\n');
}

void Planning_Page::FindClosestCity(const QString& Start, std::vector<QString>& visitedCities, std::vector<QString>& visitedCitiesDistances)
{
    if(visitedCities.size() != TOTAL_CITY_COUNT)
    {
        Planning_Page connection;
        std::list<QString> End;
        std::list<QString> Distance;

        if(connection.isOpen())
            connection.ConnClose();
        connection.ConnOpen();

        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery * endCityQuery = new QSqlQuery(connection.mydb);
        QSqlQuery * distancesQuery = new QSqlQuery(connection.mydb);

        endCityQuery->prepare("Select End from Distances where start = '"+Start+"' order by [Distance] ASC");
        distancesQuery->prepare("Select Distance from Distances where start = '"+Start+"' order by [Distance] ASC");

        endCityQuery->exec();
        distancesQuery->exec();

        while(endCityQuery->next())
        {
            End.push_back(endCityQuery->value(0).toString());
            Distance.push_back(distancesQuery->value(0).toString());
        }

        for(; !CheckCity(End.front(), visitedCities); End.pop_front()) {}
        model->setQuery(*endCityQuery);

        visitedCities.push_back(End.front());
        visitedCitiesDistances.push_back(Distance.front());

        FindClosestCity(End.front(), visitedCities, visitedCitiesDistances);
    }
}

bool Compare(const QString& str1, const QString& str2);

bool Planning_Page::CheckCity(const QString& CITY, std::vector<QString>& visitedCities)
{
    bool notVisitedYet = true;
    for(unsigned int i = 0; i < visitedCities.size(); i++)
    {
        if(Compare(CITY, visitedCities[i]))
            notVisitedYet = false;
    }
    return notVisitedYet;
}

bool Compare(const QString& str1, const QString& str2)
{
    // returns true if they are equal
    if(str1.size() != str2.size())
        return false;
    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] != str2[i])
            return false;
    }
    return true;
}

void Planning_Page::on_EndCityList_doubleClicked(const QModelIndex &index)
{
    ui->To_ComboBox->setCurrentIndex(index.row());
}


void Planning_Page::on_London_PushButton_released()
{
    Planning_Page connection;
    std::vector<QString> visitedCities;
    std::vector<QString> visitedCitiesDistances;
    visitedCities.push_back("London");
    if(connection.isOpen())
        connection.ConnClose();
    FindClosestCity("London", visitedCities, visitedCitiesDistances);
    ui->StartCityTextEdit->setText("London");
    connection.ConnOpen();
    QSqlQueryModel * endModel = new QSqlQueryModel();
    QSqlQuery * endQuery = new QSqlQuery(connection.mydb);
    endQuery->prepare("Select End from Distances where Start = 'London' and Distance =( SELECT MIN(Distance) from Distances where Start = 'London')");
    endQuery->exec();
    endModel->setQuery(*endQuery);
    ui->EndCityList->setModel(endModel);
    QSqlQueryModel * distModel= new QSqlQueryModel();
    QSqlQuery * distQuery = new QSqlQuery(connection.mydb);
    ui->Route_TextEdit->setText(visitedCities[0]);
    for(unsigned int i = 1; i < visitedCities.size(); i++)
        ui->Route_TextEdit->setText(ui->Route_TextEdit->toPlainText() + '\n' + visitedCities[i]);
    qDebug() << endl;
    distQuery->prepare("SELECT MIN(Distance) from Distances where Start = 'London'");
    distQuery->exec();
    distModel->setQuery(*distQuery);
    ui->DistanceList->setModel(distModel);
}

void Planning_Page::on_Paris_PushButton_clicked()
{
    Planning_Page connection;
    std::vector<QString> visitedCities;
    std::vector<QString> visitedCitiesDistances;
    visitedCities.push_back("Paris");

    if(connection.isOpen())
        connection.ConnClose();

    FindClosestCity("Paris", visitedCities, visitedCitiesDistances);

    ui->StartCityTextEdit->setText("Paris");
    connection.ConnOpen();
    QSqlQueryModel * endModel = new QSqlQueryModel();
    QSqlQuery * endQuery = new QSqlQuery(connection.mydb);
    endQuery->prepare("Select End from Distances where Start = 'Paris' and Distance =( SELECT MIN(Distance) from Distances where Start = 'Paris')");
    endQuery->exec();
    endModel->setQuery(*endQuery);
    ui->EndCityList->setModel(endModel);

    QSqlQueryModel * distModel= new QSqlQueryModel();
    QSqlQuery * distQuery = new QSqlQuery(connection.mydb);

    ui->Route_TextEdit->setText(visitedCities[0]);

    for(unsigned int i = 1; i < visitedCities.size(); i++)
        ui->Route_TextEdit->setText(ui->Route_TextEdit->toPlainText() + '\n' + visitedCities[i]);

    distQuery->prepare("SELECT MIN(Distance) from Distances where Start = 'Paris'");
    distQuery->exec();
    distModel->setQuery(*distQuery);
    ui->DistanceList->setModel(distModel);
}

void Planning_Page::on_From_ComboBox_currentTextChanged(const QString &arg1)
{
    QString Start = ui->From_ComboBox->currentText();

    Planning_Page connection;

    if(connection.isOpen())
        connection.ConnClose();

    connection.ConnOpen();

    QSqlQuery * startQuery = new QSqlQuery(connection.mydb);
    startQuery->prepare("Select * FROM Distances where Start ='"+Start+"'");

    if(startQuery->exec())
    {
        while(startQuery->next())
        {
            ui->StartCityTextEdit->setText(Start);
            QSqlQueryModel * endModel = new QSqlQueryModel();
            QSqlQuery * endQuery = new QSqlQuery(connection.mydb);
            endQuery->prepare("Select End from Distances where Start ='"+Start+"' Order by [Distance] ASC");
            endQuery->exec();
            endModel->setQuery(*endQuery);
            ui->EndCityList->setModel(endModel);
            ui->To_ComboBox->setModel(endModel);

            QSqlQueryModel * distModel = new QSqlQueryModel();
            QSqlQuery * distQuery = new QSqlQuery(connection.mydb);
            distQuery->prepare("Select Distance from Distances where Start ='"+Start+"' Order by [Distance] ASC");
            distQuery->exec();
            distModel->setQuery(*distQuery);
            ui->DistanceList->setModel(distModel);
        }
        connection.ConnClose();
    } else {
        qDebug() << "Error in Executing Query";
    }
}

void Planning_Page::on_To_ComboBox_currentIndexChanged(const QString &arg1)
{
    Planning_Page connection;
    if(connection.isOpen())
        connection.ConnClose();
    connection.ConnOpen();

    QString Start = ui->From_ComboBox->currentText();
    QString End = ui->To_ComboBox->currentText();

    QSqlQueryModel * endModel = new QSqlQueryModel();
    QSqlQuery * endQuery = new QSqlQuery(connection.mydb);
    endQuery->prepare("Select End from Distances where Start ='"+Start+"' and End = '"+End+"'");
    endQuery->exec();
    endModel->setQuery(*endQuery);
    //ui->EndCityList->setModel(endModel);

    QSqlQueryModel * distModel = new QSqlQueryModel();
    QSqlQuery * distQuery = new QSqlQuery(connection.mydb);
    distQuery->prepare("Select Distance from Distances where Start ='"+Start+"' and End = '"+End+"'");
    distQuery->exec();
    distModel->setQuery(*distQuery);
    ui->DistanceList->setModel(distModel);
}
