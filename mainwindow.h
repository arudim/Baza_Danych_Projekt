#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dodawanie_rekordu.h"
#include <QTableWidget>
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
    void updateTable();
    void header_clicked();
    static int id;
    int kolumna_sortowania=0;
    dodawanie_rekordu *okno;
private slots:
    void on_Add_Button_clicked();
    void on_Delete_Button_clicked();
    void on_Sort_Button_clicked();

private:

};

extern MainWindow* mainWindowInstance;

#endif // MAINWINDOW_H

