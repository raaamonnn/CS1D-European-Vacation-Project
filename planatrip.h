#ifndef PLANATRIP_H
#define PLANATRIP_H

#include <QDialog>

namespace Ui {
class planATrip;
}

class planATrip : public QDialog
{
    Q_OBJECT

public:
    explicit planATrip(QWidget *parent = nullptr);
    ~planATrip();

private slots:
    void on_parisTrip_clicked();

    void on_londonTrip_clicked();

    void on_customTrip_clicked();

private:
    Ui::planATrip *ui;
};

#endif // PLANATRIP_H
