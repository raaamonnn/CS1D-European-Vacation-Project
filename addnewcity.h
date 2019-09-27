#ifndef ADDNEWCITY_H
#define ADDNEWCITY_H

#include <QWidget>

namespace Ui {
class AddNewCity;
}

class AddNewCity : public QWidget
{
    Q_OBJECT

public:
    explicit AddNewCity(QWidget *parent = nullptr);
    ~AddNewCity();

private slots:
    void on_addFood_clicked();

    void on_pushData_clicked();

private:
    Ui::AddNewCity *ui;
    QVector<QString> foodArray;
    QVector<QString> priceArray;
};

#endif // ADDNEWCITY_H
