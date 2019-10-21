#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<displayinformation.h>
#include<login.h>

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

void MainWindow::on_pushButton_clicked()
{
    displayInformation window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    login window;
    window.setModal(true);
    window.exec();
}
