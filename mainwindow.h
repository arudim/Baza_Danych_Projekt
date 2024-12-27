#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QMessageBox>
#include "film.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *ui;

private slots:
    void on_Add_Button_clicked();
    void on_Delete_Button_clicked();

private:
    void updateTable();
};

extern MainWindow* mainWindowInstance;

#endif // MAINWINDOW_H

