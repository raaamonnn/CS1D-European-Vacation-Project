#ifndef PRACTICE_H
#define PRACTICE_H

#include <QDialog>

namespace Ui {
class Practice;
}

class Practice : public QDialog
{
    Q_OBJECT

public:
    explicit Practice(QWidget *parent = nullptr);
    ~Practice();

private:
    Ui::Practice *ui;
};

#endif // PRACTICE_H
