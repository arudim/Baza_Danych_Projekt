#ifndef BAZADANYCH_H
#define BAZADANYCH_H
#include <QJsonObject>
#include <QString>

class BazaDanych {
 public:
  virtual QString DodawnieRekordu(int _rok, QString _tytul, QString _rezyser,
                                  QString _gatunek) = 0;
  virtual void KasowanieRekordu(int _id) = 0;
  virtual void ResetIteratoraRekordu() = 0;
  virtual QJsonObject DajRekord(int _indexId) = 0;
  virtual QJsonObject IteratorRekordu() = 0;

  static BazaDanych &Instancja();
  virtual void EdytowanieRekordu(int _id, int _rok, QString _tytul,
                                 QString _rezyser, QString _gatunek) = 0;
  virtual bool ZapisDoPliku(const QString &fileName) = 0;
  virtual bool OdczytZPliku(const QString &fileName) = 0;
  virtual int Rozmiar() = 0;
};

#endif  // BAZADANYCH_H
