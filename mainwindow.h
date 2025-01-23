#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QJsonArray>
#include <QMainWindow>
#include <QTableWidget>

#include "dodawanie_rekordu.h"
#include "edit.h"

namespace Ui {
class MainWindow;
}

/*!
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  Ui::MainWindow *ui;
  void updateTable();
  int kolumna_sortowania = 0;
  int edit_id = 0;
  dodawanie_rekordu *okno;
  Edit *okno2;

 private slots:
  void on_Add_Button_clicked();
  void on_Delete_Button_clicked();
  void on_Sort_Button_clicked();
  void on_Search_Button_clicked();
  void on_Refresh_Button_clicked();
  void on_Edit_Button_clicked();
  void on_pushButton_Save_clicked();
  void on_pushButton_Load_clicked();

 private:
};

extern MainWindow *mainWindowInstance;

#endif  // MAINWINDOW_H
