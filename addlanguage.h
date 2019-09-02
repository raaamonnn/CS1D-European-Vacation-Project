#ifndef ADDLANGUAGE_H
#define ADDLANGUAGE_H

#include <QWidget>

namespace Ui {
class AddLanguage;
}

class AddLanguage : public QWidget
{
    Q_OBJECT

public:
    explicit AddLanguage(QWidget *parent = nullptr);
    ~AddLanguage();

private:
    Ui::AddLanguage *ui;
};

#endif // ADDLANGUAGE_H
