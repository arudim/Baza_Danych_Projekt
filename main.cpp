#include "mainwindow.h"

#include <QApplication>
#include "BazaDanych.h"
extern BazaAbstract *dba;
int main(int argc, char *argv[])
{
    dba=new BazaDanych();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
