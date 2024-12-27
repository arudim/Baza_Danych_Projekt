#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "film.h"
#include "ksiazka.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4); // Set number of columns
    QStringList headers;
    headers << "Year" << "Name" << "Director" << "Type";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_Button_clicked()
{
    // Check if any QLineEdit is empty
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

    Film1 a;
    a.year = year;
    a.name = ui->lineEditName->text().toStdString();
    a.director = ui->lineEditDirector->text().toStdString();
    a.type = ui->lineEditType->text().toStdString();
    f.push_back(a);
    updateTable();

    // Clear the QLineEdits after adding the film
    ui->lineEditYear->clear();
    ui->lineEditName->clear();
    ui->lineEditDirector->clear();
    ui->lineEditType->clear();
}

void MainWindow::on_Delete_Button_clicked()
{
    auto selectedItems = ui->tableWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = ui->tableWidget->row(selectedItems.first());

        // Remove the film from the vector
        f.erase(f.begin() + row);

        // Remove the row from the table
        ui->tableWidget->removeRow(row);
    }
    else{
        QMessageBox::about(this,"Błąd Usuwania","Nie Wybrano Wiersza");
    }
}

void MainWindow::updateTable()
{
    ui->tableWidget->setRowCount(f.size()); // Set number of rows

    for (size_t i = 0; i < f.size(); ++i)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(f[i].year)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(f[i].name)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(f[i].director)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(f[i].type)));
    }
}
