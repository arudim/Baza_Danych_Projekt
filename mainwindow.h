#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <QTableWidget>
#include <QMessageBox>

using std::string;
using std::vector;

struct Film1{
    int year;
    string name;
    string director;
    string type;
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Add_Button_clicked();

    void on_Delete_Button_clicked();

private:
    Ui::MainWindow *ui;
    vector<Film1> f;
    void updateTable();
};
#endif // MAINWINDOW_H
