/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Add_Button;
    QPushButton *Delete_Button;
    QTableWidget *tableWidget;
    QPushButton *Sort_Button;
    QLabel *label;
    QPushButton *Search_Button;
    QPushButton *Refresh_Button;
    QLineEdit *lineEdit_Search;
    QPushButton *Edit_Button;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_Load;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(681, 386);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Add_Button = new QPushButton(centralwidget);
        Add_Button->setObjectName("Add_Button");
        Add_Button->setGeometry(QRect(10, 60, 80, 24));
        Delete_Button = new QPushButton(centralwidget);
        Delete_Button->setObjectName("Delete_Button");
        Delete_Button->setGeometry(QRect(10, 90, 80, 24));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(100, 60, 551, 241));
        Sort_Button = new QPushButton(centralwidget);
        Sort_Button->setObjectName("Sort_Button");
        Sort_Button->setGeometry(QRect(10, 280, 80, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 0, 281, 51));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        Search_Button = new QPushButton(centralwidget);
        Search_Button->setObjectName("Search_Button");
        Search_Button->setGeometry(QRect(10, 310, 80, 24));
        Refresh_Button = new QPushButton(centralwidget);
        Refresh_Button->setObjectName("Refresh_Button");
        Refresh_Button->setGeometry(QRect(10, 250, 80, 24));
        lineEdit_Search = new QLineEdit(centralwidget);
        lineEdit_Search->setObjectName("lineEdit_Search");
        lineEdit_Search->setGeometry(QRect(100, 310, 113, 24));
        Edit_Button = new QPushButton(centralwidget);
        Edit_Button->setObjectName("Edit_Button");
        Edit_Button->setGeometry(QRect(10, 120, 80, 24));
        pushButton_Save = new QPushButton(centralwidget);
        pushButton_Save->setObjectName("pushButton_Save");
        pushButton_Save->setGeometry(QRect(10, 180, 80, 24));
        pushButton_Load = new QPushButton(centralwidget);
        pushButton_Load->setObjectName("pushButton_Load");
        pushButton_Load->setGeometry(QRect(10, 150, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 681, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Add_Button->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        Delete_Button->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        Sort_Button->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Baza Danych Film\303\263w", nullptr));
        Search_Button->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        Refresh_Button->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        Edit_Button->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        pushButton_Save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton_Load->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
