#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <QString>
#include <QSqlDatabase>

/**
 * @brief The DatabaseManager class is created to pass all the database from SQlite
 *
 */
class DatabaseManager
{
private:
    QString path;
    QSqlDatabase database;
    void setDatabase(QSqlDatabase database) {
        this->database = database;
    }

public:
    DatabaseManager(QString path) {
        this->path = path;
    }

    void connect();
    QString getPath() {
        return this->path;
    }

    QSqlDatabase getDatabase() {
        return this->database;
    }


};

#endif // DATABASE_MANAGER_H
