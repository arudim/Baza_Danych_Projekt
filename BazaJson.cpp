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
 * Dodawanie rekordu do bazy danych na podstawie przekazanych parametrów do funkcji
 */
QString BazaJson::DodawnieRekordu(int _rok, QString _tytul, QString _rezyser, QString _gatunek) {
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
/*!
 * \brief BazaJson::KasowanieRekordu
 * \param _id
 * Usuwanie rekordu na podstawie przekazanego do funkcji ID
 */
void BazaJson::KasowanieRekordu(int _id) {
  for (int i = 0; i < db.size(); i++) {
    if (db[i].toObject()["id"] == _id) {
      db.removeAt(i);
      break;
    }
  }
}
/*!
 * \brief BazaJson::ResetIteratoraRekordu
 * Metoda służy do ustawiania iteratora na początek tablicy QJsonArray
 */
void BazaJson::ResetIteratoraRekordu() { indexNext = 0; }

/*!
 * \brief BazaJson::IteratorRekordu
 * \return zwraca bierząco wskazywany obiekt
 * Metoda służy do sekwencyjnego pobierania elementów z tablicy QJsonArray
 */
QJsonObject BazaJson::IteratorRekordu() { return db[indexNext++].toObject(); }

/*!
 * \brief BazaJson::DajRekord
 * \param _id
 * \return zwraca obiekt definiowany przez _id
 */
QJsonObject BazaJson::DajRekord(int _id) {
  QJsonObject ret;
  for (int i = 0; i < db.size(); i++) {
    if (db[i].toObject()["id"] == _id) {
      ret = db[i].toObject();
    } else {
      ret.empty();
    }
  }
  return ret;
}

/*!
 * \brief BazaJson::EdytowanieRekordu
 * \param _id
 * \param _rok
 * \param _tytul
 * \param _rezyser
 * \param _gatunek
 * Edytowanie rekordu na podstawie podanego ID do funkcji
 * zamiana parametrów na dane podane do funkcji
 */
void BazaJson::EdytowanieRekordu(int _id, int _rok, QString _tytul, QString _rezyser, QString _gatunek) {
  QJsonObject rekord = DajRekord(_id);
  rekord["rok"] = _rok;
  rekord["tytul"] = _tytul;
  rekord["rezyser"] = _rezyser;
  rekord["rodzaj"] = _gatunek;
  db.replace(_id, rekord);
}

/*!
 * \brief BazaJson::ZapisDoPliku
 * \param fileName
 * \return zrwaca powodzenia "true" lub "false"
 * Zapis bazy danych do pliku zwracajacy czy zapis był pomyślny czy też nie
 */
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

/*!
 * \brief BazaJson::OdczytZPliku
 * \param fileName
 * \return zrwaca powodzenia "true" lub "false"
 * Odczyt z pliku konwertujacy dokument .json do tabeli
 */
bool BazaJson::OdczytZPliku(const QString &fileName) {
  bool a = true;
    QJsonParseError blad;
  Plik &file = Plik::Instancja();
  if (!file.open(fileName, QIODevice::ReadOnly)) {
    a = false;
    return a;
  }
  QByteArray data = file.readAll();
  QJsonDocument doc(QJsonDocument::fromJson(data,&blad));
  if(blad.error==QJsonParseError::NoError){
  db = doc.array();
  ResetIteratoraRekordu();
  for (int i = 0; i < db.size(); i++) {
    auto _id = IteratorRekordu()["id"].toInt();
    if (id < _id)
      id = _id;
  }
  id++;
  }
  else{ a=false;}
  file.close();
  return a;
}



int BazaJson::Rozmiar() { return db.size(); }
