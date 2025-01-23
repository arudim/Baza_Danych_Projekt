#include "edit.h"

#include <QMessageBox>

#include "BazaDanych.h"
#include "mainwindow.h"
#include "ui_edit.h"

/*!
 * \brief Edit::Edit
 * \param parent
 * Konstruktor
 * Wpisanie do lineeditow odpowiednich parametrów edytowaniego pliku
 * aby ułatwić modyfikację użytkownikowi
 */
Edit::Edit(QWidget *parent)
    : QDialog(parent), ui(new Ui::Edit), mw((MainWindow *)parent) {
  ui->setupUi(this);
  BazaDanych &DB = BazaDanych::Instancja();
  QJsonObject r = DB.DajRekord(mw->edit_id);
  int edit_rok = r["rok"].toInt();
  QString edit_tytul = r["tytul"].toString();
  QString edit_rezyser = r["rezyser"].toString();
  QString edit_gatunek = r["rodzaj"].toString();
  ui->rok_prod_edit->setText(QString::number(edit_rok));
  ui->tytul_edit->setText(edit_tytul);
  ui->rezyser_edit->setText(edit_rezyser);
  ui->gatunek_edit->setText(edit_gatunek);
}

Edit::~Edit() { delete ui; }
/*!
 * \brief Edit::on_pushButton_Porzuc_clicked
 * Zamkniecie okna pozosawiając rekord bez zmian
 */
void Edit::on_pushButton_Porzuc_clicked() {
  close();
}
/*!
 * \brief Edit::on_pushButton_Zatwierdz_clicked
 * Kontrola błędów dodawania rekordu (uzupełnienie wszystkich pól) (rok musi być intigerem)
 * Następnie rekord jest odpowiednio zmieniany
 */
void Edit::on_pushButton_Zatwierdz_clicked() {
  BazaDanych &DB = BazaDanych::Instancja();
  if (ui->rok_prod_edit->text().isEmpty() || ui->tytul_edit->text().isEmpty() || ui->rezyser_edit->text().isEmpty() || ui->gatunek_edit->text().isEmpty()) {
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
