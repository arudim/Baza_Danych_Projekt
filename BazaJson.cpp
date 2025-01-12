#include "BazaJson.h"
#include "plik.h"
#include <QIODevice>
#include <QJsonObject>
#include <QMessageBox>
static BazaJson instancja_bazy;

BazaJson::BazaJson() { id = 0; }

/*!
 * \brief BazaJson::DodawnieRekordu
 * \param _rok
 * \param _tytul
 * \param _rezyser
 * \param _gatunek
 * \return
 */
QString BazaJson::DodawnieRekordu(int _rok, QString _tytul, QString _rezyser,
                                  QString _gatunek) {
  QString ret = "";
  QJsonObject rekord;

  rekord["id"] = id++;
  rekord["rok"] = _rok;
  rekord["tytul"] = _tytul;
  rekord["rezyser"] = _rezyser;
  rekord["rodzaj"] = _gatunek;
  db.append(rekord);
  return ret;
}

void BazaJson::KasowanieRekordu(int _id) {
  for (int i = 0; i < db.size(); i++) {
    if (db[i].toObject()["id"] == _id) {
      db.removeAt(i);
      break;
    }
  }
}

void BazaJson::DajRekordReset() { indexNext = 0; }

QJsonObject BazaJson::DajRekord() { return db[indexNext++].toObject(); }

QJsonObject BazaJson::DajRekord(int _id) {
  QJsonObject ret;
  /*if(_index>=db.size()){
      ret.empty();
  }
  else{
      ret=db[_index].toObject();
  }
  return ret;*/

  for (int i = 0; i < db.size(); i++) {
    if (db[i].toObject()["id"] == _id) {
      ret = db[i].toObject();
    } else {
      ret.empty();
    }
  }
  return ret;
}

void BazaJson::EdytowanieRekordu(int _id, int _rok, QString _tytul,
                                 QString _rezyser, QString _gatunek) {
  QJsonObject rekord = DajRekord(_id);
  rekord["rok"] = _rok;
  rekord["tytul"] = _tytul;
  rekord["rezyser"] = _rezyser;
  rekord["rodzaj"] = _gatunek;
  db.replace(_id, rekord);
}

bool BazaJson::ZapisDoPliku(const QString &fileName) {
  Plik &file = Plik::Instancja();
  bool a = true;
  if (!file.open(fileName, QIODevice::WriteOnly)) {
    a = false;
    return a;
  }
  QJsonDocument doc(db);
  file.write(doc.toJson());
  file.close();
  return a;
}

bool BazaJson::OdczytZPliku(const QString &fileName) {
  bool a = true;
  Plik &file = Plik::Instancja();
  if (!file.open(fileName, QIODevice::ReadOnly)) {
    a = false;
    return a;
  }
  QByteArray data = file.readAll();
  QJsonDocument doc(QJsonDocument::fromJson(data));
  db = doc.array();
  DajRekordReset();
  for (int i = 0; i < db.size(); i++) {
    auto _id = DajRekord()["id"].toInt();
    if (id < _id)
      id = _id;
  }
  id++;
  file.close();
  return a;
}

bool BazaJson::ZnajdzPlik(QString plik) { return false; }

int BazaJson::Rozmiar() { return db.size(); }
