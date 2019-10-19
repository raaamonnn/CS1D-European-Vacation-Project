/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLabel *label_6;
    QLabel *label_7;
    QTableView *tableView;
    QLabel *label;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_9;

    void setupUi(QDialog *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName(QString::fromUtf8("admin"));
        admin->resize(875, 472);
        gridLayout = new QGridLayout(admin);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_3 = new QLineEdit(admin);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 8, 1, 1, 1);

        pushButton_3 = new QPushButton(admin);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 15, 1, 1, 1);

        pushButton_4 = new QPushButton(admin);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 16, 0, 1, 1);

        label_3 = new QLabel(admin);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 1, 1, 1);

        comboBox = new QComboBox(admin);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 0, 1, 1);

        label_8 = new QLabel(admin);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 13, 1, 1, 1);

        lineEdit_4 = new QLineEdit(admin);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 12, 1, 1, 1);

        pushButton = new QPushButton(admin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 5, 1, 1, 1);

        label_5 = new QLabel(admin);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 7, 1, 1, 1);

        lineEdit_2 = new QLineEdit(admin);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 4, 1, 1, 1);

        label_6 = new QLabel(admin);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 10, 1, 1, 1);

        label_7 = new QLabel(admin);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 11, 1, 1, 1);

        tableView = new QTableView(admin);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 3, 0, 13, 1);

        label = new QLabel(admin);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Niagara Engraved"));
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_5 = new QLineEdit(admin);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 14, 1, 1, 1);

        pushButton_2 = new QPushButton(admin);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 9, 1, 1, 1);

        lineEdit = new QLineEdit(admin);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(32767);

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        label_4 = new QLabel(admin);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 6, 1, 1, 1);

        label_2 = new QLabel(admin);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_9 = new QLabel(admin);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 2, 1, 1, 1);


        retranslateUi(admin);

        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QDialog *admin)
    {
        admin->setWindowTitle(QApplication::translate("admin", "Dialog", nullptr));
        pushButton_3->setText(QApplication::translate("admin", "Set New Price", nullptr));
        pushButton_4->setText(QApplication::translate("admin", "Add New Cities", nullptr));
        label_3->setText(QApplication::translate("admin", "FOOD PRICE", nullptr));
        comboBox->setItemText(0, QApplication::translate("admin", "CITY", nullptr));
        comboBox->setItemText(1, QApplication::translate("admin", "Amsterdam", nullptr));
        comboBox->setItemText(2, QApplication::translate("admin", "Berlin", nullptr));
        comboBox->setItemText(3, QApplication::translate("admin", "Brussels", nullptr));
        comboBox->setItemText(4, QApplication::translate("admin", "Budapest", nullptr));
        comboBox->setItemText(5, QApplication::translate("admin", "Hamburg", nullptr));
        comboBox->setItemText(6, QApplication::translate("admin", "Lisbon", nullptr));
        comboBox->setItemText(7, QApplication::translate("admin", "London", nullptr));
        comboBox->setItemText(8, QApplication::translate("admin", "Madrid", nullptr));
        comboBox->setItemText(9, QApplication::translate("admin", "Paris", nullptr));
        comboBox->setItemText(10, QApplication::translate("admin", "Prague", nullptr));
        comboBox->setItemText(11, QApplication::translate("admin", "Rome", nullptr));
        comboBox->setItemText(12, QApplication::translate("admin", "Stockholm", nullptr));
        comboBox->setItemText(13, QApplication::translate("admin", "Vienna", nullptr));

        label_8->setText(QApplication::translate("admin", "NEW PRICE", nullptr));
        pushButton->setText(QApplication::translate("admin", "Add Food", nullptr));
        label_5->setText(QApplication::translate("admin", "FOOD NAME", nullptr));
        label_6->setText(QApplication::translate("admin", "===============", nullptr));
        label_7->setText(QApplication::translate("admin", "FOOD NAME", nullptr));
        label->setText(QApplication::translate("admin", "Vacation Spots", nullptr));
        pushButton_2->setText(QApplication::translate("admin", "Remove Food", nullptr));
        lineEdit->setInputMask(QString());
        label_4->setText(QApplication::translate("admin", "===============", nullptr));
        label_2->setText(QApplication::translate("admin", "FOOD NAME", nullptr));
        label_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
