/********************************************************************************
** Form generated from reading UI file 'planning_page.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANNING_PAGE_H
#define UI_PLANNING_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Planning_Page
{
public:
    QVBoxLayout *verticalLayout;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *Route_TextEdit;
    QPushButton *ChoosePath_pushButton;
    QPushButton *Paris_PushButton;
    QListView *EndCityList;
    QPushButton *Save_Route_pushButton;
    QPushButton *London_PushButton;
    QComboBox *To_ComboBox;
    QTextEdit *StartCityTextEdit;
    QListView *DistanceList;
    QComboBox *From_ComboBox;

    void setupUi(QDialog *Planning_Page)
    {
        if (Planning_Page->objectName().isEmpty())
            Planning_Page->setObjectName(QString::fromUtf8("Planning_Page"));
        Planning_Page->resize(877, 600);
        verticalLayout = new QVBoxLayout(Planning_Page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        statusbar = new QStatusBar(Planning_Page);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));

        verticalLayout->addWidget(statusbar);

        menubar = new QMenuBar(Planning_Page);
        menubar->setObjectName(QString::fromUtf8("menubar"));

        verticalLayout->addWidget(menubar);

        centralwidget = new QWidget(Planning_Page);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Route_TextEdit = new QTextEdit(centralwidget);
        Route_TextEdit->setObjectName(QString::fromUtf8("Route_TextEdit"));

        gridLayout->addWidget(Route_TextEdit, 1, 0, 1, 1);

        ChoosePath_pushButton = new QPushButton(centralwidget);
        ChoosePath_pushButton->setObjectName(QString::fromUtf8("ChoosePath_pushButton"));

        gridLayout->addWidget(ChoosePath_pushButton, 6, 1, 1, 1);

        Paris_PushButton = new QPushButton(centralwidget);
        Paris_PushButton->setObjectName(QString::fromUtf8("Paris_PushButton"));

        gridLayout->addWidget(Paris_PushButton, 3, 1, 1, 1);

        EndCityList = new QListView(centralwidget);
        EndCityList->setObjectName(QString::fromUtf8("EndCityList"));

        gridLayout->addWidget(EndCityList, 1, 3, 1, 2);

        Save_Route_pushButton = new QPushButton(centralwidget);
        Save_Route_pushButton->setObjectName(QString::fromUtf8("Save_Route_pushButton"));

        gridLayout->addWidget(Save_Route_pushButton, 5, 3, 1, 1);

        London_PushButton = new QPushButton(centralwidget);
        London_PushButton->setObjectName(QString::fromUtf8("London_PushButton"));

        gridLayout->addWidget(London_PushButton, 5, 1, 1, 1);

        To_ComboBox = new QComboBox(centralwidget);
        To_ComboBox->setObjectName(QString::fromUtf8("To_ComboBox"));

        gridLayout->addWidget(To_ComboBox, 0, 3, 1, 2);

        StartCityTextEdit = new QTextEdit(centralwidget);
        StartCityTextEdit->setObjectName(QString::fromUtf8("StartCityTextEdit"));

        gridLayout->addWidget(StartCityTextEdit, 1, 1, 1, 1);

        DistanceList = new QListView(centralwidget);
        DistanceList->setObjectName(QString::fromUtf8("DistanceList"));

        gridLayout->addWidget(DistanceList, 1, 5, 1, 2);

        From_ComboBox = new QComboBox(centralwidget);
        From_ComboBox->setObjectName(QString::fromUtf8("From_ComboBox"));

        gridLayout->addWidget(From_ComboBox, 0, 1, 1, 1);


        verticalLayout->addWidget(centralwidget);


        retranslateUi(Planning_Page);

        QMetaObject::connectSlotsByName(Planning_Page);
    } // setupUi

    void retranslateUi(QDialog *Planning_Page)
    {
        Planning_Page->setWindowTitle(QApplication::translate("Planning_Page", "MainWindow", nullptr));
        ChoosePath_pushButton->setText(QApplication::translate("Planning_Page", "Choose Path", nullptr));
        Paris_PushButton->setText(QApplication::translate("Planning_Page", "Start at Paris", nullptr));
        Save_Route_pushButton->setText(QApplication::translate("Planning_Page", "Save Route", nullptr));
        London_PushButton->setText(QApplication::translate("Planning_Page", "Start at London", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Planning_Page: public Ui_Planning_Page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANNING_PAGE_H
