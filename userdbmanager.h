#ifndef USERDBMANAGER_H
#define USERDBMANAGER_H


#include <QtSql>
#include <QTableView>
class userDbManager
{
public:
    bool loginCheck(QString username, QString password);
    userDbManager();
    ~userDbManager();

private:
    QSqlDatabase m_db;
};

#endif // USERDBMANAGER_H


