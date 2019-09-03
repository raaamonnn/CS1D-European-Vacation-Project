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
    destroy();
    planATrip.showMaximized();
}

void MainWindow::on_displayInformationButton_clicked()
{
    destroy();
    displayInformation.showMaximized();
}

void MainWindow::on_adminButton_clicked()
{
    destroy();
    admin.showMaximized();
}
