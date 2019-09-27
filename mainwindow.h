#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "planatrip.h"
#include "displayinformation.h"
#include "admin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_planATripButton_clicked();

    void on_displayInformationButton_clicked();

    void on_adminButton_clicked();

private:
    Ui::MainWindow *ui;
    planATrip planATrip;
    displayInformation displayInformation;
    admin admin;
};

#endif // MAINWINDOW_H
