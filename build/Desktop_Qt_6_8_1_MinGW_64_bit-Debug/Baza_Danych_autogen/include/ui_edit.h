/********************************************************************************
** Form generated from reading UI file 'edit.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_H
#define UI_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Edit
{
public:
    QPushButton *pushButton_Zatwierdz;
    QPushButton *pushButton_Porzuc;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *rok_prod_edit;
    QLabel *label_4;
    QLineEdit *rezyser_edit;
    QLineEdit *gatunek_edit;
    QLineEdit *tytul_edit;

    void setupUi(QDialog *Edit)
    {
        if (Edit->objectName().isEmpty())
            Edit->setObjectName("Edit");
        Edit->resize(400, 300);
        pushButton_Zatwierdz = new QPushButton(Edit);
        pushButton_Zatwierdz->setObjectName("pushButton_Zatwierdz");
        pushButton_Zatwierdz->setGeometry(QRect(130, 230, 80, 24));
        pushButton_Porzuc = new QPushButton(Edit);
        pushButton_Porzuc->setObjectName("pushButton_Porzuc");
        pushButton_Porzuc->setGeometry(QRect(230, 230, 80, 24));
        label_2 = new QLabel(Edit);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 70, 49, 16));
        label_3 = new QLabel(Edit);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 120, 49, 16));
        label = new QLabel(Edit);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 121, 16));
        rok_prod_edit = new QLineEdit(Edit);
        rok_prod_edit->setObjectName("rok_prod_edit");
        rok_prod_edit->setGeometry(QRect(120, 20, 113, 24));
        label_4 = new QLabel(Edit);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 170, 49, 16));
        rezyser_edit = new QLineEdit(Edit);
        rezyser_edit->setObjectName("rezyser_edit");
        rezyser_edit->setGeometry(QRect(120, 120, 113, 24));
        gatunek_edit = new QLineEdit(Edit);
        gatunek_edit->setObjectName("gatunek_edit");
        gatunek_edit->setGeometry(QRect(120, 170, 113, 24));
        tytul_edit = new QLineEdit(Edit);
        tytul_edit->setObjectName("tytul_edit");
        tytul_edit->setGeometry(QRect(120, 70, 113, 24));

        retranslateUi(Edit);

        QMetaObject::connectSlotsByName(Edit);
    } // setupUi

    void retranslateUi(QDialog *Edit)
    {
        Edit->setWindowTitle(QCoreApplication::translate("Edit", "Dialog", nullptr));
        pushButton_Zatwierdz->setText(QCoreApplication::translate("Edit", "Zatwierd\305\272", nullptr));
        pushButton_Porzuc->setText(QCoreApplication::translate("Edit", "Porzu\304\207", nullptr));
        label_2->setText(QCoreApplication::translate("Edit", "Tytu\305\202", nullptr));
        label_3->setText(QCoreApplication::translate("Edit", "Re\305\274yser", nullptr));
        label->setText(QCoreApplication::translate("Edit", "Rok Produkcji", nullptr));
        label_4->setText(QCoreApplication::translate("Edit", "Gatunek", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Edit: public Ui_Edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_H
