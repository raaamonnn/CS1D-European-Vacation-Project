/********************************************************************************
** Form generated from reading UI file 'planning_page.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANNING_PAGE_H
#define UI_PLANNING_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Planning_Page
{
public:
    QLabel *SelectedPath_label;
    QLabel *CustomPath_label;
    QLabel *To_label_2;
    QLabel *From_label_2;
    QLabel *To_label;
    QComboBox *To_ComboBox;
    QLabel *From_label;
    QComboBox *From_ComboBox;
    QLabel *Distance_label;
    QLabel *Distances_label;
    QLabel *units_label;
    QTextBrowser *Distance_TextBrowser_2;
    QLabel *EqualSign_label;
    QTextBrowser *Food_TextBrowser;
    QPushButton *BuyFood_PushButton;
    QComboBox *Food_ComboBox;
    QSpinBox *Quantity_SpinBox;
    QLabel *Total_label;
    QLabel *Total_label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QTextBrowser *StartCity_TextBrowser;
    QListView *EndCityList;
    QListView *DistanceList;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *Route_TextBrowser;
    QTextBrowser *Route_TextBrowser_2;
    QTextBrowser *Distance_TextBrowser;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Save_Route_pushButton;
    QPushButton *ClearPath_PushButton;
    QWidget *widget3;
    QVBoxLayout *verticalLayout;
    QPushButton *ChoosePath_pushButton;
    QPushButton *Paris_PushButton;
    QPushButton *London_PushButton;

    void setupUi(QDialog *Planning_Page)
    {
        if (Planning_Page->objectName().isEmpty())
            Planning_Page->setObjectName(QString::fromUtf8("Planning_Page"));
        Planning_Page->resize(1089, 568);
        SelectedPath_label = new QLabel(Planning_Page);
        SelectedPath_label->setObjectName(QString::fromUtf8("SelectedPath_label"));
        SelectedPath_label->setGeometry(QRect(20, 30, 251, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(9);
        SelectedPath_label->setFont(font);
        CustomPath_label = new QLabel(Planning_Page);
        CustomPath_label->setObjectName(QString::fromUtf8("CustomPath_label"));
        CustomPath_label->setGeometry(QRect(510, 30, 301, 31));
        CustomPath_label->setFont(font);
        To_label_2 = new QLabel(Planning_Page);
        To_label_2->setObjectName(QString::fromUtf8("To_label_2"));
        To_label_2->setGeometry(QRect(621, 100, 21, 16));
        To_label_2->setFont(font);
        From_label_2 = new QLabel(Planning_Page);
        From_label_2->setObjectName(QString::fromUtf8("From_label_2"));
        From_label_2->setGeometry(QRect(510, 100, 41, 16));
        From_label_2->setFont(font);
        To_label = new QLabel(Planning_Page);
        To_label->setObjectName(QString::fromUtf8("To_label"));
        To_label->setGeometry(QRect(130, 97, 21, 16));
        To_label->setFont(font);
        To_ComboBox = new QComboBox(Planning_Page);
        To_ComboBox->setObjectName(QString::fromUtf8("To_ComboBox"));
        To_ComboBox->setGeometry(QRect(620, 73, 111, 24));
        To_ComboBox->setFont(font);
        From_label = new QLabel(Planning_Page);
        From_label->setObjectName(QString::fromUtf8("From_label"));
        From_label->setGeometry(QRect(20, 97, 41, 16));
        From_label->setFont(font);
        From_ComboBox = new QComboBox(Planning_Page);
        From_ComboBox->setObjectName(QString::fromUtf8("From_ComboBox"));
        From_ComboBox->setGeometry(QRect(510, 73, 111, 24));
        From_ComboBox->setFont(font);
        Distance_label = new QLabel(Planning_Page);
        Distance_label->setObjectName(QString::fromUtf8("Distance_label"));
        Distance_label->setGeometry(QRect(247, 97, 61, 16));
        Distance_label->setFont(font);
        Distances_label = new QLabel(Planning_Page);
        Distances_label->setObjectName(QString::fromUtf8("Distances_label"));
        Distances_label->setGeometry(QRect(735, 100, 71, 16));
        Distances_label->setFont(font);
        units_label = new QLabel(Planning_Page);
        units_label->setObjectName(QString::fromUtf8("units_label"));
        units_label->setGeometry(QRect(810, 80, 41, 16));
        units_label->setFont(font);
        Distance_TextBrowser_2 = new QTextBrowser(Planning_Page);
        Distance_TextBrowser_2->setObjectName(QString::fromUtf8("Distance_TextBrowser_2"));
        Distance_TextBrowser_2->setGeometry(QRect(760, 70, 45, 30));
        Distance_TextBrowser_2->setFont(font);
        EqualSign_label = new QLabel(Planning_Page);
        EqualSign_label->setObjectName(QString::fromUtf8("EqualSign_label"));
        EqualSign_label->setGeometry(QRect(740, 76, 16, 16));
        EqualSign_label->setFont(font);
        Food_TextBrowser = new QTextBrowser(Planning_Page);
        Food_TextBrowser->setObjectName(QString::fromUtf8("Food_TextBrowser"));
        Food_TextBrowser->setGeometry(QRect(860, 160, 221, 321));
        Food_TextBrowser->setFont(font);
        BuyFood_PushButton = new QPushButton(Planning_Page);
        BuyFood_PushButton->setObjectName(QString::fromUtf8("BuyFood_PushButton"));
        BuyFood_PushButton->setGeometry(QRect(860, 500, 80, 25));
        BuyFood_PushButton->setFont(font);
        Food_ComboBox = new QComboBox(Planning_Page);
        Food_ComboBox->setObjectName(QString::fromUtf8("Food_ComboBox"));
        Food_ComboBox->setGeometry(QRect(860, 120, 141, 24));
        Food_ComboBox->setFont(font);
        Quantity_SpinBox = new QSpinBox(Planning_Page);
        Quantity_SpinBox->setObjectName(QString::fromUtf8("Quantity_SpinBox"));
        Quantity_SpinBox->setGeometry(QRect(1010, 120, 43, 25));
        Quantity_SpinBox->setFont(font);
        Total_label = new QLabel(Planning_Page);
        Total_label->setObjectName(QString::fromUtf8("Total_label"));
        Total_label->setGeometry(QRect(864, 530, 55, 16));
        Total_label->setFont(font);
        Total_label_2 = new QLabel(Planning_Page);
        Total_label_2->setObjectName(QString::fromUtf8("Total_label_2"));
        Total_label_2->setGeometry(QRect(920, 530, 71, 16));
        Total_label_2->setFont(font);
        widget = new QWidget(Planning_Page);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(510, 120, 331, 361));
        widget->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        StartCity_TextBrowser = new QTextBrowser(widget);
        StartCity_TextBrowser->setObjectName(QString::fromUtf8("StartCity_TextBrowser"));
        StartCity_TextBrowser->setFont(font);

        horizontalLayout_3->addWidget(StartCity_TextBrowser);

        EndCityList = new QListView(widget);
        EndCityList->setObjectName(QString::fromUtf8("EndCityList"));
        EndCityList->setFont(font);

        horizontalLayout_3->addWidget(EndCityList);

        DistanceList = new QListView(widget);
        DistanceList->setObjectName(QString::fromUtf8("DistanceList"));
        DistanceList->setFont(font);

        horizontalLayout_3->addWidget(DistanceList);

        widget1 = new QWidget(Planning_Page);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 120, 331, 361));
        widget1->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Route_TextBrowser = new QTextBrowser(widget1);
        Route_TextBrowser->setObjectName(QString::fromUtf8("Route_TextBrowser"));
        Route_TextBrowser->setFont(font);

        horizontalLayout_2->addWidget(Route_TextBrowser);

        Route_TextBrowser_2 = new QTextBrowser(widget1);
        Route_TextBrowser_2->setObjectName(QString::fromUtf8("Route_TextBrowser_2"));
        Route_TextBrowser_2->setFont(font);

        horizontalLayout_2->addWidget(Route_TextBrowser_2);

        Distance_TextBrowser = new QTextBrowser(widget1);
        Distance_TextBrowser->setObjectName(QString::fromUtf8("Distance_TextBrowser"));
        Distance_TextBrowser->setFont(font);

        horizontalLayout_2->addWidget(Distance_TextBrowser);

        widget2 = new QWidget(Planning_Page);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(510, 490, 111, 67));
        widget2->setFont(font);
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Save_Route_pushButton = new QPushButton(widget2);
        Save_Route_pushButton->setObjectName(QString::fromUtf8("Save_Route_pushButton"));
        Save_Route_pushButton->setFont(font);

        verticalLayout_2->addWidget(Save_Route_pushButton);

        ClearPath_PushButton = new QPushButton(widget2);
        ClearPath_PushButton->setObjectName(QString::fromUtf8("ClearPath_PushButton"));
        ClearPath_PushButton->setFont(font);

        verticalLayout_2->addWidget(ClearPath_PushButton);

        widget3 = new QWidget(Planning_Page);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(370, 250, 121, 103));
        widget3->setFont(font);
        verticalLayout = new QVBoxLayout(widget3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ChoosePath_pushButton = new QPushButton(widget3);
        ChoosePath_pushButton->setObjectName(QString::fromUtf8("ChoosePath_pushButton"));
        ChoosePath_pushButton->setFont(font);

        verticalLayout->addWidget(ChoosePath_pushButton);

        Paris_PushButton = new QPushButton(widget3);
        Paris_PushButton->setObjectName(QString::fromUtf8("Paris_PushButton"));
        Paris_PushButton->setFont(font);

        verticalLayout->addWidget(Paris_PushButton);

        London_PushButton = new QPushButton(widget3);
        London_PushButton->setObjectName(QString::fromUtf8("London_PushButton"));
        London_PushButton->setFont(font);

        verticalLayout->addWidget(London_PushButton);


        retranslateUi(Planning_Page);

        QMetaObject::connectSlotsByName(Planning_Page);
    } // setupUi

    void retranslateUi(QDialog *Planning_Page)
    {
        Planning_Page->setWindowTitle(QCoreApplication::translate("Planning_Page", "MainWindow", nullptr));
        SelectedPath_label->setText(QCoreApplication::translate("Planning_Page", "Your Selected Path", nullptr));
        CustomPath_label->setText(QCoreApplication::translate("Planning_Page", "Custom Path Selection", nullptr));
        To_label_2->setText(QCoreApplication::translate("Planning_Page", "To", nullptr));
        From_label_2->setText(QCoreApplication::translate("Planning_Page", "From", nullptr));
        To_label->setText(QCoreApplication::translate("Planning_Page", "To", nullptr));
        From_label->setText(QCoreApplication::translate("Planning_Page", "From", nullptr));
        Distance_label->setText(QCoreApplication::translate("Planning_Page", "Distance", nullptr));
        Distances_label->setText(QCoreApplication::translate("Planning_Page", "Distances", nullptr));
        units_label->setText(QCoreApplication::translate("Planning_Page", "miles", nullptr));
        EqualSign_label->setText(QCoreApplication::translate("Planning_Page", "=", nullptr));
        BuyFood_PushButton->setText(QCoreApplication::translate("Planning_Page", "Buy Food", nullptr));
        Total_label->setText(QCoreApplication::translate("Planning_Page", "Total:", nullptr));
        Total_label_2->setText(QCoreApplication::translate("Planning_Page", "0", nullptr));
        Save_Route_pushButton->setText(QCoreApplication::translate("Planning_Page", "Save Route", nullptr));
        ClearPath_PushButton->setText(QCoreApplication::translate("Planning_Page", "Clear Path", nullptr));
        ChoosePath_pushButton->setText(QCoreApplication::translate("Planning_Page", "Choose Path", nullptr));
        Paris_PushButton->setText(QCoreApplication::translate("Planning_Page", "Start at Paris", nullptr));
        London_PushButton->setText(QCoreApplication::translate("Planning_Page", "Start at London", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Planning_Page: public Ui_Planning_Page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANNING_PAGE_H
