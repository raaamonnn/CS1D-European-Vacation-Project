#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QWidget>

namespace Ui {
class adminView;
}

class adminView : public QWidget
{
    Q_OBJECT

public:
    explicit adminView(QWidget *parent = nullptr);
    ~adminView();

private slots:
    void on_loadData_clicked();

    void on_new_2_clicked();

    void on_changePrice_clicked();

    void on_addFood_clicked();

    void on_deleteFood_clicked();

private:
    Ui::adminView *ui;
};

#endif // ADMINVIEW_H
