#include "mainwindow.h"
#include "edit.h"
#include "ui_edit.h"
#include "BazaDanych.h"
#include <QMessageBox>

Edit::Edit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Edit)
    ,mw((MainWindow*) parent)
{
    ui->setupUi(this);
    ui->rok_prod_edit->setText(QString::number(mw->edit_rok));
    ui->tytul_edit->setText(mw->edit_tytul);
    ui->rezyser_edit->setText(mw->edit_rezyser);
    ui->gatunek_edit->setText(mw->edit_gatunek);
}

Edit::~Edit()
{
    delete ui;
}

void Edit::on_pushButton_Porzuc_clicked()
{
    close();
}


void Edit::on_pushButton_Zatwierdz_clicked()
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
    DB.EdytowanieRekordu(mw->edit_id, year,
                        ui->tytul_edit->text().toStdString().c_str(),
                        ui->rezyser_edit->text().toStdString().c_str(),
                        ui->gatunek_edit->text().toStdString().c_str());
    mw->updateTable();
    close();

}

