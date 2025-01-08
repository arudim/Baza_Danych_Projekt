#include "mainwindow.h"
#include "dodawanie_rekordu.h"
#include "ui_mainwindow.h"
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonValue>
#include <QString>
#include "BazaDanych.h"

MainWindow* mainWindowInstance = nullptr;
QJsonObject rekord;


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
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
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
    okno= new dodawanie_rekordu(this);
    okno->show();
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


void MainWindow::on_Search_Button_clicked()
{
    QString query= ui->lineEdit_Search->text();

    QList<QTableWidgetItem *> items = ui ->tableWidget->findItems(query,Qt::MatchContains);

    for(int i=0;i<ui->tableWidget->rowCount();i++){
        ui->tableWidget->setRowHidden(i,true);
    }

    for(auto item:items){
        ui->tableWidget->setRowHidden(item->row(),false);
    }
}

void MainWindow::on_Refresh_Button_clicked()
{
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        ui->tableWidget->setRowHidden(i,false);
    }
}


void MainWindow::on_Edit_Button_clicked()
{
    BazaDanych &DB=BazaDanych::Instancja();
    auto selectedItems = ui->tableWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = ui->tableWidget->row(selectedItems.first());
        QTableWidgetItem *ti=ui->tableWidget->item(row,0);
        edit_id=ti->data(0).toInt();
        QJsonObject r=DB.DajRekord(edit_id);
        edit_rok=r["rok"].toInt();
        edit_tytul=r["tytul"].toString();
        edit_rezyser=r["rezyser"].toString();
        edit_gatunek=r["rodzaj"].toString();
    }
    okno2 = new Edit(this);
    okno2->show();
}

