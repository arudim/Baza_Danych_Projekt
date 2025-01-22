#include "mainwindow.h"
#include "BazaDanych.h"
#include "dodawanie_rekordu.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QJsonObject>
#include <QMessageBox>
#include <QString>

MainWindow *mainWindowInstance = nullptr;
QJsonObject rekord;
/*!
 * \brief MainWindow::MainWindow
 * \param parent
 * Konstruktor
 * Dodatkowo definiowane parametry tablei
 * Miedzy innymi dodane nagłówków do kolumn, ukrycie identyfikatora rekordów indywidualnego dla kazdego rejestru,
 * ustawienie kolumny tytułowej na dynamiczną
 */
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  mainWindowInstance = this;

  ui->tableWidget->setColumnCount(5); // Set number of columns
  QStringList headers;
  headers << "ID" << "Year" << "Name" << "Director" << "Type";
  ui->tableWidget->setHorizontalHeaderLabels(headers);
  ui->tableWidget->setColumnHidden(0,true);
  ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
}
/*!
 * \brief MainWindow::~MainWindow
 * Destruktor
 */
MainWindow::~MainWindow() { delete ui; }
/*!
 * \brief MainWindow::updateTable
 * Pierwsza pętla usuwa wszystkie wiersze w poprzednio zadeklarowanej tabeli
 * Druga pętla wpisuje rejestry z aktualnej bazy danych
 * "if" sortowanie po odpowiednio zaznaczonym elemęcie tabeli
 */
void MainWindow::updateTable() {
  QJsonObject r;
  BazaDanych &DB = BazaDanych::Instancja();
  int rc = ui->tableWidget->rowCount();
  int dbs = DB.Rozmiar();
  //auto tbl = ui->tableWidget;
  for (int i = 0; i < rc; i++) {
    ui->tableWidget->removeRow(i);
  }
  ui->tableWidget->setRowCount(dbs);
  DB.ResetIteratoraRekordu();
  for (int i = 0; i < dbs; i++) {
    r = DB.IteratorRekordu();
    if (r.isEmpty()) {
      break;
    }
    ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(r["id"].toInt())));
    ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(r["rok"].toInt())));
    ui->tableWidget->setItem(i, 2, new QTableWidgetItem(r["tytul"].toString()));
    ui->tableWidget->setItem(i, 3, new QTableWidgetItem(r["rezyser"].toString()));
    ui->tableWidget->setItem(i, 4, new QTableWidgetItem(r["rodzaj"].toString()));
  }
  if (kolumna_sortowania != 0) {
    ui->tableWidget->sortByColumn(kolumna_sortowania, Qt::AscendingOrder);
  }
}
/*!
 * \brief MainWindow::on_Add_Button_clicked
 * Otwarcie nowego okna dodawanai rekordów
 */
void MainWindow::on_Add_Button_clicked() {
  okno = new dodawanie_rekordu(this);
  okno->show();
}
/*!
 * \brief MainWindow::on_Delete_Button_clicked
 * Usuwanie pierwszego zaznaczonego rekordu z tabeli
 */
void MainWindow::on_Delete_Button_clicked() {
  BazaDanych &DB = BazaDanych::Instancja();
  auto selectedItems = ui->tableWidget->selectedItems();
  if (!selectedItems.isEmpty()) {
    int row = ui->tableWidget->row(selectedItems.first());
    QTableWidgetItem *ti = ui->tableWidget->item(row, 0);
    int d = ti->data(0).toInt();

    DB.KasowanieRekordu(d);
    updateTable();
  } else {
    QMessageBox::about(this, "Błąd Usuwania", "Nie Wybrano Wiersza");
  }
}
/*!
 * \brief MainWindow::on_Sort_Button_clicked
 * Sortowanie tabeli na podstawie danych w wybranej kolumnie
 */
void MainWindow::on_Sort_Button_clicked() {
  auto selectedItems = ui->tableWidget->selectedItems();
  if (!selectedItems.isEmpty()) {
    kolumna_sortowania = ui->tableWidget->column(selectedItems.first());
    updateTable();
  } else {
    QMessageBox::about(this, "Błąd Sortowania","Nie Wybrano Kolumny Sortującej");
  }
}
/*!
 * \brief MainWindow::on_Search_Button_clicked
 * Sortowanie danych na podstawie zadanego lineEdita
 * Pierwsza pętla ukrywa wszystkie wiersze
 * Druga pętla odsłania pasujące do wyszukiwania wyniki
 */
void MainWindow::on_Search_Button_clicked() {
  QString query = ui->lineEdit_Search->text();

  QList<QTableWidgetItem *> items = ui->tableWidget->findItems(query, Qt::MatchContains);
  for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
    ui->tableWidget->setRowHidden(i, true);
  }
  for (auto item : items) {
    ui->tableWidget->setRowHidden(item->row(), false);
  }
}
/*!
 * \brief MainWindow::on_Refresh_Button_clicked
 * Pozwala na ponowne wyswietlenmie wszystkich rekordow tabeli
 */
void MainWindow::on_Refresh_Button_clicked() {
  for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
    ui->tableWidget->setRowHidden(i, false);
  }
}
/*!
 * \brief MainWindow::on_Edit_Button_clicked
 * Pozwala na edytowanie pierwszego oznaczonego rekordu i otwiera okno modyfikacji
 */
void MainWindow::on_Edit_Button_clicked() {
  auto selectedItems = ui->tableWidget->selectedItems();
  if (!selectedItems.isEmpty()) {
    int row = ui->tableWidget->row(selectedItems.first());
    QTableWidgetItem *ti = ui->tableWidget->item(row, 0);
    edit_id = ti->data(0).toInt();
  }
  okno2 = new Edit(this);
  okno2->show();
}
/*!
 * \brief MainWindow::on_pushButton_Save_clicked
 * Otwiera dialog systemowy pozwalający na zapisanie nowego pliku ".json" o wybranej nazwie
 * lub nadpisanie starej bazy danych
 */
void MainWindow::on_pushButton_Save_clicked() {
  BazaDanych &DB = BazaDanych::Instancja();
    QString plik = QFileDialog::getSaveFileName(this,"Zapisz bazę danych","","*.json");
  if (DB.ZapisDoPliku(plik)) {
    QMessageBox::about(this, "Zapis pomyślny.", "Plik zapisany.");
  } else {
    QMessageBox::about(this, "Błąd zapisu.", "Plik nie został zapisany.");
  }
}
/*!
 * \brief MainWindow::on_pushButton_Load_clicked
 * Otwiera dialog systemowy pozwalający na odczyt pliku ".json" i wczytuje go do tabeli
 */
void MainWindow::on_pushButton_Load_clicked() {
  BazaDanych &DB = BazaDanych::Instancja();
  QString plik = QFileDialog::getOpenFileName(
      this, "Wybierz plik bazy danch filmow.", "", "*.json");
  if (DB.OdczytZPliku(plik)) {
    QMessageBox::about(this, "Odczyt pomyślny.", "Plik Odczytany.");
  } else {
    QMessageBox::about(this, "Błąd odczytu.", "Plik nie został odczytany.");
  }
  updateTable();
}
