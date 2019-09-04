#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_planATripButton_clicked()
{
    planATrip.show();
}

void MainWindow::on_displayInformationButton_clicked()
{
    displayInformation.show();
}

void MainWindow::on_adminButton_clicked()
{
    admin.show();
}
