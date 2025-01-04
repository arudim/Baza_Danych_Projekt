#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "film.h"

MainWindow* mainWindowInstance = nullptr;
extern std::vector<Film1> f;

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
void MainWindow::updateTable(std::vector<Film1> &f) {
    ui->tableWidget->setRowCount(f.size());

    for (size_t i = 0; i < f.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(f[i].year)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(f[i].name)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(f[i].director)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(f[i].type)));
    }
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
    updateTable(f);

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
        updateTable(f);
    }
    else{
        QMessageBox::about(this,"Błąd Usuwania","Nie Wybrano Wiersza");
    }
}


