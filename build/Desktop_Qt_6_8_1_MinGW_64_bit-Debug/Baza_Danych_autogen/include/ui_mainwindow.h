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
    QLineEdit *lineEditYear;
    QLineEdit *lineEditName;
    QLineEdit *lineEditDirector;
    QLineEdit *lineEditType;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *Sort_Button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Add_Button = new QPushButton(centralwidget);
        Add_Button->setObjectName("Add_Button");
        Add_Button->setGeometry(QRect(40, 170, 80, 24));
        Delete_Button = new QPushButton(centralwidget);
        Delete_Button->setObjectName("Delete_Button");
        Delete_Button->setGeometry(QRect(40, 220, 80, 24));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(150, 170, 491, 241));
        lineEditYear = new QLineEdit(centralwidget);
        lineEditYear->setObjectName("lineEditYear");
        lineEditYear->setGeometry(QRect(70, 70, 113, 24));
        lineEditName = new QLineEdit(centralwidget);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setGeometry(QRect(200, 70, 113, 24));
        lineEditDirector = new QLineEdit(centralwidget);
        lineEditDirector->setObjectName("lineEditDirector");
        lineEditDirector->setGeometry(QRect(340, 70, 113, 24));
        lineEditType = new QLineEdit(centralwidget);
        lineEditType->setObjectName("lineEditType");
        lineEditType->setGeometry(QRect(480, 70, 113, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 50, 49, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 50, 49, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(340, 50, 49, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(480, 50, 49, 16));
        Sort_Button = new QPushButton(centralwidget);
        Sort_Button->setObjectName("Sort_Button");
        Sort_Button->setGeometry(QRect(40, 260, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
        label->setText(QCoreApplication::translate("MainWindow", "Rok", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nazwa", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Re\305\274yser", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Typ", nullptr));
        Sort_Button->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
