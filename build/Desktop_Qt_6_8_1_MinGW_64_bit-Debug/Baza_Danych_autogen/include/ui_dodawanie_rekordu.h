/********************************************************************************
** Form generated from reading UI file 'dodawanie_rekordu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DODAWANIE_REKORDU_H
#define UI_DODAWANIE_REKORDU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dodawanie_rekordu
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *rok_prod_edit;
    QLineEdit *tytul_edit;
    QLineEdit *rezyser_edit;
    QLineEdit *gatunek_edit;
    QPushButton *pushButton_Dodaj;
    QPushButton *pushButton_Porzuc;

    void setupUi(QDialog *dodawanie_rekordu)
    {
        if (dodawanie_rekordu->objectName().isEmpty())
            dodawanie_rekordu->setObjectName("dodawanie_rekordu");
        dodawanie_rekordu->resize(400, 300);
        label = new QLabel(dodawanie_rekordu);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 30, 121, 16));
        label_2 = new QLabel(dodawanie_rekordu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 80, 49, 16));
        label_3 = new QLabel(dodawanie_rekordu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 130, 49, 16));
        label_4 = new QLabel(dodawanie_rekordu);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 180, 49, 16));
        rok_prod_edit = new QLineEdit(dodawanie_rekordu);
        rok_prod_edit->setObjectName("rok_prod_edit");
        rok_prod_edit->setGeometry(QRect(160, 30, 113, 24));
        tytul_edit = new QLineEdit(dodawanie_rekordu);
        tytul_edit->setObjectName("tytul_edit");
        tytul_edit->setGeometry(QRect(160, 80, 113, 24));
        rezyser_edit = new QLineEdit(dodawanie_rekordu);
        rezyser_edit->setObjectName("rezyser_edit");
        rezyser_edit->setGeometry(QRect(160, 130, 113, 24));
        gatunek_edit = new QLineEdit(dodawanie_rekordu);
        gatunek_edit->setObjectName("gatunek_edit");
        gatunek_edit->setGeometry(QRect(160, 180, 113, 24));
        pushButton_Dodaj = new QPushButton(dodawanie_rekordu);
        pushButton_Dodaj->setObjectName("pushButton_Dodaj");
        pushButton_Dodaj->setGeometry(QRect(180, 250, 80, 24));
        pushButton_Porzuc = new QPushButton(dodawanie_rekordu);
        pushButton_Porzuc->setObjectName("pushButton_Porzuc");
        pushButton_Porzuc->setGeometry(QRect(280, 250, 80, 24));

        retranslateUi(dodawanie_rekordu);

        QMetaObject::connectSlotsByName(dodawanie_rekordu);
    } // setupUi

    void retranslateUi(QDialog *dodawanie_rekordu)
    {
        dodawanie_rekordu->setWindowTitle(QCoreApplication::translate("dodawanie_rekordu", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("dodawanie_rekordu", "Rok Produkcji", nullptr));
        label_2->setText(QCoreApplication::translate("dodawanie_rekordu", "Tytu\305\202", nullptr));
        label_3->setText(QCoreApplication::translate("dodawanie_rekordu", "Re\305\274yser", nullptr));
        label_4->setText(QCoreApplication::translate("dodawanie_rekordu", "Gatunek", nullptr));
        pushButton_Dodaj->setText(QCoreApplication::translate("dodawanie_rekordu", "Dodaj", nullptr));
        pushButton_Porzuc->setText(QCoreApplication::translate("dodawanie_rekordu", "Porzu\304\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dodawanie_rekordu: public Ui_dodawanie_rekordu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DODAWANIE_REKORDU_H
