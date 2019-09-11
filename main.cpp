#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    const QString PATH = "my path"; //my path

    DatabaseManager *databaseManager = new DatabaseManager(PATH);
    databaseManager->connect();
    MainWindow w;



    w.showMaximized();

    return a.exec();
}
