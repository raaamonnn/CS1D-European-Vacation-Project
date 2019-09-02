#ifndef USER_H
#define USER_H

#include <QWidget>


namespace Ui {
class User;
}

class User : public QWidget
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = nullptr);
    void setUsername(QString username)
    {
        this->username = username;
    }
    void setPassword(QString password)
    {
        this->password = password;
    }
    ~User();

private slots:
    void on_practice_clicked();

    void on_addLanguage_clicked();

    void on_deleteLanguage_clicked();

    void on_editLanguages_clicked();

private:
    QString username;
    QString password;
    Ui::User *ui;
};

#endif // USER_H
