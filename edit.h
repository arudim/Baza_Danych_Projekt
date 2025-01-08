#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
class MainWindow;
namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = nullptr);
    ~Edit();
    MainWindow *mw;

private slots:
    void on_pushButton_Porzuc_clicked();

    void on_pushButton_Zatwierdz_clicked();

private:
    Ui::Edit *ui;
};

#endif // EDIT_H
