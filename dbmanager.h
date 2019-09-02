#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class dbManager;
}

class dbManager : public QWidget
{
    Q_OBJECT

public:
    explicit dbManager(QWidget *parent = nullptr);
    ~dbManager();

private slots:
    void on_updateData_clicked();

    void on_getData_clicked();

    void on_addLanguage_clicked();

    void on_editLanguage_clicked();

    void on_deleteLanguage_clicked();

    void on_back_clicked();

private:
    Ui::dbManager *ui;
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
