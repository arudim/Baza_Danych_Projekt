#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "film.h"
#include <QJsonObject>
#include <QJsonValue>
#include <QString>

MainWindow* mainWindowInstance = nullptr;
extern std::vector<Film1> f;
int MainWindow::id=0;
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*!
 * \brief MainWindow::updateTable
 * \param f
 */
void MainWindow::updateTable(std::vector<Film1> &f) {
    /*ui->tableWidget->setRowCount(f.size());

    for (size_t i = 0; i < f.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(f[i].year)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(f[i].name)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(f[i].director)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(f[i].type)));
    }*/
    ui->tableWidget->setRowCount(db.size());
    for (int i =0; i<db.size();i++){
        QJsonValue r=db[i];
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(r.toObject()["id"].toInt())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(r.toObject()["rok"].toInt())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(r.toObject()["tytul"].toString()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(r.toObject()["rezyser"].toString()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(r.toObject()["rodzaj"].toString()));
    }
        ui->tableWidget->sortByColumn(kolumna_sortowania,Qt::AscendingOrder);
}
void MainWindow::on_Add_Button_clicked()
{
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

    addFilm(year, ui->lineEditName->text().toStdString(),
            ui->lineEditDirector->text().toStdString(),
            ui->lineEditType->text().toStdString());
    rekord["id"]= id++;
    rekord["rok"] = year;
    rekord["tytul"] = ui->lineEditName->text().toStdString().c_str();
    rekord["rezyser"] = ui->lineEditDirector->text().toStdString().c_str();
    rekord["rodzaj"] = ui->lineEditType->text().toStdString().c_str();
    db.append(rekord);
    updateTable(f);


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
    auto selectedItems = ui->tableWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = ui->tableWidget->row(selectedItems.first());
        QTableWidgetItem *ti=ui->tableWidget->item(row,0);
        auto d=ti->data(0);
        //deleteFilm(row);

        db.removeAt(row);
        updateTable(f);
    }
    else{
        QMessageBox::about(this,"Błąd Usuwania","Nie Wybrano Wiersza");
    }

}


void MainWindow::on_pushButton_clicked()
{
    auto selectedItems = ui->tableWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        kolumna_sortowania = ui->tableWidget->column(selectedItems.first());
        updateTable(f);
    }
}

