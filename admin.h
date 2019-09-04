#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "adminview.h"

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_login_clicked();

private:
    Ui::admin *ui;
    adminView adminView;
};

#endif // ADMIN_H
