#include "mainwindow.h"
#include "user.h"
#include <QApplication>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.showMaximized();

    return a.exec();
}
