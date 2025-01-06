#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QMessageBox>
#include <QJsonArray>
#include "film.h"

namespace Ui {
class MainWindow;
}

/*!
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *ui;
    void updateTable(std::vector<Film1> &f);
    QJsonArray db;
    void header_clicked();
    static int id;
    int kolumna_sortowania=0;
private slots:
    void on_Add_Button_clicked();
    void on_Delete_Button_clicked();



    void on_pushButton_clicked();

private:

};

extern MainWindow* mainWindowInstance;

#endif // MAINWINDOW_H

