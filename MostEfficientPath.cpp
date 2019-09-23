#include "MostEfficientPath.h"
#include "ui_mainwindow.h"
#include <vector>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ChoosePath_pushButton_released()
{
    QString start;
    MainWindow connection;

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

void MainWindow::on_From_ComboBox_currentIndexChanged(const QString &arg1)
{
    QString Start = ui->From_ComboBox->currentText();

    MainWindow connection;

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

void MainWindow::on_To_ComboBox_currentIndexChanged(const QString &arg1)
{
    MainWindow connection;
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
//    ui->EndCityList->setModel(endModel);

    QSqlQueryModel * distModel = new QSqlQueryModel();
    QSqlQuery * distQuery = new QSqlQuery(connection.mydb);
    distQuery->prepare("Select Distance from Distances where Start ='"+Start+"' and End = '"+End+"'");
    distQuery->exec();
    distModel->setQuery(*distQuery);
    ui->DistanceList->setModel(distModel);
}

void MainWindow::on_Save_Route_pushButton_released()
{
    ui->Route_TextEdit->setText(ui->Route_TextEdit->toPlainText() +
                                "From " + ui->From_ComboBox->currentText() + " to\t" + ui->To_ComboBox->currentText() + '\n');
}

void MainWindow::on_Paris_PushButton_released()
{
    MainWindow connection;
    std::vector<QString> visitedCities;
    visitedCities.push_back("Paris");

    if(connection.isOpen())
        connection.ConnClose();

    FindClosestCity("Paris", visitedCities);

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


    distQuery->prepare("SELECT MIN(Distance) from Distances where Start = 'Paris'");
    distQuery->exec();
    distModel->setQuery(*distQuery);
    ui->DistanceList->setModel(distModel);

}

void MainWindow::FindClosestCity(const QString& Start, std::vector<QString>& visitedCities)
{
    if(visitedCities.size() == TOTAL_CITY_COUNT)
    {
        MainWindow connection;
        QString End;
//        QString strQuery = "SELECT End from Distances where Distance= (SELECT MIN(Distance) from Distances where Start= '"+Start+"'";

        if(connection.isOpen())
            connection.ConnClose();
        connection.ConnOpen();

        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery * query = new QSqlQuery(connection.mydb);
        query->prepare("SELECT End from Distances where Distance= (SELECT MIN(Distance) from Distances where Start= '"+Start+"'");
        query->exec();
        model->setQuery(*query);
        query->boundValue(0);

        visitedCities.push_back(End);
        FindClosestCity(End, visitedCities);
    }
}


































//Default Travel Plan Starting from Paris:

//This only finds the closest city from one given city (givenCity),
//	ignoring all previous cities visited in the trip;
//void MainWindow::FindClosestCity(const QString& Start, std::vector<QString>& visitedCities)
//{
//	int minimumDistance = -1;
//	QString currentCity;

//	(loop until end of database)
//	{
//		otherCity = other city from database
//		if (otherCity == givenCity)
//		{
//			if(find(alreadyVisitedCities.begin(), alreadyVisitedCities.end(), otherCity) == alreadyVisitedCities.end())
//			{
//				if(minimumDistance == -1 || minimumDistance > distance from database)
//				{
//					minimumDistance = distance from database;
//					currentCity = otherCity;
//				}
//			}
//		}
//	}

//	return currentCity;
//}

//This handles the first two trip options, both with given number of cities
//void shortestTripPlanner()
//{
//	int numCities /*= get from GUI*/; //default trip from Paris is 11
//	QString city;

//	std::vector<QString> alreadyVisitedCities;

//	for(int i = 0; i < numCities; i++)
//	{
//		if(i == 0)
//		{
//			city /*= get from GUI*/; //default trip is Paris, other option is London
//		}
//		else
//		{
//			city = closestCity(city, alreadyVisitedCities);
//		}
//		alreadyVisitedCities.push(city);
//		display city to the GUI;
//		put the city onto the database;
//		wait for a signal from the GUI that the user finished buying food;
//		//put all of the foods onto the database
//		//	-> this will probably be handled by something else
//	}
//}





void MainWindow::on_EndCityList_doubleClicked(const QModelIndex &index)
{
    ui->To_ComboBox->setCurrentIndex(index.row());
}
