#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "film.h"

MainWindow* mainWindowInstance = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainWindowInstance = this;

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
        deleteFilm(row);
    }
    else{
        QMessageBox::about(this,"Błąd Usuwania","Nie Wybrano Wiersza");
    }
}

void MainWindow::updateTable()
{
    updateFilmTable();
}
