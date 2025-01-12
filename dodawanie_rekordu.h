#ifndef DODAWANIE_REKORDU_H
#define DODAWANIE_REKORDU_H
class MainWindow;
#include <QDialog>
namespace Ui {
class dodawanie_rekordu;
}

class dodawanie_rekordu : public QDialog
{
    Q_OBJECT

public:
    explicit dodawanie_rekordu(QWidget *parent = nullptr);
    ~dodawanie_rekordu();
    MainWindow *mw;

private slots:

    void on_pushButton_Dodaj_clicked();

    void on_pushButton_Porzuc_clicked();

private:
    Ui::dodawanie_rekordu *ui;
};

#endif // DODAWANIE_REKORDU_H
