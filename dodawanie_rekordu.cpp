#include "mainwindow.h"
#include "dodawanie_rekordu.h"
#include "ui_dodawanie_rekordu.h"
#include "BazaDanych.h"
#include <QMessageBox>

dodawanie_rekordu::dodawanie_rekordu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dodawanie_rekordu)
    ,mw((MainWindow*) parent)
{
    ui->setupUi(this);
}

dodawanie_rekordu::~dodawanie_rekordu()
{
    delete ui;
}




void dodawanie_rekordu::on_pushButton_Dodaj_clicked()
{
    BazaDanych &DB=BazaDanych::Instancja();
    if (ui->rok_prod_edit->text().isEmpty() ||
        ui->tytul_edit->text().isEmpty() ||
        ui->rezyser_edit->text().isEmpty() ||
        ui->gatunek_edit->text().isEmpty())
    {
        QMessageBox::warning(this, "Błąd Danych", "Wszystkie pola muszą być wypełnione.");
        return;
    }
    bool ok;
    int year = ui->rok_prod_edit->text().toInt(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Zła Dana", "Wprowadź 'int' dla danej Rok");
        return;
    }

    DB.DodawnieRekordu(year, ui->tytul_edit->text().toStdString().c_str(),
                       ui->rezyser_edit->text().toStdString().c_str(),
                       ui->gatunek_edit->text().toStdString().c_str());

    mw->updateTable();
    this->close();
}


void dodawanie_rekordu::on_pushButton_Porzuc_clicked()
{
    this->close();
}

