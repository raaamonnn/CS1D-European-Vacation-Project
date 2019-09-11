#include "databaseManager.h"
#include <QDebug>

void DatabaseManager::connect() {
    setDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    getDatabase().setDatabaseName(getPath());
    if (!getDatabase().open()) {
        qDebug() << "Error: connection with database fail";
    } else {
        qDebug() << "Database: connection ok";
    }
}
