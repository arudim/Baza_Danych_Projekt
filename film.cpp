#include "film.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

std::vector<Film1> f;

extern MainWindow* mainWindowInstance;

void addFilm(int year, const std::string &name, const std::string &director, const std::string &type) {
    Film1 a;
    a.year = year;
    a.name = name;
    a.director = director;
    a.type = type;
    f.push_back(a);
    updateFilmTable();
}

void deleteFilm(int index) {
    if (index >= 0 && index < f.size()) {
        f.erase(f.begin() + index);
        updateFilmTable();
    }
}

void updateFilmTable() {
    mainWindowInstance->ui->tableWidget->setRowCount(f.size());

    for (size_t i = 0; i < f.size(); ++i) {
        mainWindowInstance->ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(f[i].year)));
        mainWindowInstance->ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(f[i].name)));
        mainWindowInstance->ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(f[i].director)));
        mainWindowInstance->ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(f[i].type)));
    }
}
