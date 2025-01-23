#ifndef BAZAJSON_H
#define BAZAJSON_H
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "BazaDanych.h"
class BazaJson : public BazaDanych {
 private:
 public:
  BazaJson();
  virtual QString DodawnieRekordu(int _rok, QString _tytul, QString _rezyser, QString _gatunek);
  virtual void KasowanieRekordu(int _id);
  virtual void ResetIteratoraRekordu();
  virtual QJsonObject DajRekord(int _indexId);
  virtual QJsonObject IteratorRekordu();

  static BazaDanych &Instancja();
  virtual void EdytowanieRekordu(int _id, int _rok, QString _tytul, QString _rezyser, QString _gatunek);
  virtual bool ZapisDoPliku(const QString &fileName);
  virtual bool OdczytZPliku(const QString &fileName);
  virtual int Rozmiar();

  int id;
  QJsonArray db;
  QString plik_db;
  int indexNext;
};
#endif  // BAZAJSON_H
