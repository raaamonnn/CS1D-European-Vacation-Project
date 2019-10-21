#include "planning_page.h"
#include "ui_planning_page.h"
#include <vector>
#include <iostream>
#include <iomanip>

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
    ui->Route_TextBrowser->setText   (ui->Route_TextBrowser->toPlainText()    + ui->From_ComboBox->currentText()          + '\n');
    ui->Route_TextBrowser_2->setText (ui->Route_TextBrowser_2->toPlainText()  + ui->To_ComboBox->currentText()            + '\n');
    ui->Distance_TextBrowser->setText(ui->Distance_TextBrowser->toPlainText() + ui->Distance_TextBrowser_2->toPlainText() + '\n');
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

        endCityQuery->prepare       ("Select End from Distances where start = '"+Start+"' order by [Distance] ASC");
        distancesQuery->prepare("Select Distance from Distances where start = '"+Start+"' order by [Distance] ASC");

        endCityQuery->exec();
        distancesQuery->exec();

        while(endCityQuery->next() && distancesQuery->next())
        {
            End.push_back(endCityQuery->value(0).toString());
            Distance.push_back(distancesQuery->value(0).toString());
        }

        for(; !CheckIfCityWasVisited(End.front(), visitedCities); End.pop_front()) {Distance.pop_front();}

        model->setQuery(*endCityQuery);
        model->setQuery(*distancesQuery);

        visitedCities.push_back(End.front());
        visitedCitiesDistances.push_back(Distance.front());

        FindClosestCity(End.front(), visitedCities, visitedCitiesDistances);
    }
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

bool Planning_Page::CheckIfCityWasVisited(const QString& CITY, std::vector<QString>& visitedCities)
{
    bool notVisitedYet = true;

    for(unsigned int i = 0; i < visitedCities.size(); i++)
    {
        if(Compare(CITY, visitedCities[i]))
            notVisitedYet = false;
    }
    return notVisitedYet;
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
    ui->StartCity_TextBrowser->setText("London");
    connection.ConnOpen();

    QSqlQueryModel * endModel = new QSqlQueryModel();
    QSqlQuery * endQuery = new QSqlQuery(connection.mydb);

    endQuery->prepare("Select End from Distances where Start = 'London' and Distance =( SELECT MIN(Distance) from Distances where Start = 'London')");
    endQuery->exec();
    endModel->setQuery(*endQuery);
    ui->EndCityList->setModel(endModel);

    QSqlQueryModel * distModel= new QSqlQueryModel();
    QSqlQuery * distQuery = new QSqlQuery(connection.mydb);

    ui->Route_TextBrowser->setText(visitedCities[0]);
    ui->Route_TextBrowser_2->setText(visitedCities[1]);
    ui->Distance_TextBrowser->setText(visitedCitiesDistances[0]);

    for(unsigned int i = 1; i < visitedCities.size() - 1; i++)
    {
        ui->Route_TextBrowser->setText(ui->Route_TextBrowser->toPlainText() + '\n' + visitedCities[i]);
        ui->Route_TextBrowser_2->setText(ui->Route_TextBrowser_2->toPlainText() + '\n' + visitedCities[i+1]);
        ui->Distance_TextBrowser->setText(ui->Distance_TextBrowser->toPlainText() + '\n' + visitedCitiesDistances[i]);
    }

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
    ui->StartCity_TextBrowser->setText("Paris");
    connection.ConnOpen();

    QSqlQueryModel * endModel = new QSqlQueryModel();
    QSqlQuery * endQuery = new QSqlQuery(connection.mydb);

    endQuery->prepare("Select End from Distances where Start = 'Paris' and Distance =( SELECT MIN(Distance) from Distances where Start = 'Paris')");
    endQuery->exec();
    endModel->setQuery(*endQuery);
    ui->EndCityList->setModel(endModel);

    QSqlQueryModel * distModel= new QSqlQueryModel();
    QSqlQuery * distQuery = new QSqlQuery(connection.mydb);

    ui->Route_TextBrowser->setText(visitedCities[0]);
    ui->Route_TextBrowser_2->setText(visitedCities[1]);
    ui->Distance_TextBrowser->setText(visitedCitiesDistances[0]);

    for(unsigned int i = 1; i < visitedCities.size() - 1; i++)
    {
        ui->Route_TextBrowser->setText(ui->Route_TextBrowser->toPlainText() + '\n' + visitedCities[i]);
        ui->Route_TextBrowser_2->setText(ui->Route_TextBrowser_2->toPlainText() + '\n' + visitedCities[i+1]);
        ui->Distance_TextBrowser->setText(ui->Distance_TextBrowser->toPlainText() + '\n' + visitedCitiesDistances[i]);
    }

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
            ui->StartCity_TextBrowser->setText(Start);

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

    QString city = ui->From_ComboBox->currentText();

    QSqlQuery * foodQuery = new QSqlQuery(connection.mydb);
    QSqlQueryModel * foodModel = new QSqlQueryModel();
    foodQuery->prepare("Select Food from '"+city+"'");
    foodQuery->exec();
    foodModel->setQuery(*foodQuery);
    ui->Food_ComboBox->setModel(foodModel);
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

    QSqlQueryModel * distModel = new QSqlQueryModel();
    QSqlQuery * distQuery = new QSqlQuery(connection.mydb);

    distQuery->prepare("Select Distance from Distances where Start ='"+Start+"' and End = '"+End+"'");
    distQuery->exec();
    while(distQuery->next())
        ui->Distance_TextBrowser_2->setText(distQuery->value(0).toString());
    distModel->setQuery(*distQuery);
}

void Planning_Page::on_ClearPath_PushButton_released()
{
    ui->Route_TextBrowser->clear();
    ui->Route_TextBrowser_2->clear();
    ui->Distance_TextBrowser->clear();
}

void Planning_Page::on_BuyFood_PushButton_released()
{
    Planning_Page connection;
    QString food;

    if(connection.isOpen())
        connection.close();

    connection.open();

    QString city = ui->From_ComboBox->currentText();

    food = ui->Food_ComboBox->currentText();

    int quantity = ui->Quantity_SpinBox->value();
    double price;

    QSqlQuery* priceQuery = new QSqlQuery;
    priceQuery->prepare("Select Price from '"+city+"' where Food = '"+food+"'");
    priceQuery->exec();

    priceQuery->next();
    price = priceQuery->value(0).toDouble();

    totalCost += price * quantity;

    if(ui->Food_TextBrowser->toPlainText() == "")
        ui->Food_TextBrowser->setText(city + ": " + food + " - " + QString::number(quantity) + '\n');
    else
        ui->Food_TextBrowser->append(city + ": " + food + " - " + QString::number(quantity) + '\n');

    ui->Total_label_2->setText(QString::number(totalCost));

    connection.close();
}
