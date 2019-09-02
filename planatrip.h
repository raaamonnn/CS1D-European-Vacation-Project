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

private:
    Ui::planATrip *ui;
};

#endif // PLANATRIP_H
