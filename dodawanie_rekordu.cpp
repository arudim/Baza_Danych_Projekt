#include "dodawanie_rekordu.h"
#include "ui_dodawanie_rekordu.h"

dodawanie_rekordu::dodawanie_rekordu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dodawanie_rekordu)
{
    ui->setupUi(this);
}

dodawanie_rekordu::~dodawanie_rekordu()
{
    delete ui;
}
