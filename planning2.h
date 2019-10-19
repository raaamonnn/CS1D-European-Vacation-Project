#ifndef PLANNING2_H
#define PLANNING2_H

#include <QDialog>

namespace Ui {
class planning2;
}

class planning2 : public QDialog
{
    Q_OBJECT

public:
    explicit planning2(QWidget *parent = nullptr);
    ~planning2();

private slots:


private:
    Ui::planning2 *ui;

};

#endif // PLANNING2_H
