#include "mainwindow.h"
#include "dodawanie_rekordu.h"
#include "ui_mainwindow.h"
#include "film.h"
#include <QJsonObject>
#include <QJsonValue>
#include <QString>
#include "BazaDanych.h"

MainWindow* mainWindowInstance = nullptr;
extern std::vector<Film1> f;
int MainWindow::id=0;
QJsonObject rekord;
QJsonArray db;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainWindowInstance = this;

    ui->tableWidget->setColumnCount(5); // Set number of columns
    QStringList headers;
    headers<< "ID" << "Year" << "Name" << "Director" << "Type";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setColumnHidden(0,true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*!
 * \brief MainWindow::updateTable
 * \param f
 */
void MainWindow::updateTable() {
    QJsonObject r;
    BazaDanych &DB=BazaDanych::Instancja();
    ui->tableWidget->setRowCount(db.size());
    for (int i =0; ;i++){
        r=DB.DajRekord(i);
        if(r.isEmpty()){
            break;
        }
        ui->tableWidget->setRowCount(i+1);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(r["id"].toInt())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(r["rok"].toInt())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(r["tytul"].toString()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(r["rezyser"].toString()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(r["rodzaj"].toString()));
    }
        ui->tableWidget->sortByColumn(kolumna_sortowania,Qt::AscendingOrder);
}
void MainWindow::on_Add_Button_clicked()
{
    BazaDanych &DB=BazaDanych::Instancja();
    if (ui->lineEditYear->text().isEmpty() ||
        ui->lineEditName->text().isEmpty() ||
        ui->lineEditDirector->text().isEmpty() ||
        ui->lineEditType->text().isEmpty())
    {
        QMessageBox::warning(this, "Błąd Danych", "Wszystkie pola muszą być wypełnione.");
        return;
    }
    bool ok;
    int year = ui->lineEditYear->text().toInt(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Zła Dana", "Wprowadź 'int' dla danej Rok");
        return;
    }

    DB.DodawnieRekordu(year, ui->lineEditName->text().toStdString().c_str(),
            ui->lineEditDirector->text().toStdString().c_str(),
            ui->lineEditType->text().toStdString().c_str());

    updateTable();


    //okno= new dodawanie_rekordu(this);
    //okno->show();

    ui->lineEditYear->clear();
    ui->lineEditName->clear();
    ui->lineEditDirector->clear();
    ui->lineEditType->clear();
}
/*!
 * \brief MainWindow::on_Delete_Button_clicked
 */
void MainWindow::on_Delete_Button_clicked()
{
    BazaDanych &DB=BazaDanych::Instancja();
    auto selectedItems = ui->tableWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = ui->tableWidget->row(selectedItems.first());
        QTableWidgetItem *ti=ui->tableWidget->item(row,0);
        int d=ti->data(0).toInt();

        DB.KasowanieRekordu(d);
        updateTable();
    }
    else{
        QMessageBox::about(this,"Błąd Usuwania","Nie Wybrano Wiersza");
    }

}





void MainWindow::on_Sort_Button_clicked()
{
    auto selectedItems = ui->tableWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        kolumna_sortowania = ui->tableWidget->column(selectedItems.first());
        updateTable();
    }
}

