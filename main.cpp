#include "mainwindow.h"
#include "BazaJson.h"
#include "qplik.h"
#include <QApplication>
extern BazaDanych *dba;
extern Plik *pa;
int main(int argc, char *argv[]) {
  dba = new BazaJson();
  pa = new QPlik();
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
