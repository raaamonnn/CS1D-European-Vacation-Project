/********************************************************************************
** Form generated from reading UI file 'planning2.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANNING2_H
#define UI_PLANNING2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_planning2
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QListView *listView;
    QListView *listView_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;

    void setupUi(QDialog *planning2)
    {
        if (planning2->objectName().isEmpty())
            planning2->setObjectName(QString::fromUtf8("planning2"));
        planning2->resize(506, 342);
        pushButton = new QPushButton(planning2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 260, 80, 18));
        pushButton_2 = new QPushButton(planning2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 260, 91, 18));
        pushButton_3 = new QPushButton(planning2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(300, 260, 91, 18));
        listView = new QListView(planning2);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(50, 60, 161, 181));
        listView_2 = new QListView(planning2);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));
        listView_2->setGeometry(QRect(240, 60, 181, 181));
        comboBox = new QComboBox(planning2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(120, 30, 91, 22));
        comboBox_2 = new QComboBox(planning2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(270, 30, 91, 22));

        retranslateUi(planning2);

        QMetaObject::connectSlotsByName(planning2);
    } // setupUi

    void retranslateUi(QDialog *planning2)
    {
        planning2->setWindowTitle(QCoreApplication::translate("planning2", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("planning2", "Choose Path", nullptr));
        pushButton_2->setText(QCoreApplication::translate("planning2", "Start From London", nullptr));
        pushButton_3->setText(QCoreApplication::translate("planning2", "Start From Paris", nullptr));
    } // retranslateUi

};

namespace Ui {
    class planning2: public Ui_planning2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANNING2_H
