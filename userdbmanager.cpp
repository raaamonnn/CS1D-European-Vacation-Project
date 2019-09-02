#include "userdbmanager.h"

userDbManager::userDbManager()
{
    QString path = "C:/Users/annea/Summer2019Database.db";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);
    m_db.open();

    if (!m_db.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }
}

userDbManager::~userDbManager()
{
}

bool userDbManager::loginCheck(QString username, QString password)
{
    QSqlQueryModel *queryModel = new QSqlQueryModel;
    queryModel->setQuery("SELECT * FROM [User Database] WHERE Username= username");
    if(queryModel->record(0).value(1).toString()== password)
    {
        qDebug("XDDDDDDDDDDD");
        return true;
    }
    return false;
}
